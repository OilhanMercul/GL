#pragma once

#include <string>
#include "../etat.h"
using namespace std;

class E4 : public Etat {
    public:
        E4() : Etat("E4") {}
        bool transition (Automate & automate, Symbole * s);
};