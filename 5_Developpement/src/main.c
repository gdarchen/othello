#include <stdio.h>
#include <stdlib.h>
#include "FaireUnePartie.h"
#include "Affichage.h"
#include "ObtenirCoupIA.h"
#include "ObtenirCoupHumain.h"

int main(int argc, char** argv){
	Couleur vainqueur=CL_blanc();
	int matchNul = 0;

	if(argc!=2){
		afficherAide();
	}
	else
	{
		if (argc==2 && argv[1]=="standard"){
			faireUnePartie(afficherPlateau,obtenirCoupHumain,obtenirCoupIA,&vainqueur,&matchNul);
		}
		else
		{
			if (argc==2 && argv[1]=="tournoi"){
				faireUnePartie(afficherPlateau,obtenirCoupIA,obtenirCoupIA,&vainqueur,&matchNul);
			}
		}
	}

	return EXIT_SUCCESS;
}
