#include "TAD_Couleur.h"

/* Partie publique */

Couleur CL_blanc(){
	return BLANC;
}

Couleur CL_noir(){
	return NOIR;
}

Couleur CL_changerCouleur(Couleur couleur){
	if (couleur==BLANC)
		return NOIR;
	else
		return BLANC;
}