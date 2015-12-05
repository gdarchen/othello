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
 * \procedure faireUnePartie(void(*afficherPlateau)(Plateau), GETCOUP(*obtenirCoupJoueur1)(Plateau,Couleur,Coup), GETCOUP(*obtenirCoupJoueur2)(Plateau,Couleur,Coup), Couleur* joueur, int* estMatchNul)
 * \brief Procedure permmettant de jouer au jeu de l'othello
 *
 * \param void(*afficherPlateau)(Plateau) POINTEUR sur une fonction qui permet d'afficher le plateau a chaque tour
 * \param GETCOUP(*obtenirCoupJoueur1)(Plateau,Couleur,Coup) permer d'obtenir le coup du joueur 1
 * \param GETCOUP(*obtenirCoupJoueur2)(Plateau,Couleur,Coup) permet d'obtenir le coup du joueur 2
 * \param  Couleur* joueur permet de determiner le gagnant de la partie
 * \param int* estMatchNul booléen qui permet de savoir si aucun joueur n'a gagné la partie ou il y'a un gagnant
 * \
 */


void faireUnePartie(void(*afficherPlateau)(Plateau), GETCOUP(*obtenirCoupJoueur1)(Plateau,Couleur,Coup), GETCOUP(*obtenirCoupJoueur2)(Plateau,Couleur,Coup), Couleur* joueur, int* estMatchNul)
