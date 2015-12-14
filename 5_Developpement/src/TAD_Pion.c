#include "TAD_Couleur.h"
#include "TAD_Pion.h"

/* Partie publique */

Pion PI_creerPion(Couleur couleur){
  Pion pion=couleur;
  return(pion);
}

Couleur PI_obtenirCouleur(Pion pion){
  Couleur couleur;
  couleur=pion;
  return(couleur);
}

void PI_retournerPion(Pion* pion){
  Couleur couleur;
  couleur=PI_obtenirCouleur(*pion);
  CL_changerCouleur(couleur);
  *pion=PI_creerPion(couleur);
}

int PI_sontEgaux(Pion pion1, Pion pion2){
  return(pion1 == pion2);
}
