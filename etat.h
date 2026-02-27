#pragma once

#include <string>
#include "symbole.h"
using namespace std;

class Automate;

class Etat {
    public:
        Etat(string name) : name(name) {}
        virtual ~Etat() = default;
        void print() const;
        virtual bool transition (Automate & automate, Symbole * s) = 0;
    protected:
        string name;
};
