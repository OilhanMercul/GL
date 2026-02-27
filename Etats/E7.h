#pragma once

#include <string>
#include "../etat.h"
using namespace std;

class E7 : public Etat {
    public:
        E7() : Etat("E7") {}
        bool transition (Automate & automate, Symbole * s);
};