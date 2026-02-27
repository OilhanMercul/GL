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
        //regle E -> E * E
        Expr* s1 = (Expr*) automate.popSymbol();   // E de droite
        automate.popAndDestroySymbol();             // jeter le '*'
        Expr* s2 = (Expr*) automate.popSymbol();   // E de gauche
        automate.reduction(3, new Expr(s2->getValeur() * s1->getValeur())); // reduction de E*E en E
        break;
    }
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E8 : token inattendu");
    }
    return false;
}