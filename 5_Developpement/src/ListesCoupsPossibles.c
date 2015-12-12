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
  Coups ListeCoups;

  return ListeCoups;

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
