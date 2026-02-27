#pragma once

#include <string>
#include "../etat.h"
using namespace std;


class E2 : public Etat {
    public:
        E2() : Etat("E2") {}
        bool transition (Automate & automate, Symbole * s);
};