#include "E4.h"
#include "../automate.h"
#include "E3.h"
#include "E2.h"
#include "E7.h"
#include <iostream>

bool E4::transition(Automate & automate, Symbole * s) {

    switch (*s) {
    case INT:
        automate.decalage(s, new E3);
        break;
    case OPENPAR:
        automate.decalage(s, new E2);
        break;
    case EXPR:
        automate.transitionsimple(s, new E7);
        break;
    default:
        throw ErreurSyntaxe("Erreur de syntaxe dans E4 : token inattendu");
    }
    return false;
}