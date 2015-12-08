#include "TAD_Plateau.h"
#include "TAD_Coup.h"
#include "TAD_Couleur.h"
#include "ListeCoupsPossibles_Prive.h"
#include "ListeCoupsPossibles.h"
#include <math.h>

/* Partie publique  */

Coups listeCoupsPossibles(Plateau plateau, Couleur couleur){
  Coups ListeCoups;

  return ListeCoups;

}

/* Partie privee  */

int coupValide(Plateau plateau, Coup coup) {
  int pionPresent;
  Position pos,posTmp;
  Pion pionJoueur;
  unsigned int x,y;

  x = -1;
  pionPresent = 0;
  pos = CP_obtenirPositionCoup(coup);
  pionJoueur = CP_obtenirPionCoup(coup);
  while(!(pionPresent) && (x<2)) {
    y = -1;
    while(!(pionPresent) && (y<2)) {
      if(!((x==0) && (y==0))) {
	  posTmp = pos;
	  /*pionEstPresent(pionJoueur,x,y,posTmp,plateau,pionPresent);*/ //Revoir la doc pour cette procedure
	  if(pionPresent) {
		if(fabs(POS_obtenirLigne(posTmp)-POS_obtenirLigne(pos))<2 || fabs(POS_obtenirColonne(posTmp)-POS_obtenirColonne(pos))<2) {
		  pionPresent = 0;
		  }
	      }
	}
      y = y+1;
    }
    x = x+1;
  }
return pionPresent;
}
		  



void copierPlateau(Plateau plateauACopier, Plateau* plateauCopie){
  /*plateauCopie = PL_creerPlateau();
    memcpy(plateauCopie.pions,plateauACopier.pions,sizeof()*/ 
}
