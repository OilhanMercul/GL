#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   string chaine("(1+34)*123");
   string chaine2("1+2*3");
   string chaine3("1");
   string chaine4("1+2");

   cout<<"Analyse de la chaine : "<<chaine4<<endl;

   Lexer l(chaine4);
   Automate automate(l);

   // Symbole * s;
   // while(*(s=l.Consulter())!=FIN) {
   //    s->Affiche();
   //    cout<<endl;
   //    l.Avancer();
   //    cout<<"-----------------"<<endl;
   // }

   int i = 0;
   while( i <= 10) { // Trouver la condition d'arrêt de la boucle
      automate.lecture();
      i++;
   }

   return 0;
}

