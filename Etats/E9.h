#pragma once

#include <string>
#include "../etat.h"
using namespace std;

class E9 : public Etat {
    public:
        E9() : Etat("E9") {}
        bool transition (Automate & automate, Symbole * s);
};