#include "E1.h"
#include "../automate.h"
#include "E4.h"
#include "E5.h"
#include <iostream>

bool E1::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case FIN:
        return true;
        break;
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E1 : token inattendu");
    }
    return false;
}