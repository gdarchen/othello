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
    "\t othello standard blanc|noir [profondeur>2] \n"
      "\t\t permet de jouer contre l’ordinateur en lui donnant les blancs \n"
      "\t\t ou les noirs \n" 
      "\t\t par defaut la profondeur d’analyse est egale a 5 \n \n"
    "\t othello tournoi blanc|noir [profondeur>2] \n"
      "\t\t permet de faire jouer le programme dans un mode ’tournoi’ en \n"
      "\t\t lui donnant les blancs ou les noirs\n"
      "\t\t par defaut la profondeur d’analyse est egale a 5\n\n");
}

void afficher (Plateau plateau){
  int i,j;
  Couleur couleurBlanc, couleurNoir;
  couleurBlanc=CL_blanc();
  couleurNoir=CL_noir();
  printf("    0   1   2   3   4   5   6   7 \n");
  printf("   ———————————————————————————————\n");
  Position position;
  for(i=0;i<8;i++){
    printf("%d |", i);
    for (j=0;j<8;j++){
      POS_fixerPosition(i,j,&position);
      if (!PL_estCaseVide(plateau,position)){
        if (CL_sontEgales((PI_obtenirCouleur(PL_obtenirPion(plateau,position))),couleurBlanc)){
          printf("\033[35m" ); // Remplacer 35 par 37 pour du blanc
          printf(" ● ");
          printf("\033[0m" );
          printf("|");
        }
        else
        {
          if (CL_sontEgales((PI_obtenirCouleur(PL_obtenirPion(plateau,position))),couleurNoir))
            printf(" ● |");
        }
      }
      else
      {
        printf("   |");
      }
    }
	  printf("\n   ———————————————————————————————\n");
  }
}

/* Procedure à supprimer (sert à tester l'affichage)

int main(int argc, char const *argv[]){
  Plateau plateau=PL_creerPlateau();
  Pion pBlanc=PI_creerPion(CL_blanc()), pNoir=PI_creerPion(CL_noir());
  Position pos1,pos2,pos3,pos4;
  POS_fixerPosition(3,4,&pos1);
  POS_fixerPosition(4,3,&pos2);
  POS_fixerPosition(3,3,&pos3);
  POS_fixerPosition(4,4,&pos4);
  PL_poserPion(&plateau,pos1,pBlanc);
  PL_poserPion(&plateau,pos2,pBlanc);
  PL_poserPion(&plateau,pos3,pNoir);
  PL_poserPion(&plateau,pos4,pNoir);
  afficher(plateau);
  afficherAide();
  return 0;
}

// Lignes de code pour executer et tester ce fichier :
// gcc -o src/Affichage.o -c src/Affichage.c -Iinclude -Wall -pedantic -std=c99
// gcc -o src/TESTTTT src/Affichage.o src/TAD_Couleur.o src/TAD_Pion.o src/TAD_Plateau.o src/TAD_Position.o
// ./src/TESTTTT 

*/

