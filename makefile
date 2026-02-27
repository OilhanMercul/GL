# Variables
CC = g++
CFLAGS = -Wall -g
SOURCES = main.cpp lexer.cpp symbole.cpp automate.cpp etat.cpp Etats/E0.cpp Etats/E1.cpp Etats/E2.cpp Etats/E3.cpp Etats/E4.cpp Etats/E5.cpp Etats/E6.cpp Etats/E7.cpp Etats/E8.cpp Etats/E9.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = analyser

# Règle par défaut
all: $(TARGET)

# Lien de l'exécutable
# $@ -> $(TARGET)
# $^ -> $(OBJECTS)
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# Compilation des fichiers .cpp en .o
# $< -> Premier element des pr
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Déclaration des cibles phony
.PHONY: all clean fclean re

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJECTS)

# Nettoyage complet (fichiers objets et exécutable)
fclean: clean
	rm -f $(TARGET)

# Refaire la compilation
re: fclean all