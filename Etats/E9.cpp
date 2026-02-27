#include "E9.h"
#include "../automate.h"
#include <iostream>

bool E9::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS: 
    case MULT:
    case CLOSEPAR:
    case FIN: {
        //regle E -> (E)
        automate.popAndDestroySymbol(); // jeter le ')'
        Expr * s1 = (Expr*) automate.popSymbol();  // E entre les parenthèses
        automate.popAndDestroySymbol(); // jeter le '('
        automate.reduction(3, new Expr(s1->getValeur())); // reduction de (E) en E
        break;
    }
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E9 : token inattendu");
    }
    return false;
}