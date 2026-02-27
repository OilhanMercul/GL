#include "E7.h"
#include "../automate.h"
#include "E5.h"
#include <iostream>

bool E7::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS:
    case CLOSEPAR:
    case FIN:
    {
        //regle E -> E + E
        Expr* s1 = (Expr*) automate.popSymbol();
        automate.popAndDestroySymbol();   // jette le '+'
        Expr* s2 = (Expr*) automate.popSymbol();
        automate.reduction(3, new Expr(s2->getValeur() + s1->getValeur()));
        break;
    }
    case MULT:{
        automate.decalage(s, new E5);
        break;
    }
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E7 : token inattendu");
    }
    return false;
}