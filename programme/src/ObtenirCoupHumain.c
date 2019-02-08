#include "TAD_Couleur.h"
#include "TAD_Coup.h"
#include "TAD_Plateau.h"
#include "ListeCoupsPossibles.h"
#include <stdio.h>

Coup obtenirCoupHumain(Plateau plateau, Couleur couleur){
  unsigned int i=9,j=9;
  int estValide = 0;
  Coup coup;
  Position position;
  Pion pion;
  if(CL_sontEgales(couleur,CL_blanc())){
    printf("Joueur ○ : \n");
  }
  else {
    printf("Joueur ● : \n");
  }
  while(estValide==0) {
    while((i > 8) || (i < 1)){
      printf("Veuillez saisir un numéro de ligne (de 1 à 8) : \n");
      scanf("%u",&i);
    }
    while((j > 8) || (i < 1)){
      printf("Veuillez saisir un numéro de colonne (de 1 à 8) : \n");
      scanf("%u",&j);
    }

    i=i-1;
    j=j-1;
    POS_fixerPosition(i,j,&position);
    pion=PI_creerPion(couleur);
    coup=CP_creerCoup(position,pion);
    estValide=coupValide(plateau,coup);
    i=9;
    j=9;
    if(!estValide){
      printf("Coup non valide, recommencez \n");
    }
  }
  return coup;
}
