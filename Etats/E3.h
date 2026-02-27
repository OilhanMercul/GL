#pragma once

#include <string>
#include "../etat.h"
using namespace std;


class E3 : public Etat {
    public:
        E3() : Etat("E3") {}
        bool transition (Automate & automate, Symbole * s);
};