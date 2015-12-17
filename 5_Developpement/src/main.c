#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FaireUnePartie.h"
#include "Affichage.h"
#include "ObtenirCoupIA.h"
#include "ObtenirCoupHumain.h"

int main(int argc, char** argv){
	Couleur vainqueur=CL_blanc();
	int matchNul = 0;

	if(argc!=3){
		afficherAide();
	}
	else
	{
		if (argc==3 && (strcmp(argv[1],"standard")==0)){
			if (strcmp(argv[2],"blanc")==0){
				faireUnePartie(afficherPlateau,obtenirCoupHumain,obtenirCoupIA,&vainqueur,&matchNul,CL_blanc());
			}
			else{
				if (strcmp(argv[2],"noir")==0){
					faireUnePartie(afficherPlateau,obtenirCoupHumain,obtenirCoupIA,&vainqueur,&matchNul,CL_noir());
				}
			}
		}
		else
		{
			if (argc==3 && (strcmp(argv[1],"tournoi")==0)){
				if (strcmp(argv[2],"blanc")==0){
					faireUnePartie(afficherTournoi,obtenirCoupIA,obtenirCoupIA,&vainqueur,&matchNul,CL_blanc());
				}
				else{
					if (strcmp(argv[2],"noir")==0){
						faireUnePartie(afficherTournoi,obtenirCoupIA,obtenirCoupIA,&vainqueur,&matchNul,CL_blanc());
					}
				}
			}
		}
	}
	
	return EXIT_SUCCESS;
}
