#pragma once

#include <string>
#include "symbole.h"
#include <stdexcept>
using namespace std;

//Declaration de la classe Automate pour éviter les dépendances circulaires
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

// Classe d'exception pour les erreurs de syntaxe
class ErreurSyntaxe : public runtime_error {
public:
    ErreurSyntaxe(string msg) : runtime_error(msg) {}
};
