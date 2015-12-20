#include <stdio.h>
#include <stdlib.h>
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "TAD_Plateau.h"
#include "TAD_Position.h"
#include "Affichage.h"
#include "FaireUnePartie.h"

void afficherAide(){
  printf("Aide du programme othello \n"
  "Les options possibles sont : \n"
    "\t othello standard blanc|noir [profondeur>2] \n"
      "\t\t permet de jouer contre l’ordinateur en lui donnant les blancs \n"
      "\t\t ou les noirs \n"
      "\t\t par defaut la profondeur d’analyse est egale a 5 \n \n"
    "\t othello tournoi blanc|noir [profondeur>2] \n"
      "\t\t permet de faire jouer le programme dans un mode ’tournoi’ en \n"
      "\t\t lui donnant les blancs ou les noirs\n"
      "\t\t par defaut la profondeur d’analyse est egale a 5\n\n");
}

void afficherTournoi(Plateau plateau, Coup coup, int aPuJouer,int estPartieFinie){
  int nbPionsNoirs,nbPionsBlancs,i,j,ligne;
  char colonne;

  if(estPartieFinie){
    nbPions(plateau, &nbPionsNoirs, &nbPionsBlancs);
    if(nbPionsNoirs==nbPionsBlancs){
      printf("nulle\n");
    }
    else{
      if(nbPionsNoirs>nbPionsBlancs){
        printf("noir\n");
      }
      else{
        printf("blanc\n");
      }
    }
  }
  else{
    if(!aPuJouer){
      printf("passe\n");
    }
    else{
      i=POS_obtenirLigne(CP_obtenirPositionCoup(coup));
      j=POS_obtenirColonne(CP_obtenirPositionCoup(coup));
      colonne=intToChar(i);
      ligne=j+1;
      printf("%c%d\n",colonne,ligne);
    }
  }
}

char intToChar(unsigned int i){
  char res;
        switch(i){
          case 0 :
            res='a';
          break;
          case 1 :
            res='b';
          break;
          case 2 :
            res='c';
          break;
          case 3 :
            res='d';
          break;
          case 4 :
            res='e';
          break;
          case 5 :
            res='f';
          break;
          case 6 :
            res='g';
          break;
          case 7 :
            res='h';
          break;
        }
    return(res);
}

void afficherPlateau(Plateau plateau, Coup coup, int aPuJouer,int estPartieFinie){
  unsigned int i,j;
  int nbPionsNoirs,nbPionsBlancs;
  Couleur couleurBlanc, couleurNoir;
  couleurBlanc=CL_blanc();
  couleurNoir=CL_noir();
  if(!estPartieFinie){
    printf("    1   2   3   4   5   6   7   8 \n");
    printf("   ———————————————————————————————\n");
    Position position;
    for(i=1;i<9;i++){
      printf("%d |", i);
      for (j=1;j<9;j++){
        POS_fixerPosition(i-1,j-1,&position);
        if (!PL_estCaseVide(plateau,position)){
          if (CL_sontEgales((PI_obtenirCouleur(PL_obtenirPion(plateau,position))),couleurBlanc)){
            printf(" ○ ");
            printf("|");
          }
          else
          {
            if (CL_sontEgales((PI_obtenirCouleur(PL_obtenirPion(plateau,position))),couleurNoir)){
              printf(" ● |");
            }
          }
        }
        else
        {
          printf("   |");
        }
      }
  	  printf("\n   ———————————————————————————————\n");
    }
  }
  else{
    nbPions(plateau, &nbPionsNoirs, &nbPionsBlancs);
    if(nbPionsNoirs==nbPionsBlancs){
      printf("La partie est nulle\n");
    }
    else{
      if(nbPionsNoirs>nbPionsBlancs){
        printf("Le joueur ayant les pions ●  a gagné\n");
      }
      else{
        printf("Le joueur ayant les pions ○  a gagné\n");
      }
    }
  }
}

void afficherCoup(Couleur couleurJoueur, Coup coupJoueur){
  Position pos = CP_obtenirPositionCoup(coupJoueur);
  unsigned int ligne = POS_obtenirLigne(pos);
  unsigned int colonne = POS_obtenirColonne(pos);
  ligne ++; // pour l'affichage
  colonne ++; // pour l'affichage

  if (CL_sontEgales(couleurJoueur,CL_blanc())){
    printf("\n\n\n Le joueur ○  joue en : \n \tligne : %u — colonne : %u \n\n",ligne,colonne);
  }
  else{
    if (CL_sontEgales(couleurJoueur,CL_noir())){
      printf("\n\n\n Le joueur ●  joue en : \n \tligne : %u — colonne : %u \n\n",ligne,colonne);
    }
  }
}

