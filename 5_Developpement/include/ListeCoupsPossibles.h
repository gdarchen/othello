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
#include "FaireUnePartie.h"

/**
 * \fn Coups listeCoupsPossibles(Plateau plateau, Couleur couleur)
 * \brief Fonction qui retourne un ensemble de coups possibles
 *
 * \param Plateau plateau, le plateau
 * \param Couleur couleur, couleur du joueur courant
 * \return Coups
 */
Coups listeCoupsPossibles(Plateau plateau, Couleur couleur);

/**
 * \fn void copierPlateau(Plateau plateauACopier, Plateau* plateauCopie)
 * \brief Procédure qui copie un plateau sur un autre
 *
 * \param Plateau plateauACopier, le plateau à copier
 * \param Plateau* plateauCopie, le plateau copié
 */
void copierPlateau(Plateau plateauACopier, Plateau* plateauCopie);

/**
 * \fn int coupValide(Plateau plateau, Coup coup)
 * \brief Fonction qui vérifie qu'un coup est valide
 *
 * \param Plateau plateau, le plateau
 * \param Coup coup, le coup à vérifier
 */
int coupValide(Plateau plateau, Coup coup);

#endif
