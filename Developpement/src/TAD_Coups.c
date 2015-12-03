#include "TAD_Coups.h"
#include <assert.h>

/* Partie publique */

void CPS_creerCoups(Coups* coups){
	coups->nbCps = 0;
}

void CPS_ajouterCoups(Coups* coups, Coup coup){
	coups->tabCoups[coups->nbCps+1] = coup;
	coups->nbCps = (coups->nbCps)+1;
}

unsigned int CPS_nbCoups(Coups coups){
	return coups.nbCps;
}

Coup CPS_iemeCoup(Coups coups, unsigned int i){
	assert(i>=0 && i<coups.nbCps); /* //////////A CONFIRMER //////////////*/ 
	return coups.tabCoups[i];
}

