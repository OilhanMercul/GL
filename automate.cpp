#include "automate.h"
#include "Etats/E0.h"
#include <iostream>

//Constructeur de l'automate
Automate::Automate(Lexer& lexer): lexer(lexer) {
    pileEtats.push_back(new E0);
}

//Destructeur de l'automate
Automate::~Automate() {
}

//Lecture du symbole en haut de la pile et transition vers le nouvel état
bool Automate::lecture(){
    Symbole* s = lexer.Consulter();
    //pileEtats.back()->print();
    //cout<<" | ";
    //s->Affiche();
    //cout<<endl;
    return pileEtats.back()->transition(*this, s);
}

//Decalage : ajoute le symbole et l'état à la pile, puis avance le lexer
void Automate::decalage(Symbole* s, Etat* e) {
    pileSymboles.push_back(s);
    pileEtats.push_back(e);
    lexer.Avancer();
}

//Reduction : retire les éléments de la pile selon la règle de production, puis ajoute le symbole non terminal et l'état correspondant
void Automate::reduction(int n,Symbole * s) {
    for (int i=0; i<n; i++) {
        delete(pileEtats.back());
        pileEtats.pop_back();
    }
    pileEtats.back()->transition(*this, s);
}

//Transition simple : pas d'avancement du lexer car symbole non-terminal
void Automate::transitionsimple(Symbole* s, Etat* e) {
    pileSymboles.push_back(s);
    pileEtats.push_back(e);
}

//PopSymbol: recuperer et enlever le symbole en haut de la pile
Symbole* Automate::popSymbol() {
    Symbole* s = pileSymboles.back();
    pileSymboles.pop_back();
    return s;
}

//PopAndDestroySymbol: supprimer le symbole en haut de la pile sans l'exploiter (pour les signes)
void Automate::popAndDestroySymbol() {
    delete pileSymboles.back();
    pileSymboles.pop_back();
}