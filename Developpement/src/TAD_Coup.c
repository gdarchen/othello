#include "TAD_Coup.h"

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
