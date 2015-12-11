#include <stdio.h>
#include <stdlib.h>
#include "FaireUnePartie.h"

int main(int argc, char** argv){
	Couleur vainqueur=CL_blanc();
	int matchNul = 0;
	FaireUnePartie(afficherPlateau,obtenirCoupHumain,obtenirCoupIA,&vainqueur,&matchNul);
	
	if(argc<>2){
		afficherAide(); 
	}
	else
	{
		if (argc==2 && argv[1]=="standard"){
			FaireUnePartie(afficherPlateau,obtenirCoupHumain,obtenirCoupIA,&vainqueur,&matchNul);
		}
		else
		{
			if (argc==2 && argv[1]="tournoi"){
				FaireUnePartie(afficherPlateau,obtenirCoupIA,obtenirCoupIA,&vainqueur,&matchNul);
			}
		}
	}

	if (matchNul){
		printf("MATCH NUL !\n");
	}
	return EXIT_SUCCESS;
}
