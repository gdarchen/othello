#include "FaireUnePartie_Prive.h"
#define TRUE 1
#define FALSE 0


Plateau InitialiserPlateau(){
    Plateau plateaudejeu;
    Pion pionnnoir;
    Pion pionblanc;
    Position* positionpion;
    plateaudejeu=PL_creerPlateau();
    pionnoir=PI_creerPion(CL_noir());
    pionblanc=creerPion(CL_noir());
    POS_fixerPosition(3,3,*positionpion);
    PL_poserPion(plateaudejeu, positionpion, pionblanc);
    POS_fixerPosition(3,4,*positionpion);
    PL_poserPion(plateaudejeu, positionpion, pionnoir);
    POS_fixerPosition(4,3,*positionpion);
    PL_poserPion(plateaudejeu, positionpion, pionnoir);
    POS_fixerPosition(4,4,*positionpion);
    PL_poserPion(plateaudejeu, positionpion, pionblanc);
    return(plateaudejeu);
}


void jouer(Plateau* plateau , Couleur* couleurJoueur, GETCOUP(*obtenirCoupJoueur)(Plateau,Couleur,Coup), int* aPuJouer)
{
    unsigned int i;
    int res;
    Coups coups;
    Coup coupJoueur;
    res=FALSE
    coupJoueur=obtenirCoupJoueur(*plateau,*couleurJoueur);
    coups=listeCoupsPossibles(*plateau,*couleurJoueur);
    for(i=1;i<nbCoups(coups);i++){
        if (iemeCoup(coups,i)=coup)) {
            jouerCoup(coupJoueur,&plateau);
            res=TRUE;
        }
    }
    *aPuJouer=res;
}

void jouerCoup (Coup coup, Plateau* plateau)
{ unsigned int i;
    Position pos;
    Pion  pionJoueur;
    
    poserPion(&plateau,obtenirPositionCoup(coup),obtenirPionCoup(coup));
    pos=obtenirPositionCoup(coup);
    pionJoueur=obtenirPionCoup(coup);
    inverserPions(pos,pionJoueur,&plateau);
    
}

void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau)
{ Position *posTmp=NULL;
    int x,y;
    unsigned int i,j;
    int* pionPresent=NULL
    for (i=1; i<4; i++)
    { x:i-2;
        for (j=1; j<3; j++)
        {    y=i-2;
            if !((x==0) && { y==0)){
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
{               Position *poscour =&posCourante
                if ! (posInitiale==posCourante){
                    inverserPions(posCourante,&plateau);
                    POS_fixerPosition(x+i,y+j,poscour);
                    inverserPionsDir(&plateau,posInitiale,poscour,x,y);
            }
}
                 
                 
void pionEstPresent(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
{
                unsigned int i,j;
                i=POS_obtenirLigne(pos);
                j=POS_obtenirColonne(pos);
                if (((x+i)<1) || ((x+i)>8) || ((y+j)<1) || ((y+j)>8)) {
                    *pionPresent=FALSE;
                    else
                        POS_fixerPosition(x+i,y+j,&pos)
                        pionEstPresentRecursif(pionJoueur,&pos,&plateau,&pionPresent);
                }
}
                 
                 
void pionEstPresentRecursif(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
{
                unsigned int i,j;
                Couleur couleurJoueur;
                i==POS_obtenirLigne(pos);
                j=POS_obtenirColonne(pos);
                couleurJoueur=PI_obtenirCouleur(pionJoueur);
                if PL_estCaseVide(*plateau,*pos) {
                    *pionPresent=FALSE;
                    else
                        IF PI_obtenirCouleur(PL_obtenirPion(*plateau,*pos))==couleurJoueur {
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
                if ((aPuJouerJoueur1=FALSE) && ( aPuJouerJoueur2=FALSE)) || (plateauRempli(plateau)){
                    nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);
                    *estFinie=TRUE
                }
            }
                 
                 
void nbPions (Plateau plateau, unsigned int* nbPionsNoirs, unsigned int* nbPionsBlancs)
{
                Position *pos;
                for(i=1;i<9;i++){
                    for(j=1;j<9;j++){
                        POS_fixerPosition(i,j,pos)
                        if PI_obtenirCouleur(PL_obtenirPion(plateau,pos)==CL_noir(){
                            *nbPionsNoirs=++;
                            else *nbPionsBlancs=++;
                        }
                                             }
                                             }
}
                                             
                                             
                                             
                                             
                                             
                                             
                                             
                                             
                                             
