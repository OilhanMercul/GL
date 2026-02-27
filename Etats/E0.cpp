#include "E0.h"
#include "../automate.h"
#include "E3.h"
#include "E2.h"
#include "E1.h"
#include <iostream>

bool E0::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.transitionsimple(s, new E1);
        break;
    default:
        cout<<"Erreur de syntaxe"<<endl;
        break;
    }
    return false;
}