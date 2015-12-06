#include "FaireUnePartie.h"
#include "FaireUnePartie_Prive.h"
#include <stddef.h>
#define TRUE 1
#define FALSE 0

/* Partie publique */

void faireUnePartie(void(*afficherPlateau)(Plateau), Coup(*getCoup1)(Plateau,Pion), Coup(*getCoup2)(Plateau,Pion), Couleur* joueur, int* estMatchNul)
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
        jouer(&plateau,couleurJoueur1,getCoup1,&aPuJouerJoueur1);
        afficherPlateau(*plateau);
        jouer(&plateau,couleurJoueur2,getCoup2,&aPuJouerJoueur2);
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

/* Partie privée */


Plateau initialiserPlateau(){
    Plateau plateaudejeu;
    Pion pionnoir;
    Pion pionblanc;
    Position* positionpion;
    plateaudejeu=PL_creerPlateau();
    pionnoir=PI_creerPion(CL_noir());
    pionblanc=PI_creerPion(CL_blanc());
    POS_fixerPosition(3,3,positionpion);
    PL_poserPion(&plateaudejeu, *positionpion, pionblanc);
    POS_fixerPosition(3,4,positionpion);
    PL_poserPion(&plateaudejeu, *positionpion, pionnoir);
    POS_fixerPosition(4,3,positionpion);
    PL_poserPion(&plateaudejeu, *positionpion, pionnoir);
    POS_fixerPosition(4,4,positionpion);
    PL_poserPion(&plateaudejeu, *positionpion, pionblanc);
    return(plateaudejeu);
}


void jouer(Plateau* plateau , Couleur* couleurJoueur, Coup(*getCoup)(Plateau,Pion), int* aPuJouer)
{
    unsigned int i;
    int res;
    Coups coups;
    Coup coupJoueur;
    res=FALSE;
    Pion pionJoueur;
    pionJoueur=PI_creerPion(couleurJoueur);
    coupJoueur=getCoup(plateau,pionJoueur);
    coups=listeCoupsPossibles(*plateau,*couleurJoueur);
    for(i=1;i<CPS_nbCoups(coups);i++){
        if (CPS_iemeCoup(coups,i)==coupJoueur) {
            jouerCoup(coupJoueur,plateau);
            res=TRUE;
        }
    }
    *aPuJouer=res;
}

void jouerCoup (Coup coup, Plateau* plateau)
{ unsigned int i;
    Position pos;
    Pion  pionJoueur;

    PL_poserPion(plateau,CP_obtenirPositionCoup(coup),CP_obtenirPionCoup(coup));
    pos=CP_obtenirPositionCoup(coup);
    pionJoueur=CP_obtenirPionCoup(coup);
    inverserPions(pos,pionJoueur,&plateau);

}

void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau)
{ Position *posTmp=NULL;
    int x,y;
    unsigned int i,j;
    int* pionPresent=NULL;
    for (i=1; i<4; i++)
    { x:i-2;
        for (j=1; j<3; j++)
        {    y=i-2;
            if (!((x==0) && (y==0))){
                *posTmp=&pos;
                pionEstPresent(pionJoueur,x,y,posTmp,&plateau,*pionPresent)
                if *pionPresent {
                    inverserPionsDir(&plateau,pos,posTmp,-x,-y,pionJoueur);
                }
            }
            }
                  }

                  }

void inverserPionsDir(Plateau* plateau, Position posInitiale, Position posCourante, unsigned int x, unsigned int y)
{       Position *poscour =&posCourante;
    if (! (posInitiale==posCourante)){
        inverserPions(posCourante,plateau);
        POS_fixerPosition(x+i,y+j,poscour);
        inverserPionsDir(&plateau,posInitiale,poscour,x,y);
    }
}



void pionEstPresent(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
{
                unsigned int i,j;
                i=POS_obtenirLigne(*pos);
                j=POS_obtenirColonne(*pos);
                if (((x+i)<1) || ((x+i)>8) || ((y+j)<1) || ((y+j)>8)) {
                    *pionPresent=FALSE;
                    else
                        POS_fixerPosition(x+i,y+j,&pos);
                    pionEstPresentRecursif(pionJoueur,&pos,&plateau,&pionPresent);
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
                    *pionPresent=FALSE;
                    else
                        if (PI_obtenirCouleur(PL_obtenirPion(*plateau,*pos))==couleurJoueur) {
                            *pionPresent=TRUE;
                            else
                                if (((x+i)<1) || ((x+i)>8) || ((y+j)<1) || ((y+j)>8)) {
                                    *pionPresent=FALSE;
                                    else
                                        POS_fixerPosition(x+i,y+j,&pos);
                                    pionEstPresentRecursif(pionJoueur,x,y,&pos,&plateau,&pionPresent);
                                }
                        }
                }
}

void finPartie (Plateau plateau, int aPuJouerJoueur1, int aPuJouerJoueur2 , unsigned int* nbPionsNoirs, unsigned int* nbPionsBlancs , int* estFinie)
{
                if (((aPuJouerJoueur1=FALSE) && ( aPuJouerJoueur2=FALSE))) || (plateauRempli(plateau)){
                    nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);
                    *estFinie=TRUE;
                }
            }


void nbPions (Plateau plateau, unsigned int* nbPionsNoirs, unsigned int* nbPionsBlancs)
{
                Position *pos;
                Couelur couleur=CL_noir();
                unsigned int i,j;
                for(i=1;i<9;i++){
                    for(j=1;j<9;j++){
                        POS_fixerPosition(i,j,pos);
                        if (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),couleur){
                            *nbPionsNoirs=++;
                          }
                        else {
                          *nbPionsBlancs=++;
                        }
                    }
                }
}
