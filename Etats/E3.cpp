#include "E1.h"
#include "../automate.h"
#include "E3.h"
#include "E2.h"
#include "E6.h"
#include <iostream>

bool E3::transition(Automate & automate, Symbole * s) {
    switch (*s) {
    case PLUS:
    case MULT:
    case CLOSEPAR:
    case FIN: { 
        //regle E -> val
        Entier* s1 = (Entier*) automate.popSymbol(); //recup l'entier
        automate.reduction(1, new Expr(s1->getValeur())); //reduction de l'entier en expression
        break;
    }
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E3 : token inattendu");
    }
    return false;
}