#include "ObtenirCoupIA.h"
#include "ObtenirCoupIA_Prive.h"

#define INFINI 100 /* Valeur affectée pour signifier qu'un coup est gagnant. */

/* Partie publique */

Coup obtenirCoupIA(Plateau plateau, Couleur couleur){
    Coup coupBidon;
    return coupBidon;
}


/* Partie privée */

unsigned int profondeur(void){

    return PROFONDEUR;
}

int scoreDUnCoup(Plateau plateau,Coup coup, Couleur couleurRef, Couleur couleurCourante, unsigned int profondeurCourante){
	Plateau plateauTest;
	plateauTest = copierPlateau(plateau);
	jouerCoup(coup, plateauTest);
	if (plateauRempli(plateauTest) || profondeurCourante==0)
		return score(plateauTest, couleurRef);
	else
		return minMax(plateauTest, couleurRef, changerCouleur(couleurCourante), profondeurCourante-1);

}

int minMax(Plateau plateau, Couleur couleurRef, Couleur couleurCourante, unsigned int profondeurCourante){
	Coups coupsPossibles;
	int resultat, score;
	unsigned int i;

	coupsPossibles = listeCoupsPossibles(plateau, couleurCourante);
	if (nbCoups(coupsPossibles) > 0){
		resultat = scoreDUnCoup(plateau, iemeCoup(coupsPossibles, 1), couleurRef, couleurCourante, profondeurCourante);
		for (i=2 ; i<nbCoups(coupsPossibles)){ // nbCoups(coupsPossibles) + 1 ???
			score = scoreDUnCoup(plateau, iemeCoup(coupsPossibles, i), couleurRef, couleurCourante, profondeurCourante);
			if (couleurCourante == couleurRef){
				resultat = max(resultat, score);
			}
			else{
				resultat = min(resultat, score);
			}
		}
	}
	else{
		if (couleurCourante == couleurRef){
			resultat = INFINI;
		}
		else{
			resultat = -1*INFINI;
		}
	}
}

int score(Plateau plateau, Couleur couleur){

    return 0;
}

int evaluerPlateau(Plateau plateau, Couleur couleur){

    return 0;
}

int min(int a, int b){
	if (a<b){
		return a;
	}
	else{
		return b;
	}
}

int max(int a, int b){
	if (a>b){
		return a;
	}
	else{
		return b;
	}
}
