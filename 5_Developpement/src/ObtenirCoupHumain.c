#include "TAD_Couleur.h"
#include "TAD_Coup.h"
#include "TAD_Plateau.h"
#include <stdio.h>

Coup obtenirCoupHumain(Plateau plateau, Couleur couleur){
  int i=-1,j=-1;
  Coup coup;
  Position position;
  Pion pion;
  if(CL_sontEgales(couleur,CL_blanc())){
    printf("Joueur blanc, ");
  }
  else {
    printf("Joueur noir, ");
  }
    while((i!=0) && (i!=1) && (i!=2) && (i!=3) && (i!=4) && (i!=5) && (i!=6) && (i!=7)){
      printf("veuillez saisir un numéro de ligne (de 0 à 7) : \n");
      scanf("%d",&i);
    }
    while((j!=0) && (j!=1) && (j!=2) && (j!=3) && (j!=4) && (j!=5) && (j!=6) && (j!=7)){
      printf("veuillez saisir un numéro de colonne (de 0 à 7) : \n");
      scanf("%d",&j);
    }
  POS_fixerPosition(i,j,&position);
  pion=PI_creerPion(couleur);
  coup=CP_creerCoup(position,pion);

  return(coup);
}
