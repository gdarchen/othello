#include "ObtenirCoupIA.h"
#include "ObtenirCoupIA_Prive.h"
#include "FaireUnePartie.h"

#define INFINI 10000 /* Valeur affectée pour signifier qu'un coup est gagnant. */

/* Partie publique */

Coup obtenirCoupIA(Plateau plateau, Couleur couleur){
    Coups coupsPossibles;
    unsigned int i;
    int scoreCourant, meilleurScore;
    Coup coupCourant, meilleurCoup;
    coupsPossibles = listeCoupsPossibles(plateau,couleur);
    if (nbCoups(coupsPossibles) > 0) {
        meilleurCoup = iemeCoup(coupsPossibles,1);
        meilleurScore = scoreDUnCoup(plateau,meilleurCoup,couleur,couleur,profondeurMinMax);
        for (i=2;nbCoups(coupsPossibles);i++) {
            coupCourant = iemeCoup(coupsPossibles,i);
            scoreCourant = scoreDUnCoup(plateau,scoreCourant,couleur,couleur,profondeurMinMax);
            if (scoreCourant > meilleurScore) {
                meilleurCoup = coupCourant;
                meilleurScore = scoreCourant;
            }
        }
    }
    return meilleurCoup;
}


/* Partie privée */

unsigned int profondeur(void){

    return PROFONDEUR;
}

int scoreDUnCoup(Plateau plateau, Coup coup, Couleur couleurRef, Couleur couleurCourante, unsigned int profondeurCourante){
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

  return evaluerPlateau(plateau,couleur);
}

int evaluerPlateau(Plateau plateau, Couleur couleur){
  int evaluer1,evaluer2,evaluer3,res;
  evaluer1=evaluerNbCoupsPossiblesAdversaire(plateau,couleur);
  evaluer2=evaluerNbPionsCouleur(plateau,couleur);
  evaluer3=evaluerPositionsPionsPlateau(plateau,couleur);
  res=evaluer1+evaluer2+evaluer3; /* Il serait peut-être utile de donner un coefficient à chaque evaluation ? */

  return (res);
}

int evaluerNbCoupsPossiblesAdversaire(Plateau plateau, Couleur couleur){
  Coups coupsAdversaire;
  Couleur couleurAdversaire;
  int nbCoupsAdversaire,res;

  couleurAdversaire=CL_changerCouleur(couleur);
  coupsAdversaire=listeCoupsPossibles(plateau, couleurAdversaire);
  nbCoupsAdversaire=CPS_nbCoups(coupsAdversaire);

  res=(60-10*nbCoupsAdversaire); /* Le mieux est que l'adversaire ait 0 coups possibles. Plus il en a, moins l'évaluation est bonne. */
  return(res);
}

int evaluerNbPionsCouleur(Plateau plateau, Couleur couleur){
  unsigned int nbPionsNoirs,nbPionsBlancs;
  int res;

  nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);
  if (CL_sontEgales(couleur,CL_noir())) {
    res=nbPionsNoirs-nbPionsBlancs;
  }
  else {
    res=nbPionsBlancs-nbPionsNoirs;
  }
  return res;
}

int evaluerPositionsPionsPlateau(Plateau plateau, Couleur couleur){
  int grilleScore[8][8];
  unsigned int i,j,x,y;
  Position pos;
  int resJoueur,resAdversaire,res;

  grilleScore=initialiserGrilleScore();
  resJoueur=0;
  resAdversaire=0;
  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      POS_fixerPosition(i-1,j-1,&pos);
      if(!PL_estCaseVide(plateau,pos) && CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(pos)),couleur)) {
        resJoueur=resJoueur+grilleScore[i-1][j-1];
      }
      else if(!PL_estCaseVide(plateau,pos)) {
        resAdversaire=resAdversaire+grilleScore[i-1][j-1];
      }
    }
  }
  res=resJoueur-resAdversaire;
  return(res);
}

/* Tirée de http://emmanuel.adam.free.fr/site/IMG/pdf/jeuP.pdf */
int[8][8] initialiserGrilleScore(){
  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      if(((i=1) && (j=1)) || ((i=1) && (j=8)) || ((i=8) && (j=1)) || ((i=8) && (j=8))){
        grilleScore[i-1][j-1]=500;
      }
      else{
        if(((i=1) && (j=2)) || ((i=2) && (j=1)) || ((i=8) && (j=7)) || ((i=7) && (j=8))
          || ((i=7) && (j=1)) || ((i=8) && (j=2)) || ((i=1) && (j=7)) || ((i=2) && (j=8))){
          grilleScore[i-1][j-1]=-150;
        }
        else {
          if(((i=1) && (j=3)) || ((i=3) && (j=1)) || ((i=8) && (j=6)) || ((i=6) && (j=8))
          || ((i=6) && (j=1)) || ((i=8) && (j=3)) || ((i=1) && (j=6)) || ((i=3) && (j=8))){
          grilleScore[i-1][j-1]=30;
          }
          else {
            if(((i=1) && (j=4)) || ((i=4) && (j=1)) || ((i=8) && (j=5)) || ((i=5) && (j=8))
            || ((i=5) && (j=1)) || ((i=8) && (j=4)) || ((i=1) && (j=5)) || ((i=4) && (j=8))){
            grilleScore[i-1][j-1]=10;
            }
            else {
              if(((i=2) && (j=2)) || ((i=2) && (j=7)) || ((i=7) && (j=2)) || ((i=7) && (j=7))){
                grilleScore[i-1][j-1]=-250;
              }
              else {
                if(((i=3) && (j=3)) || ((i=3) && (j=6)) || ((i=6) && (j=3)) || ((i=6) && (j=6))){
                  grilleScore[i-1][j-1]=1;
                }
                else {
                  if(((i=4) && (j=4)) || ((i=4) && (j=5)) || ((i=5) && (j=4)) || ((i=5) && (j=5))){
                    grilleScore[i-1][j-1]=16;
                  }
                  else {
                    if(((i=4) && (j=3)) || ((i=5) && (j=3)) || ((i=3) && (j=4)) || ((i=3) && (j=5))
                    || ((i=6) && (j=4)) || ((i=6) && (j=5)) || ((i=4) && (j=6)) || ((i=5) && (j=6))){
                      grilleScore[i-1][j-1]=2;
                    }
                    else {
                      grilleScore[i-1][j-1]=0;
                    } /*FinSi*/
                  } /*FinSi*/
                } /*FinSi*/
              } /*FinSi*/
            } /*FinSi*/
          } /*FinSi*/
        } /*FinSi*/
      } /*FinSi*/
    } /*FinPour*/
  } /*FinPour*/
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
