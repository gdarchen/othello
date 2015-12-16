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
 * \procedure faireUnePartie(void(*afficherPlateau)(Plateau), Coup(*getCoup)(Plateau,Pion), Coup(*getCoup)(Plateau,Pion), Couleur* vainqueur, int* estMatchNul, Couleur couleurJoueur1)
 * \brief Procedure permettant de jouer au jeu de l'othello
 *
 * \param void(*afficherPlateau)(Plateau,Coup,int,int) POINTEUR sur une fonction qui permet d'afficher le plateau a chaque tour
 * \param Coup(*getCoup1)(Plateau,Pion) permet d'obtenir le coup du joueur 1
 * \param Coup(*getCoup2)(Plateau,Pion) permet d'obtenir le coup du joueur 2
 * \param Couleur* vaiqueur permet de determiner le gagnant de la partie
 * \param int* estMatchNul booléen qui permet de savoir si aucun joueur n'a gagné la partie ou il y'a un gagnant
 * \param Couleur couleurJoueur1 permet d'obtenir la couleur choisie par le joueur 1
 * \
 */


void faireUnePartie(void(*afficherPlateau)(Plateau,Coup,int,int), Coup(*getCoup1)(Plateau,Couleur), Coup(*getCoup2)(Plateau,Couleur), Couleur* vainqueur, int* estMatchNul, Couleur couleurJoueur1);

/**
 * \procedure void pionEstPresent(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
 * \brief Procedure qui permet de savoir si un pion est présent sur le plateau selon une direction, et si oui quelle est sa position
 *
 * \param Pion pionJoueur, le pion représentant le joueur
 * \param Direction dirATester, la direction à tester
 * \param Position* pos, la position initiale du pion qui, à la fin de l'exécution de la procédure, renvoit la position du pion trouvé
 * \param Plateau* plateau, le plateau de jeu
 * \param int* pionPresent, qui renvoit 0 si aucun pion conforme n'a été trouvé, 1 sinon
 * \
 */
void pionEstPresent(Pion pionJoueur, Direction dirATester, Position* pos, Plateau* plateau, int* pionPresent);

/**
 * \procedure void nbPions (Plateau plateau, unsigned int* scoreJoueur1, unsigned int* scoreJoueur2)
 * \brief Procedure qui permet de compter le nombre de pions des joueurs 1 et 2 sur le plateau
 *
 * \param Plateau plateau, le plateau de jeu
 * \param unsigned int* nbPionsBlancs, le nombre de pions Blanc
 * \param unsigned int* nbPionsNoirs, le nombre de pions Noirs
 * \
 */
void nbPions(Plateau plateau, unsigned int* nbPionsNoirs, unsigned int* nbPionsBlancs);

#endif
