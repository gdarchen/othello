#include "TAD_Couleur.h"
#include "TAD_Coup.h"
#include "TAD_Plateau.h"
#include "ListeCoupsPossibles.h"
#include <stdio.h>

Coup obtenirCoupHumain(Plateau plateau, Couleur couleur){
  unsigned int i=8,j=8;
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
    while(i > 7){
      printf("Veuillez saisir un numéro de ligne (de 0 à 7) : \n");
      scanf("%u",&i);
    }
    while(j > 7){
      printf("Veuillez saisir un numéro de colonne (de 0 à 7) : \n");
      scanf("%u",&j);
    }

  POS_fixerPosition(i,j,&position);
  pion=PI_creerPion(couleur);
  coup=CP_creerCoup(position,pion);
  estValide=coupValide(plateau,coup);
  i=8;
  j=8;
  if(!estValide){
    printf("Coup non valide, recommencez \n");
  }
  }





  return(coup);
}
