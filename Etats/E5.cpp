#include "E5.h"
#include "../automate.h"
#include "E3.h"
#include "E2.h"
#include "E8.h"
#include <iostream>

bool E5::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.transitionsimple(s, new E8);
        break;
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E5 : token inattendu");
    }
    return false;
}