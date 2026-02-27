#include "symbole.h"
#include <iostream>

//Affichage du symbole
void Symbole::Affiche() {
   cout<<Etiquettes[ident];
}

//Affichage de l'entier avec sa valeur
void Entier::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

//Affichage de l'expression avec sa valeur
void Expr::Affiche() {
   Symbole::Affiche();
   cout<<"("<<valeur<<")";
}

