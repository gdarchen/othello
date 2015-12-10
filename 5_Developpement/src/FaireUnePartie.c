#include "FaireUnePartie.h"
#include "FaireUnePartie_Prive.h"
#include "ListeCoupsPossibles.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#define TRUE 1
#define FALSE 0

/* Partie publique */

void faireUnePartie(void(*afficherPlateau)(Plateau), Coup(*getCoup1)(Plateau,Pion), Coup(*getCoup2)(Plateau,Pion), Couleur *joueur, int* estMatchNul)
{   Plateau plateau=PL_creerPlateau();
    initialiserPlateau(&plateau);
    int aPuJouerJoueur1=TRUE;
    int aPuJouerJoueur2=TRUE;
    int *estFinie=FALSE;
    Couleur couleurJoueur1=CL_blanc();
    Couleur couleurJoueur2=CL_noir();
    unsigned int nbPionsBlancs=2;
    unsigned int nbPionsNoirs=2;
    afficherPlateau(plateau);
    while (!(estFinie)) {
        jouer(&plateau,&couleurJoueur1,getCoup1,&aPuJouerJoueur1);
        afficherPlateau(plateau);
        jouer(&plateau,&couleurJoueur2,getCoup2,&aPuJouerJoueur2);
        finPartie(plateau,aPuJouerJoueur1,aPuJouerJoueur2,&nbPionsNoirs,&nbPionsBlancs,estFinie);

    }
    if (nbPionsBlancs==nbPionsNoirs){
        *joueur=CL_blanc();
        *estMatchNul=TRUE;}
    else (*estMatchNul=FALSE);{
        if (nbPionsBlancs>nbPionsNoirs){
            *joueur=CL_blanc();}
        else {*joueur=CL_blanc();}



    }
}

/* Partie privée */


void initialiserPlateau(Plateau *plateauDeJeu){
    Pion pionNoir;
    Pion pionBlanc;
    Position positionPion;

    *plateauDeJeu=PL_creerPlateau();
    pionNoir=PI_creerPion(CL_noir());
    pionBlanc=PI_creerPion(CL_blanc());
    POS_fixerPosition(3,3,&positionPion);
    PL_poserPion(plateauDeJeu, positionPion, pionBlanc);
    POS_fixerPosition(3,4,&positionPion);
    PL_poserPion(plateauDeJeu, positionPion, pionNoir);
    POS_fixerPosition(4,3,&positionPion);
    PL_poserPion(plateauDeJeu, positionPion, pionNoir);
    POS_fixerPosition(4,4,&positionPion);
    PL_poserPion(plateauDeJeu, positionPion, pionBlanc);
}


void jouer(Plateau* plateau , Couleur* couleurJoueur, Coup(*getCoup)(Plateau,Pion), int* aPuJouer)
{
    unsigned int i;
    int res;
    Coups coups;
    Coup coupJoueur;
    res=FALSE;
    Pion pionJoueur;
    pionJoueur=PI_creerPion(*couleurJoueur);
    coupJoueur=getCoup(*plateau,pionJoueur);
    coups=listeCoupsPossibles(*plateau,*couleurJoueur);
    for(i=1;i<CPS_nbCoups(coups);i++){
        if (CP_sontEgaux(CPS_iemeCoup(coups,i),coupJoueur)) {
            jouerCoup(coupJoueur,plateau);
            res=TRUE;
        }
    }
    *aPuJouer=res;
}

void jouerCoup (Coup coup, Plateau* plateau)
{   Position pos;
    Pion  pionJoueur;

    PL_poserPion(plateau,CP_obtenirPositionCoup(coup),CP_obtenirPionCoup(coup));
    pos=CP_obtenirPositionCoup(coup);
    pionJoueur=CP_obtenirPionCoup(coup);
    inverserPions(pos,pionJoueur,plateau);

}

void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau)
{ Position posTmp;
    int x,y;
    unsigned int i,j;
    int pionPresent;
    for (i=1; i<4; i++){
        x=i-2;
        for (j=1; j<4; j++){
            y=j-2;
            if ((x!=0) && (y!=0)){
                posTmp=pos;
                pionEstPresent(pionJoueur,x,y,&posTmp,plateau,&pionPresent);
                if (pionPresent) {
                    inverserPionsDir(plateau,pos,posTmp,-x,-y);
                }
            }
        }
    }

}

