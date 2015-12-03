#include "TAD_Position.h"

/* Partie publique */

unsigned int POS_obtenirLigne(Position position){
  unsigned int ligne=position.ligne;
  return(ligne);
}


unsigned int POS_obtenirColonne(Position position){
  unsigned int colonne=position.colonne;
  return(colonne);
}

void POS_fixerPosition(unsigned int ligne, unsigned int colonne, Position* position){
  position->ligne=ligne;
  position->colonne=colonne;
}

int POS_sontEgales(Position pos1, Position pos2){
  return(((pos1.ligne) == (pos2.ligne)) && ((pos1.colonne) == (pos2.colonne)));
}
