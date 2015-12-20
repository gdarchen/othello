/**
 * \file Affichage.h
 * \brief Fonctions d'affichage d'un plateau et d'affichage de l'aide
 * \author Groupe 1.5
 * \version 1.0
 * \date 09/12/2015
 *
 */

#ifndef __AFFICHAGE__
#define __AFFICHAGE__
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "TAD_Plateau.h"
#include "TAD_Position.h"
#include "TAD_Coup.h"

 /**
  * \fn void afficherAide()
  * \brief Fonction qui affiche l'aide du jeu d'Othello (exécutable appelé sans argument)
  *
  */
void afficherAide();

 /**
  * \fn void afficherTournoi(Plateau plateau)
  * \brief Fonction qui joue en mode tournoi en affichant les coups choisis
  *
  * \param Plateau plateau, le plateau du jeu en cours
  * \param Coup coup, le coup joué
  */
void afficherTournoi(Plateau plateau, Coup coup, int aPuJouer,int estPartieFinie);

 /**
  * \fn char intToChar(unsigned int i)
  * \brief Fonction qui convertit un entier en une lettre
  *
  * \param unsigned int i, l'entier à convertir
  * \return char
  */
char intToChar(unsigned int i);

 /**
  * \fn void afficherPlateau(Plateau plateau)
  * \brief Fonction qui affiche l'état du plateau à un instant donné
  *
  * \param Plateau plateau, le plateau du jeu en cours
  * \param Coup coup, le coup joué
  */
void afficherPlateau(Plateau plateau, Coup coup, int aPuJouer,int estPartieFinie);

 /**
  * \fn void afficherCoup(Couleur couleurJouer, Coup coupJoueur)
  * \brief Fonction qui affiche le coup d'un joueur
  *
  * \param Couleur couleurJoueur, la couleur du joueur dont on affiche le coup
  * \param Coup coupJoueur, le coup joué par le joueur de couleur couleurJoueur
  */
void afficherCoup(Couleur couleurJoueur, Coup coupJoueur);

#endif