void inverserPionsDir(Plateau* plateau, Position posInitiale, Position posCourante, unsigned int x, unsigned int y)
{       Position *poscour=&posCourante;
    unsigned int i,j;
    i=POS_obtenirLigne(*poscour);
    j=POS_obtenirColonne(*poscour);

    if (!(POS_sontEgales(posInitiale,*poscour))){
        PL_inverserPion(plateau,*poscour);
        POS_fixerPosition(x+i,y+j,poscour);
        inverserPionsDir(plateau,posInitiale,*poscour,x,y);
    }
}



void pionEstPresent(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
{
    unsigned int i,j;
    i=POS_obtenirLigne(*pos);
    j=POS_obtenirColonne(*pos);
    Couleur couleurAdversaire;
    couleurAdversaire=CL_changerCouleur(PI_obtenirCouleur(pionJoueur));
    if (((x+i)<0) || ((x+i)>7) || ((y+j)<0) || ((y+j)>7)) {
        *pionPresent=FALSE;}
    else {
        POS_fixerPosition(x+i,y+j,pos);
        if(CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(*plateau,*pos)),couleurAdversaire)){
          POS_fixerPosition(2*x+i,2*y+j,pos);
          pionEstPresentRecursif(pionJoueur,x,y,pos,plateau,pionPresent);
        }
        else {
          *pionPresent=FALSE;
        }
    }
}


void pionEstPresentRecursif(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
{
    unsigned int i,j;
    Couleur couleurJoueur;
    i=POS_obtenirLigne(*pos);
    j=POS_obtenirColonne(*pos);
    couleurJoueur=PI_obtenirCouleur(pionJoueur);
    if (PL_estCaseVide(*plateau,*pos)) {
        *pionPresent=FALSE;}
    else {
        if (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(*plateau,*pos)),couleurJoueur)) {
            *pionPresent=TRUE;}
        else {
            if (((x+i)<0) || ((x+i)>7) || ((y+j)<0) || ((y+j)>7)) {
                *pionPresent=FALSE;}
            else {
                POS_fixerPosition(x+i,y+j,pos);
                pionEstPresentRecursif(pionJoueur,x,y,pos,plateau,pionPresent);
            }
        }
    }
}

void finPartie (Plateau plateau, int aPuJouerJoueur1, int aPuJouerJoueur2 , unsigned int* nbPionsNoirs, unsigned int* nbPionsBlancs , int* estFinie)
{
    if(((aPuJouerJoueur1==FALSE) && (aPuJouerJoueur2==FALSE)) || (plateauRempli(plateau)==TRUE)){
        nbPions(plateau,nbPionsNoirs,nbPionsBlancs);
        *estFinie=TRUE;
    }
}


void nbPions (Plateau plateau, unsigned int* nbPionsNoirs, unsigned int* nbPionsBlancs)
{
    *nbPionsNoirs=0;
    *nbPionsBlancs=0;
    Position pos;
    Couleur couleur=CL_noir();
    unsigned int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            POS_fixerPosition(i,j,&pos);
            if (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),couleur) && (plateau.presencePions[i][j]==1)){
                *nbPionsNoirs=*nbPionsNoirs+1;
            }
            else {
                if (plateau.presencePions[i][j]==1){
                    *nbPionsBlancs=*nbPionsBlancs+1;
                }
            }
        }
    }
}

int plateauRempli(Plateau plateau){
    int res = TRUE;
    int i,j;
    Position position;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            POS_fixerPosition(i,j,&position);
            if (PL_estCaseVide(plateau,position)){
                res = FALSE;
            }
        }
    }

    return res;

    /*Coups coupsJoueurBlanc;
    Coups coupsJoueurNoir;

    Couleur couleurNoir=CL_noir();
    Couleur couleurBlanc=CL_blanc();

    coupsJoueurNoir=listeCoupsPossibles(plateau,couleurNoir);
    coupsJoueurBlanc=listeCoupsPossibles(plateau,couleurBlanc);

    if ((CPS_nbCoups(coupsJoueurNoir)==0) && (CPS_nbCoups(coupsJoueurBlanc)==0)){
        return (1) ; }
    else { return (0) ; }*/
}
