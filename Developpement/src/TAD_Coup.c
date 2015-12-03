#include "TAD_Coup.h"
#include "TAD_Position.h"
#include "TAD_Pion.h"

/* Partie publique */

Coup CP_creerCoup(Position position, Pion pion){
	Coup coup;
	coup.position = position;
	coup.pion = pion;
	return coup;
}


Position CP_obtenirPositionCoup(Coup coup){
	return coup.position;
}

Pion CP_obtenirPionCoup(Coup coup){
	return coup.pion;
}

int CP_sontEgaux(Coup coup1, Coup coup2){
	return(POS_sontEgales(coup1.position,coup2.position) && PI_sontEgaux(coup1.pion,coup2.pion));
}
