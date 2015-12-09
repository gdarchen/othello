#include <stdio.h>
#include <stdlib.h>
#include "FaireUnePartie.h"

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

void afficher (Plateau plateau){
  printf("   0   1   2   3   4   5   6   7 ");
  printf("—————————————————————————————————");
  Position* position;
  for(int i=0;i<8;i++){
    printf("%d|", i);
    for (int j=0;j<8;j++){
      POS_fixerPosition(i,j,position)
      if (!estCaseVide(plateau,position)){
        
      }
    }
  }

}
