/**
 * \file ObtenirCoupHumain.h
 * \brief Implantation et signatures des fonctions publiques d'ObtenirCoupHumain
 * \author Groupe 1.5
 * \version 1.0
 * \date 02/12/2015
 *
 */

#ifndef __OBTENIR_COUP_HUMAIN__
#define __OBTENIR_COUP_HUMAIN__
#include "TAD_Coup.h"
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"


 /**
  * \fn Coup obtenirCoupIA(plateau Plateau, couleur Couleur)
  * \brief Fonction permettant de récupérer le coup joué par l'humain
  *
  * \param Plateau plateau, le plateau du jeu en cours
  * \param Couleur couleur, la couleur représentée par l'humain
  * \return Coup
  */
 Coup obtenirCoupHumain(Plateau plateau, Couleur couleur);

  #endif
