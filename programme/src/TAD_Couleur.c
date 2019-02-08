#include "TAD_Couleur.h"

/* Partie publique */

Couleur CL_blanc(){
	return BLANC;
}

Couleur CL_noir(){
	return NOIR;
}

Couleur CL_changerCouleur(Couleur couleur){
	if (CL_sontEgales(couleur,CL_blanc())){
		return CL_noir();
	}
	else {
		return CL_blanc();
	}
}

int CL_sontEgales(Couleur couleur1, Couleur couleur2){
	return(couleur1==couleur2);
}
