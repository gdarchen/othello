#include "TAD_Couleur.h"
#include "TAD_Coup.h"
#include "TAD_Plateau.h"
#include <stdio.h>

Coup obtenirCoupHumain(Plateau plateau, Couleur couleur){
  int x,y;
  Coup coup;
  Position position;
  Pion pion;
  printf("Veuillez saisir un numéro de ligne (de 0 à 7) :");
  scanf("%d",&x);
  printf("Veuillez saisir un numéro de colonne (de 0 à 7) :");
  scanf("%d",&y);
  POS_fixerPosition(x,y,&position);
  pion=PI_creerPion(couleur);
  coup=CP_creerCoup(position,pion);

  return(coup);
}
