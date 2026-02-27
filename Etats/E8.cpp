#include "E8.h"
#include "../automate.h"
#include <iostream>

bool E8::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN:
    {
        // r3 : E → E * E (3 symboles)
        Expr* s1 = (Expr*) automate.popSymbol();   // E de droite
        automate.popAndDestroySymbol();             // jette le '*'
        Expr* s2 = (Expr*) automate.popSymbol();   // E de gauche
        automate.reduction(3, new Expr(s2->getValeur() * s1->getValeur()));
        break;
    }
    default:
        cout << "Erreur de syntaxe E8" << endl;
        break;
    }
    return false;
}