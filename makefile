# Variables
CC = g++
CFLAGS = -Wall -g
SOURCES = main.cpp lexer.cpp symbole.cpp automate.cpp etat.cpp Etats/E0.cpp Etats/E1.cpp Etats/E2.cpp Etats/E3.cpp Etats/E4.cpp Etats/E5.cpp Etats/E6.cpp Etats/E7.cpp Etats/E8.cpp Etats/E9.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = analyser

# Fichiers sources/objets pour les tests (remplace main.cpp par tests.cpp)
TEST_SOURCES = $(subst main.cpp,tests.cpp,$(SOURCES))
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)
TEST_TARGET = test_analyser

# Règle par défaut
all: $(TARGET)

# Lien de l'exécutable principal
# $@ -> $(TARGET)
# $^ -> $(OBJECTS)
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

# Lien de l'exécutable de test
$(TEST_TARGET): $(TEST_OBJECTS)
	$(CC) -o $@ $^

# Compilation des fichiers .cpp en .o
# $< -> Premier element des dependances
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Déclaration des cibles phony
.PHONY: all clean fclean re test

# Lancer les tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Nettoyage des fichiers objets
clean:
	rm -f $(OBJECTS) $(TEST_OBJECTS)

# Nettoyage complet (fichiers objets et exécutables)
fclean: clean
	rm -f $(TARGET) $(TEST_TARGET)

# Refaire la compilation
re: fclean all
