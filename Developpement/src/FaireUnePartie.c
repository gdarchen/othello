#include "FaireUnePartie.h"
#include <stddef.h>
#define TRUE 1
#define FALSE 0

void faireUnePartie(void(*afficherPlateau)(Plateau), GETCOUP(*obtenirCoupJoueur1)(Plateau,Couleur,Coup), GETCOUP(*obtenirCoupJoueur2)(Plateau,Couleur,Coup), Couleur* joueur, int* estMatchNul)
{   Plateau *plateau=InitialiserPlateau();
    int *aPuJouerJoueur1=TRUE;
    int *aPuJouerJoueur2=TRUE;
    int *estFinie=FALSE;
    Couleur couleurJoueur1=CL=CL_blanc();
    Couleur couleurJoueur2=CL_noir();
    unsigned int *nbPionsBlancs=2;
    unsigned int *nbPionsNoirs=2;
    afficherPlateau(plateau);
    while (!(estFinie)) {
        jouer(&plateau,couleurJoueur1,obtenirCoupJoueur1,&aPuJouerJoueur1);
        afficherPlateau(*plateau);
        jouer(&plateau,couleurJoueur2,obtenirCoupJoueur2,&aPuJouerJoueur2);
        finPartie(plateau,aPuJouerJoueur1,aPuJouerJoueur2,&nbPionsNoirs,&nbPionsBlancs,&estFinie);
        
    }
    if (*nbPionsBlancs==*nbPionsNoirs){
        *joueur=CL_blanc();
        *estMatchNul=true;
        else *estMatchNul=FALSE;
        if (*nbPionsBlancs>*nbPionsNoirs){
            *joueur=CL_blanc();
            else *joueur=CL_blanc();
        }
        
    }
}