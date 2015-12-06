/**
 * \file FaireUnePartie.h
 * \brief Implantation de faireunepartie-prive pour le projet othello
 * \author groupe 1.5
 * \version 1.0
 * \date 02/12/2015
 *
 */

#ifndef __FAIREUNEPARTIE__
#define __FAIREUNEPARTIE__
#include "FaireUnePartie_Prive.h"

/**
 * \brief FaireUnePartie regroupe la procedure faireUnePartie qui va permettre de jouer a l'othello
 *
 */

/**
 * \procedure faireUnePartie(void(*afficherPlateau)(Plateau), Coup(*getCoup)(Plateau,Pion), Coup(*getCoup)(Plateau,Pion), Couleur* joueur, int* estMatchNul)
 * \brief Procedure permettant de jouer au jeu de l'othello
 *
 * \param void(*afficherPlateau)(Plateau) POINTEUR sur une fonction qui permet d'afficher le plateau a chaque tour
 * \param Coup(*getCoup1)(Plateau,Pion) permet d'obtenir le coup du joueur 1
 * \param Coup(*getCoup2)(Plateau,Pion) permet d'obtenir le coup du joueur 2
 * \param  Couleur* joueur permet de determiner le gagnant de la partie
 * \param int* estMatchNul booléen qui permet de savoir si aucun joueur n'a gagné la partie ou il y'a un gagnant
 * \
 */


void faireUnePartie(void(*afficherPlateau)(Plateau), Coup(*getCoup1)(Plateau,Pion), Coup(*getCoup2)(Plateau,Pion), Couleur* joueur, int* estMatchNul);

#endif
