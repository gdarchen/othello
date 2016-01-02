/**
 * \file ObtenirCoupIA.h
 * \brief Implantation et signatures des fonctions publiques d'ObtenirCoupIA
 * \author Groupe 1.5
 * \version 1.0
 * \date 02/12/2015
 *
 */

#ifndef __OBTENIR_COUP_IA__
#define __OBTENIR_COUP_IA__
#include "TAD_Coup.h"
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"

/**
 * \def PROFONDEUR 5
 * \brief Profondeur d'exploration de scoreDUnCoup et minMax
 *
 */

#define PROFONDEUR 4

 /**
  * \fn Coup obtenirCoupIA(plateau Plateau, couleur Couleur)
  * \brief Fonction permettant de récupérer le coup joué par l'IA
  *
  * \param Plateau plateau, le plateau du jeu en cours
  * \param Couleur couleur, la couleur représentée par l'IA
  * \return Coup
  */
 Coup obtenirCoupIA(Plateau plateau, Couleur couleur);

  #endif
