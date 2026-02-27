#pragma once

#include <string>
#include "../etat.h"
using namespace std;

class E8 : public Etat {
    public:
        E8() : Etat("E8") {}
        bool transition (Automate & automate, Symbole * s);
};