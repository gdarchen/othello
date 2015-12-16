#include "TAD_Couleur.h"
#include "TAD_Coup.h"
#include "TAD_Plateau.h"
#include <stdio.h>

Coup obtenirCoupHumain(Plateau plateau, Couleur couleur){
  unsigned int i=8,j=8;
  Coup coup;
  Position position;
  Pion pion;
  if(CL_sontEgales(couleur,CL_blanc())){
    printf("Joueur blanc, ");
  }
  else {
    printf("Joueur noir, ");
  }
    while(i > 7){
      printf("veuillez saisir un numéro de ligne (de 0 à 7) : \n");
      scanf("%d",&i);
    }
    while(j > 7){
      printf("veuillez saisir un numéro de colonne (de 0 à 7) : \n");
      scanf("%d",&j);
    }
  POS_fixerPosition(i,j,&position);
  pion=PI_creerPion(couleur);
  coup=CP_creerCoup(position,pion);

  return(coup);
}
