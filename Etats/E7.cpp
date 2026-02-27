#include "E7.h"
#include "../automate.h"
#include "E5.h"
#include <iostream>

bool E7::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS:{
        Expr * s1 = (Expr*) automate.popSymbol(); //recup la derniere expression
        automate.popAndDestroySymbol(); //supprime le symbole PLUS
        Expr * s2 = (Expr*) automate.popSymbol(); //recup la deuxieme derniere expression
        automate.reduction(3, new Expr(s2->getValeur() + s1->getValeur())); //reduction de 3 symboles en une expression
        break;
    }
    case MULT:{
        automate.decalage(s, new E5);
        break;
    }
    case CLOSEPAR:{
        Expr * s1 = (Expr*) automate.popSymbol(); //recup la derniere expression
        automate.popAndDestroySymbol(); //supprime le symbole CLOSEPAR
        Expr * s2 = (Expr*) automate.popSymbol(); //recup la deuxieme derniere expression
        automate.reduction(3, new Expr(s2->getValeur() + s1->getValeur())); //reduction de 3 symboles en une expression
        break;
    }
    case FIN:{
        Expr * s1 = (Expr*) automate.popSymbol(); //recup la derniere expression
        automate.popAndDestroySymbol(); //supprime le symbole FIN
        Expr * s2 = (Expr*) automate.popSymbol(); //recup la deuxieme derniere expression
        automate.reduction(3, new Expr(s2->getValeur() + s1->getValeur())); //reduction de 3 symboles en une expression
        break;
    }
    default:
        cout<<"Erreur de syntaxe"<<endl;
        break;
    }
    return false;
}