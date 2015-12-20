#include "TAD_Position.h"
#include "TAD_Pion.h"
#include "TAD_Couleur.h"
#include "TAD_Plateau.h"

Plateau PL_creerPlateau(){
  Plateau plateau;
  unsigned int i,j;
  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      plateau.pions[i-1][j-1]=PI_creerPion(CL_blanc());
      plateau.presencePions[i-1][j-1]=0;
    }
  }
  return plateau;
}

int PL_estCaseVide(Plateau plateau, Position position){
  unsigned int i,j;
  i=POS_obtenirLigne(position);
  j=POS_obtenirColonne(position);
  if((plateau.presencePions[i][j])==0){
    return 1;
  }
  else{
    return 0;
  }
}

void PL_viderCase(Plateau* plateau, Position position){
  unsigned int i,j;
  i=POS_obtenirLigne(position);
  j=POS_obtenirColonne(position);
  plateau->presencePions[i][j]=0;
}

void PL_poserPion(Plateau* plateau, Position position, Pion pion){
  unsigned int i,j;
  i=POS_obtenirLigne(position);
  j=POS_obtenirColonne(position);
  plateau->pions[i][j]=pion;
  plateau->presencePions[i][j]=1;
}

Pion PL_obtenirPion(Plateau plateau, Position position){
  Pion pion;
  unsigned int i,j;
  i=POS_obtenirLigne(position);
  j=POS_obtenirColonne(position);
  pion=plateau.pions[i][j];
  return pion;
}

void PL_inverserPion(Plateau* plateau, Position position){
  Pion pion;
  unsigned int i,j;
  i=POS_obtenirLigne(position);
  j=POS_obtenirColonne(position);
  pion=plateau->pions[i][j];
  PI_retournerPion(&pion);
  plateau->pions[i][j]=pion;
}
