#include <stdio.h>
#include <stdlib.h>
#include "FaireUnePartie.h"
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "TAD_Plateau.h"
#include "TAD_Position.h"

void afficherAide(){
  printf("Aide du programme othello \n"
  "Les options possibles sont : \n"
    "othello standard blanc|noir [profondeur>2] \n"
      "permet de jouer contre l’ordinateur en lui donnant les blancs ou les noirs\n"
      "par defaut la profondeur d’analyse est egale a 5 \n \n"
    "othello tournoi blanc|noir [profondeur>2] \n"
      "permet de faire jouer le programme dans un mode ’tournoi’ en lui donnant les\n"
      "blancs ou les noirs\n"
      "par defaut la profondeur d’analyse est egale a 5");
}

void afficher (Plateau plateau){
  int i,j;
  Couleur couleurBlanc, couleurNoir;
  couleurBlanc=CL_blanc();
  couleurNoir=CL_noir();
  printf("   0   1   2   3   4   5   6   7 ");
  printf(" ————————————————————————————————");
  Position position;
  for(i=0;i<8;i++){
    printf("%d|", i);
    for (j=0;j<8;j++){
      POS_fixerPosition(i,j,&position);
      if (!PL_estCaseVide(plateau,position)){
        if (CL_sontEgales((PI_obtenirCouleur(PL_obtenirPion(plateau,position))),couleurBlanc))
          printf(" B ");
        else 
          printf(" N |");
      }
      else
        printf("   |");
    }
  }
}

int main(int argc, char const *argv[]){
  Plateau plateau=PL_creerPlateau();
  afficher(plateau);
  return 0;
}