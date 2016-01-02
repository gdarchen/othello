#include "FaireUnePartie.h"
#include "FaireUnePartie_Prive.h"
#include "ListeCoupsPossibles.h"
#include "Affichage.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#define TRUE 1
#define FALSE 0

/* Partie publique */

void faireUnePartie(void(*afficher)(Plateau,Coup,int,int), Coup(*getCoup1)(Plateau,Couleur), Coup(*getCoup2)(Plateau,Couleur), Couleur *vainqueur, int* estMatchNul, Couleur couleurJoueur1)
{
    Plateau plateau=PL_creerPlateau();
    initialiserPlateau(&plateau);
    int aPuJouerJoueur1=TRUE, aPuJouerJoueur2=TRUE;
    int estFinie=FALSE;
    Couleur couleurJoueur2=CL_changerCouleur(couleurJoueur1);
    int nbPionsBlancs=2, nbPionsNoirs=2;
    Coup coupJoueur1, coupJoueur2;

    Position positionInitialisation;
    POS_fixerPosition(4,4,&positionInitialisation);
    coupJoueur1 = CP_creerCoup(positionInitialisation,PI_creerPion(CL_blanc()));

    afficher(plateau,coupJoueur1,aPuJouerJoueur1,estFinie);
    while (!(estFinie)) {
        jouer(&plateau,&couleurJoueur1,getCoup1,&aPuJouerJoueur1,&coupJoueur1);
        afficher(plateau,coupJoueur1,aPuJouerJoueur1,estFinie);
        jouer(&plateau,&couleurJoueur2,getCoup2,&aPuJouerJoueur2,&coupJoueur2);
	      afficher(plateau,coupJoueur2,aPuJouerJoueur2,estFinie);
        finPartie(plateau,aPuJouerJoueur1,aPuJouerJoueur2,&nbPionsNoirs,&nbPionsBlancs,&estFinie);
    }
    afficher(plateau,coupJoueur2,aPuJouerJoueur2,estFinie);
    if (nbPionsBlancs==nbPionsNoirs){
        *vainqueur=CL_blanc();
        *estMatchNul=TRUE;
    }
    else (*estMatchNul=FALSE);{
        if (nbPionsBlancs>nbPionsNoirs){
            *vainqueur=CL_blanc();
        }
        else {
            *vainqueur=CL_noir();
        }
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


void jouer(Plateau* plateau , Couleur* couleurJoueur, Coup(*getCoup)(Plateau,Couleur), int* aPuJouer, Coup* coupJoueur){
    unsigned int i;
    int res;
    Coups coups;
    res=FALSE;
    *coupJoueur=getCoup(*plateau,*couleurJoueur);
    coups=listeCoupsPossibles(*plateau,*couleurJoueur);
    if (CPS_nbCoups(coups)>0){
        for(i=0;i<CPS_nbCoups(coups);i++){
            if (CP_sontEgaux(CPS_iemeCoup(coups,i),*coupJoueur)) {
                jouerCoup(*coupJoueur,plateau);
                res=TRUE;
            }
        }
    }
    *aPuJouer=res;
}

void jouerCoup (Coup coup, Plateau* plateau){
    Position pos;
    Pion  pionJoueur;

    PL_poserPion(plateau,CP_obtenirPositionCoup(coup),CP_obtenirPionCoup(coup));
    pos=CP_obtenirPositionCoup(coup);
    pionJoueur=CP_obtenirPionCoup(coup);
    inverserPions(pos,pionJoueur,plateau);
}


void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau){
    Position posTmp;
    Direction dir;
    int pionPresent;
    for (dir = GAUCHE; dir <= DIAGDB; dir++){
        posTmp = pos;
        pionEstPresent(pionJoueur,dir,&posTmp,plateau,&pionPresent);
        if (pionPresent) {
            inverserPionsDir(plateau,pos,DIR_positionSelonDirection(posTmp,DIR_inverserDirection(dir)),DIR_inverserDirection(dir));
        }
    }
}


void inverserPionsDir(Plateau* plateau, Position posInitiale, Position posCourante, Direction dirInversion){
    Position posSuivante=posCourante;
    unsigned int inew,jnew;
    inew=POS_obtenirLigne(DIR_positionSelonDirection(posSuivante,dirInversion));
    jnew=POS_obtenirColonne(DIR_positionSelonDirection(posSuivante,dirInversion));

    if (!(POS_sontEgales(posInitiale,posCourante)) && DIR_deplacementValide(posCourante, dirInversion)){
        PL_inverserPion(plateau,posCourante);
        POS_fixerPosition(inew,jnew,&posSuivante);
        inverserPionsDir(plateau,posInitiale,posSuivante,dirInversion);
    }
}


void pionEstPresent(Pion pionJoueur, Direction dirATester, Position* pos, Plateau* plateau, int* pionPresent){
    Couleur couleurAdversaire;
    couleurAdversaire = CL_changerCouleur(PI_obtenirCouleur(pionJoueur));
    if (!DIR_deplacementValide(*pos,dirATester)) {
        *pionPresent = FALSE;}
    else {
        *pos = DIR_positionSelonDirection(*pos,dirATester);
        /* On doit regarder que la case n'est pas vide car le plateau est rempli des pions blancs par défaut */
        if(CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(*plateau,*pos)),couleurAdversaire) && (!PL_estCaseVide(*plateau,*pos))){
          *pos = DIR_positionSelonDirection(*pos,dirATester);
          pionEstPresentRecursif(pionJoueur,dirATester,pos,plateau,pionPresent);
        }
        else {
          *pionPresent=FALSE;
        }
    }
}


