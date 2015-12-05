/**
 * \file ListeCoupsPossibles.h
 * \brief Implantation et signatures des fonctions publiques de ListeCoupsPossibles
 * \author Groupe 1.5
 * \version 1.0
 * \date 02/12/2015
 *
 */

#ifndef __LISTES_COUPS_POSSIBLES__
#define __LISTES_COUPS_POSSIBLES__
#include "TAD_Coup.h"
#include "TAD_Coups.h"
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"

/**
 * \fn Coups listeCoupsPossibles(Plateau plateau, Couleur couleur)
 * \brief Fonction qui retourne un ensemble de coups possibles
 *
 * \param Plateau plateau, le plateau
 * \param Couleur couleur, couleur du joueur courant
 * \return Coups
 */
Coups listeCoupsPossibles(Plateau plateau, Couleur couleur);

#endif
