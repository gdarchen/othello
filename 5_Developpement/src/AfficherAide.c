#include <stdio.h>

void afficherAide(){
  printf("
Aide du programme othello
Les options possibles sont :
  othello standard blanc|noir [profondeur>2]
    permet de jouer contre l’ordinateur en lui donnant les blancs ou les noirs
    par defaut la profondeur d’analyse est egale a 5

  othello tournoi blanc|noir [profondeur>2]
    permet de faire jouer le programme dans un mode ’tournoi’ en lui donnant les
    blancs ou les noirs
    par defaut la profondeur d’analyse est egale a 5");
}
