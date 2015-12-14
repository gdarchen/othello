#include "TAD_Couleur.h"
#include "TAD_Pion.h"

/* Partie publique */

Pion PI_creerPion(Couleur couleurPion){
  Pion pion;
  pion.couleur=couleurPion;
  return(pion);
}

Couleur PI_obtenirCouleur(Pion pion){
  return(pion.couleur);
}

void PI_retournerPion(Pion* pion){
  Couleur couleurAChanger;
  couleurAChanger=PI_obtenirCouleur(*pion);
  CL_changerCouleur(couleurAChanger);
  pion->couleur=couleurAChanger;
}

int PI_sontEgaux(Pion pion1, Pion pion2){
  return(CL_sontEgales(pion1.couleur,pion2.couleur));
}
