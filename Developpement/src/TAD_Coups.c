#include "TAD_Coups.h"
#include <assert.h>

/* Partie publique */

Coups CPS_creerCoups(){
	Coups coups;

	Position position;
	Pion pion=BLANC;
	for(int i=0;i<MAX_COUPS;i++) ///////////////////////////////////////INITIALISATION ?
		coups[i]=CP_creerCoup(POS_fixerPosition(8,8,*position),pion);

	return coups;
}

void CPS_ajouterCoups(Coups* coups, Coup coup){
	unsigned int i =0;
	while ((i<MAX_COUPS))
		if ((POS_obtenirLigne(obtenirPositionCoup(coups[i]))==8) && ((POS_obtenirColonne(obtenirPositionCoup(coups[i]))==8))){ 
		////////////// si c'est un case d'initialisation (en 8*8, case impossible du coup car indices commencent à 0)
			i++;
		}
		else{
			coups[i]=coup;
		}
	}
}

unsigned int CPS_nbCoups(Coups coups){
	unsigned int i =0;
	while ((i<MAX_COUPS))
		if ((POS_obtenirLigne(obtenirPositionCoup(coups[i]))==8) && ((POS_obtenirColonne(obtenirPositionCoup(coups[i]))==8))){ 
		////////////// si c'est un case d'initialisation (en 8*8, case impossible du coup car indices commencent à 0)
			i++;
		}
		else{
			return i;
		}
	}
}

Coup CPS_iemeCoup(Coups coups, unsigned int i){
	assert(i>=0 && i<MAX_COUPS); /////////////////////////////////A CONFIRMER
	return coups[i];
}

