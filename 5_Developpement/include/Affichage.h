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
//#include "FaireUnePartie.h"
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "TAD_Plateau.h"
#include "TAD_Position.h"

 /**
  * \fn void afficherAide()
  * \brief Fonction qui affiche l'aide du jeu d'Othello (exécutable appelé sans argument)
  *
  */
void afficherAide();

 /**
  * \fn void afficherPlateau(Plateau plateau)
  * \brief Fonction qui affiche l'état du plateau à un instant donné
  *
  * \param Plateau plateau, le plateau du jeu en cours
  */
void afficherPlateau(Plateau plateau);

  #endif
