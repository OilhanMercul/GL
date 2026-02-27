#include <iostream>
#include <string>
#include "lexer.h"
#include "automate.h"
using namespace std;

// Comptage des tests
int nb_tests  = 0;
int nb_reussi = 0;

// Lance l'automate sur une chaine et retourne le résultat
int evaluer(string chaine) {
    try {
        Lexer l(chaine);
        Automate automate(l);
        bool fini = false;
        while (!fini) fini = automate.lecture();
        return automate.pileSymboles.back()->getValeur();
    }
    catch (ErreurSyntaxe& e) {
        return -1;  // valeur spéciale pour signaler une erreur
    }
}

// Compare le résultat obtenu au résultat attendu
void tester(string chaine, int attendu) {
    nb_tests++;
    int resultat = evaluer(chaine);
    bool ok = (resultat == attendu);
    if (ok) nb_reussi++;
    cout << (ok ? "[OK]    " : "[ECHEC] ")
         << chaine << " = " << resultat
         << " (attendu: " << attendu << ")" << endl;
}

int main() {
    cout << "TESTS UNITAIRES\n" << endl;
    
    // Valeur simple
    cout << "Valeurs simples" << endl;
    tester("42", 42);

    // Addition et multiplication de base
    cout << "\nOperations simples" << endl;
    tester("1+2", 3);
    tester("2*3", 6);

    // Priorité * sur + : 1+(2*3)=7, pas (1+2)*3=9
    cout << "\nPriorité des opérateurs" << endl;
    tester("1+2*3", 7);

    // Associativité gauche : (1+2)+3 et (2*3)*4
    cout << "\nAssociativité gauche des opérateurs" << endl;
    tester("1+2+3", 6);
    tester("2*3*4", 24);

    // Parenthèses
    cout << "\nParenthèses" << endl;
    tester("(1+2)*3", 9);

    // Expression complexe
    cout << "\nExpression complexe" << endl;
    tester("(1+2)*(3+4*5)", 69);

    // Expressions fausses
    cout << "\nExpressions incorrectes (=-1)" << endl;
    tester("1+", -1);          // Incomplet
    tester("*2", -1);          // Incomplet
    tester("1++2", -1);        // Syntaxe incorrecte
    tester("1+*2", -1);        // Syntaxe incorrecte

    cout << endl << nb_reussi << "/" << nb_tests << " tests reussis" << endl;
    return nb_tests - nb_reussi;
}