void pionEstPresentRecursif(Pion pionJoueur, Direction dirATester, Position* pos, Plateau* plateau, int* pionPresent)
{
    Couleur couleurJoueur;
    couleurJoueur=PI_obtenirCouleur(pionJoueur);
    if (PL_estCaseVide(*plateau,*pos)) {
        *pionPresent=FALSE;}
    else {
        if (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(*plateau,*pos)),couleurJoueur)) {
            *pionPresent=TRUE;}
        else {
            if (!DIR_deplacementValide(*pos,dirATester)) {
                *pionPresent=FALSE;}
            else {
                *pos = DIR_positionSelonDirection(*pos,dirATester);
                pionEstPresentRecursif(pionJoueur,dirATester,pos,plateau,pionPresent);
            }
        }
    }
}


void finPartie (Plateau plateau, int aPuJouerJoueur1, int aPuJouerJoueur2 , int* nbPionsNoirs, int* nbPionsBlancs , int* estFinie)
{
    if(((aPuJouerJoueur1==FALSE) && (aPuJouerJoueur2==FALSE)) || (plateauRempli(plateau)==TRUE)){
        nbPions(plateau,nbPionsNoirs,nbPionsBlancs);
        *estFinie=TRUE;
    }
}


void nbPions (Plateau plateau, int* nbPionsNoirs, int* nbPionsBlancs)
{
    *nbPionsNoirs=0;
    *nbPionsBlancs=0;
    Position pos;
    Couleur couleur=CL_noir();
    unsigned int i,j;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            POS_fixerPosition(i,j,&pos);
            if((!PL_estCaseVide(plateau,pos))){
                if (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),couleur)){
                    *nbPionsNoirs=*nbPionsNoirs+1;
                }
                else {
                    *nbPionsBlancs=*nbPionsBlancs+1;
                }
            }
        }
    }
}


int plateauRempli(Plateau plateau){
    int res = TRUE;
    unsigned int i=0,j=0;
    Position position;
    /*for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            POS_fixerPosition(i,j,&position);
            if (PL_estCaseVide(plateau,position)){
                res = FALSE;
            }
        }
    }*/
    while(res && (i<8)){
      while(res && (j<8)){
        POS_fixerPosition(i,j,&position);
        if (PL_estCaseVide(plateau,position)){
          res = FALSE;
        }
        j=j+1;
      }
      i=i+1;
    }
    return res;
}


/* Introduction d'un type privé Direction */

Direction DIR_inverserDirection(Direction dirInit){
    Direction newDir;
    switch(dirInit){
        case GAUCHE :
            newDir = DROITE;
            break;
        case DROITE :
            newDir = GAUCHE;
            break;
        case HAUT :
            newDir = BAS;
            break;
        case BAS :
            newDir = HAUT;
            break;
        case DIAGGH :
            newDir = DIAGDB;
            break;
        case DIAGGB :
            newDir = DIAGDH;
            break;
        case DIAGDH :
            newDir = DIAGGB;
            break;
        case DIAGDB :
            newDir = DIAGGH;
            break;
    }
    return newDir;
}


Position DIR_positionSelonDirection(Position posInit, Direction dirDeplacement){
    Position newPos;
    unsigned int i,j;
    i = POS_obtenirLigne(posInit);
    j = POS_obtenirColonne(posInit);
    if (DIR_deplacementValide(posInit,dirDeplacement)){
        switch(dirDeplacement){
            case GAUCHE :
                POS_fixerPosition(i,j-1, &newPos);
                break;
            case DROITE :
                POS_fixerPosition(i,j+1, &newPos);
                break;
            case HAUT :
                POS_fixerPosition(i-1,j, &newPos);
                break;
            case BAS :
                POS_fixerPosition(i+1,j, &newPos);
                break;
            case DIAGGH :
                POS_fixerPosition(i-1,j-1, &newPos);
                break;
            case DIAGGB :
                POS_fixerPosition(i+1,j-1, &newPos);
                break;
            case DIAGDH :
                POS_fixerPosition(i-1,j+1, &newPos);
                break;
            case DIAGDB :
                POS_fixerPosition(i+1,j+1, &newPos);
                break;
        }
    }
    return newPos;
}


int DIR_deplacementValide(Position pos, Direction dirDeplacement){
    int valide;
    unsigned int i,j;
    i = POS_obtenirLigne(pos);
    j = POS_obtenirColonne(pos);
    switch(dirDeplacement){
        case GAUCHE :
            valide = (j >= 1);
            break;
        case DROITE :
            valide = (j <= 6);
            break;
        case HAUT :
            valide = (i >= 1);
            break;
        case BAS :
            valide = (i <= 6);
            break;
        case DIAGGH :
            valide = ((i >= 1) && (j >= 1));
            break;
        case DIAGGB :
            valide = ((i <= 6) && (j >= 1));
            break;
        case DIAGDH :
            valide = ((i >= 1) && (j <= 6));
            break;
        case DIAGDB :
            valide = ((i <= 6) && (j <= 6));
            break;
    }
    return valide;
}

/* Fin du type privé Direction */
