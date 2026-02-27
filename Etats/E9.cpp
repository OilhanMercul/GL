#include "E9.h"
#include "../automate.h"
#include <iostream>

bool E9::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS: 
    case MULT:
    case CLOSEPAR:
    case FIN: {
        automate.popAndDestroySymbol();
        Expr * s1 = (Expr*) automate.popSymbol(); 
        automate.popAndDestroySymbol();
        automate.reduction(3, new Expr(s1->getValeur()));
        break;
    }
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E9 : token inattendu");
    }
    return false;
}