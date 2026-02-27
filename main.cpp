#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "Etats/E0.h"
using namespace std;

int main(void) {
    string chaine;

    // Demande une expression à l'utilisateur
    cout << "Entrez une expression : ";
    cin >> chaine;

    cout << "Analyse de : " << chaine << endl;

    try {
        Lexer l(chaine);
        Automate automate(l);
        bool fini = false;
        while (!fini) fini = automate.lecture();
        cout << "Résultat = " << automate.pileSymboles.back()->getValeur() << endl;
    }
    catch (ErreurSyntaxe& e) {
        cerr << "Erreur de syntaxe dans l'expression !" << endl;
        return 1;
    }

    return 0;
}