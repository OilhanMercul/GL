#pragma once

#include <string>
#include "../etat.h"
using namespace std;

class E6 : public Etat {
    public:
        E6() : Etat("E6") {}
        bool transition (Automate & automate, Symbole * s);
};