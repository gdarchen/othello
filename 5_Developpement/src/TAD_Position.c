#include "TAD_Position.h"
#include <assert.h>

/* Partie publique */

unsigned int POS_obtenirLigne(Position position){
  return(position.ligne);
}


unsigned int POS_obtenirColonne(Position position){
  return(position.colonne);
}

void POS_fixerPosition(unsigned int ligne, unsigned int colonne, Position* position){
  assert((ligne>=0) && (ligne<8) && (colonne>=0) && (colonne<8));
  position->ligne=ligne;
  position->colonne=colonne;
}

int POS_sontEgales(Position pos1, Position pos2){
  return(((pos1.ligne) == (pos2.ligne)) && ((pos1.colonne) == (pos2.colonne)));
}
