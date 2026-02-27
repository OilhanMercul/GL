#include "E9.h"
#include "../automate.h"
#include <iostream>

bool E9::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS: {
        automate.popAndDestroySymbol();
        Expr * s1 = (Expr*) automate.popSymbol(); 
        automate.popAndDestroySymbol();
        automate.reduction(4, new Expr(s1->getValeur()));
        break;
    }
    case MULT: {
        automate.popAndDestroySymbol();
        Expr * s1 = (Expr*) automate.popSymbol(); 
        automate.popAndDestroySymbol();
        automate.reduction(4, new Expr(s1->getValeur()));
        break;
    }
    case CLOSEPAR: {
        automate.popAndDestroySymbol();
        Expr * s1 = (Expr*) automate.popSymbol(); 
        automate.popAndDestroySymbol();
        automate.reduction(4, new Expr(s1->getValeur()));
        break;
    }
    case FIN: {
        automate.popAndDestroySymbol();
        Expr * s1 = (Expr*) automate.popSymbol(); 
        automate.popAndDestroySymbol();
        automate.reduction(4, new Expr(s1->getValeur()));
        break;
    }
    default:
        cout<<"Erreur de syntaxe"<<endl;
        break;
    }
    return false;
}