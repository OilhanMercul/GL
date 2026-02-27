#include "E6.h"
#include "../automate.h"
#include "E4.h"
#include "E5.h"
#include "E9.h"
#include <iostream>

bool E6::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case PLUS:
        automate.decalage(s, new E4);
        break;
    case MULT:
        automate.decalage(s, new E5);
        break;
    case CLOSEPAR:
        automate.decalage(s, new E9);
        break;
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E6 : token inattendu");
    }
    return false;
}