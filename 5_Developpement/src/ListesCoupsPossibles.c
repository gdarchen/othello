#include "TAD_Plateau.h"
#include "TAD_Coup.h"
#include "TAD_Couleur.h"
#include "ListeCoupsPossibles_Prive.h"
#include "ListeCoupsPossibles.h"
#include "FaireUnePartie.h"
#include "FaireUnePartie_Prive.h"
#include <math.h>
#include <string.h>

/* Partie publique  */

Coups listeCoupsPossibles(Plateau plateau, Couleur couleur){
    Coups coupsPossibles;
    Position positionTest;
    Coup coupTest;
    Pion pionJoueur;
    unsigned int nbPionsBlancs,nbPionsNoirs,nbPionsAParcourir,k,i,j;

    CPS_creerCoups(&coupsPossibles);
    pionJoueur = PI_creerPion(couleur);
    nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);
    nbPionsAParcourir = 64-(nbPionsBlancs+nbPionsBlancs);
    i = 0;
    j = 0;
    k = 0;
    while ((i < 7) && (j < 7) && (k < nbPionsAParcourir)){
        POS_fixerPosition(i,j,&positionTest);
        coupTest = CP_creerCoup(positionTest,pionJoueur);
        if (PL_estCaseVide(plateau,positionTest) && coupValide(plateau,coupTest)){
            CPS_ajouterCoups(&coupsPossibles,coupTest);
        }
        k = k+1;
        i = i+1;
        j = j+1;
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
        pionEstPresent(pionJoueur,dir,&posTmp,&plateau,&pionPresent);
        dir++;
    }
    return pionPresent;
}




void copierPlateau(Plateau plateauACopier, Plateau* plateauCopie){
    *plateauCopie = PL_creerPlateau();
    memcpy(plateauCopie,&plateauACopier, sizeof(plateauACopier));
}
