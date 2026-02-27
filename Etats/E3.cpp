#include "E1.h"
#include "../automate.h"
#include "E3.h"
#include "E2.h"
#include "E6.h"
#include <iostream>

bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s) {
    case PLUS:
        automate.popAndDestroySymbol();
        automate.reduction(5, new Expr(s->getValeur()));
        break;
    case MULT:
        automate.popAndDestroySymbol();
        automate.reduction(5, new Expr(s->getValeur()));
        break;
    case CLOSEPAR:
        automate.popAndDestroySymbol();
        automate.reduction(5, new Expr(s->getValeur()));
        break;
    case FIN:
        automate.popAndDestroySymbol();;  
        automate.reduction(5, new Expr(s->getValeur()));
        break;
    default:
        cout<<"Erreur de syntaxe"<<endl;
        break;
    }
    return false;
}