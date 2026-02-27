#pragma once

#include <string>
#include "../etat.h"
using namespace std;


class E5 : public Etat {
    public:
        E5() : Etat("E5") {}
        bool transition (Automate & automate, Symbole * s);
};