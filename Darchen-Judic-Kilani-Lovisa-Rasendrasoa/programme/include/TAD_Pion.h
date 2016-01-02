/**
 * \file TAD_PION.h
 * \brief Implantation du TAD Pion pour le jeu Othello
 * \author Groupe 1.5
 * \version 1.0
 * \date 2/12/2015
 *
 */

#ifndef __TAD_PION__
#define __TAD_PION__
#include "TAD_Couleur.h"

/**
 * \struct Pion
 * \brief Le type Pion permet de représenter un pion
 *
 */

 typedef struct {
  Couleur couleur; /**< la couleur du pion */
} Pion;


/**
 * \fn Pion PI_creerPion(Couleur couleur)
 * \brief Fonction de création d'un pion selon une couleur donnée
 *
 * \param Couleur couleur, la couleur à donner au pion
 * \return Pion
 */
Pion PI_creerPion(Couleur couleur);


/**
 * \fn Couleur PI_obtenirCouleur(Pion pion)
 * \brief Fonction permettant d'obtenir la couleur d'un pion
 *
 * \param Pion pion; le pion dont on veut la couleur
 * \return Couleur
 */
Couleur PI_obtenirCouleur(Pion pion);

/**
 * \fn void PI_retournerPion(Pion* pion)
 * \brief Fonction permettant de retourner un pion
 *
 * \param Pion* pion, le pion à retourner
 */
void PI_retournerPion(Pion* pion);

/**
 * \fn PI_sontEgaux
 * \brief Fonction testant l'égalité de deux pions
 *
 * \param Pion pion1
 * \param Pion pion2
 * \return int (Booleen)
 */
 int PI_sontEgaux(Pion pion1, Pion pion2);

#endif
