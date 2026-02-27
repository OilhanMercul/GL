#pragma once

#include <string>
#include "../etat.h"
using namespace std;


class E1 : public Etat {
    public:
        E1() : Etat("E1") {}
        bool transition (Automate & automate, Symbole * s);
};