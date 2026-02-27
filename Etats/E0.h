#pragma once

#include <string>
#include "../etat.h"
using namespace std;


class E0 : public Etat {
    public:
        E0() : Etat("E0") {}
        bool transition (Automate & automate, Symbole * s);
};