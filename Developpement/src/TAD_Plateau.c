#include "TAD_Position.h"
#include "TAD_Pion.h"
#include "TAD_Couleur.h"
#include "TAD_Plateau.h"

Plateau PL_creerPlateau(){
  Plateau plateau;
  unsigned int i,j;
  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      plateau.pions[i][j]=PI_creerPion(CL_blanc());
      plateau.presencePions[i][j]=0;
    }
  }
}

Couleur PL_estCaseVide(Plateau plateau, Position position){

}

void PL_viderCase(Plateau* plateau, Position position){

}

void PL_poserPion(Plateau* plateau, Position position, Pion pion){

}

Pion PL_obtenirPion(Plateau plateau, Position position){

}

void PL_inverserPion(Plateau* plateau, Position position){

}
