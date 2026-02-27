#pragma once

#include <vector>
#include "lexer.h"
#include "etat.h"
#include "symbole.h"
using namespace std;

class Automate {
public:

    //Constructeur
    Automate(Lexer& lexer);

    //Destructeur
    ~Automate();

    //Fonctions*
    void decalage(Symbole * s, Etat * e);
    void reduction(int n, Symbole * s);
    void transitionsimple(Symbole * s, Etat * e);
    void popAndDestroySymbol();
    Symbole* popSymbol();
    void lecture();

    //Attributs
    Lexer& lexer;
    vector<Etat*> pileEtats;
    vector<Symbole*> pileSymboles;
    
    
};