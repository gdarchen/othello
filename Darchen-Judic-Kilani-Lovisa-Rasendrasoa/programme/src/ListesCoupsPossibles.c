#include "TAD_Plateau.h"
#include "TAD_Coup.h"
#include "TAD_Couleur.h"
#include "ListeCoupsPossibles_Prive.h"
#include "ListeCoupsPossibles.h"
#include "FaireUnePartie.h"
#include "FaireUnePartie_Prive.h"
#include <math.h>
#include <string.h>
#include <stdio.h>

/* Partie publique  */

Coups listeCoupsPossibles(Plateau plateau, Couleur couleur){
  Coups coupsPossibles;
  Position positionTest;
  Coup coupTest;
  Pion pionJoueur;
  unsigned int i,j;
  int nbPionsBlancs,nbPionsNoirs,nbPionsAParcourir;
  int k = 0;
  CPS_creerCoups(&coupsPossibles);
  pionJoueur = PI_creerPion(couleur);
  nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);
  nbPionsAParcourir = 64-(nbPionsBlancs+nbPionsBlancs);
  for (i = 0; i < 8; i++){
    for (j = 0; j < 8; j++){
      if (k < nbPionsAParcourir){
       POS_fixerPosition(i,j,&positionTest);
       if(PL_estCaseVide(plateau,positionTest)) {
          coupTest = CP_creerCoup(positionTest,pionJoueur);
          if (coupValide(plateau,coupTest)){
            CPS_ajouterCoups(&coupsPossibles,coupTest);
            k=k+1;
          }
       }
      }
    }
  }
  return coupsPossibles;
}

/* Partie privee  */

int coupValide(Plateau plateau, Coup coup) {
  int pionPresent;
  Position pos,posTmp;
  Pion pionJoueur;
  pionPresent = 0;
  pos = CP_obtenirPositionCoup(coup);
  pionJoueur = CP_obtenirPionCoup(coup);
  Direction dir = GAUCHE;
  while(!(pionPresent) && (dir <= DIAGDB)) {
    posTmp = pos;
    if(DIR_deplacementValide(posTmp,dir) && PL_estCaseVide(plateau, pos)){
      pionEstPresent(pionJoueur,dir,&posTmp,&plateau,&pionPresent);
    }
    dir++;
  }
  return pionPresent;
}




void copierPlateau(Plateau plateauACopier, Plateau* plateauCopie){
  *plateauCopie=PL_creerPlateau();
  memcpy(&(plateauCopie->pions),&(plateauACopier.pions),sizeof(Pion)*8*8);
  memcpy(&(plateauCopie->presencePions),&(plateauACopier.presencePions),sizeof(int)*8*8);
}
