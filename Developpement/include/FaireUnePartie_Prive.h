/**
 * \file FaireUnePartie_Prive.h
 * \brief Implantation de faireunepartie-prive pour le projet othello
 * \author groupe 1.5
 * \version 1.0
 * \date 02/12/2015
 *
 */

#ifndef __FAIREUNEPARTIE__
#define __FAIREUNEPARTIE__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Position.h"
#include "TAD_Pion.h"

/**
 * \brief FaireUnePartie-prive regroupe seulement les fonctions et procédures qu'on va utiliser dans FAIREUNEPARTIE
 *
 */

 /**
  * \procedure void faireUnePartie(void(*afficherPlateau)(Plateau), GETCOUP(*obtenirCoupJoueur1)(Plateau,Couleur,Coup), GETCOUP(*obtenirCoupJoueur2)(Plateau,Couleur,Coup), Couleur* joueur, int* estMatchNul)
  * \brief Procedure permettant de faire une partie d'othello
  *
  * \param void(*afficherPlateau)(Plateau), fonction d'affichage du plateau
  * \param GETCOUP(*obtenirCoupJoueur1)(Plateau,Couleur,Coup) et GETCOUP(*obtenirCoupJoueur2)(Plateau,Couleur,Coup), fonctions d'obtentions des coups des joueurs 1 et 2
  * \param Couleur* joueur, donne la couleur du joueur gagnant si il y en a un
  * \param int* estMatchNul, permet de savoir si la partie s'est finie sur un match nul ou pas
 * \
  */
void faireUnePartie(void(*afficherPlateau)(Plateau), GETCOUP(*obtenirCoupJoueur1)(Plateau,Couleur,Coup), GETCOUP(*obtenirCoupJoueur2)(Plateau,Couleur,Coup), Couleur* joueur, int* estMatchNul)

/**
 * \procedure Plateau InitialiserPlateau()
 * \brief Procedure permettant d'initialiser le plateau (place quatre pions au centre)
 *
* \
 */
Plateau InitialiserPlateau()

/**
 * \procedure void jouer(Plateau* plateau , Couleur* couleurJoueur, GETCOUP(*obtenirCoupJoueur)(Plateau,Couleur,Coup), int* aPuJouer)
 * \brief Procedure qui permet à un joueur de jouer
 *
 * \param Plateau* plateau, le plateau de l'othello
 * \param Couleur* couleurJoueur, la couleur du joueur qui joue le tour
 * \param GETCOUP(*obtenirCoupJoueur)(Plateau,Couleur,Coup), permet d'obtenir le coup du joueur
 * \param int* aPuJouer, booleen qui permet de savoir si le joueur a pu placer son pion ou pas.
* \
 */
void jouer(Plateau* plateau , Couleur* couleurJoueur, GETCOUP(*obtenirCoupJoueur)(Plateau,Couleur,Coup), int* aPuJouer)


/**
 * \procedure void jouerCoup (Coup coup, Plateau* plateau)
 * \brief Procedure qui permet de jouer un coup sur le plateau
 *
 * \param Coup coup , le coup que le joueur souhaite jouer
 * \param Plateau* plateau, le plateau de l'othello
* \
 */
void jouerCoup (Coup coup, Plateau* plateau)

/**
 * \procedure void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau)
 * \brief Procedure qui permet de retourner les pions dans toutes les directions si possible, après le coup
 *
 * \param Position pos, la position du coup
 * \param Pion pionJoueur, le pion du coup
 * \param  Plateau* plateau, le plateau sur lequel est joué le coup
* \
 */
void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau)

/**
 * \procedure void inverserPionsDir(Plateau* plateau, Position posInitiale, Position posCourante, unsigned int x, unsigned int y)
 * \brief Procedure qui permet de retourner les pions sur le plateau selon une direction donnée
 *
 * \param Plateau* plateau, le plateau de jeu
 * \param Position posInitiale, la position du coup joué
 * \param Position posCourante, la position courante sur le plateau
 * \param unsigned int x, la direction selon l'axe des abscisses
 * \param unsigned int y, la direction selon l'axe des ordonnées
* \
 */
void inverserPionsDir(Plateau* plateau, Position posInitiale, Position posCourante, unsigned int x, unsigned int y)

/**
 * \procedure void pionEstPresent(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
 * \brief Procedure qui permet de savoir si un pion est présent sur le plateau selon une direction, et si oui quelle est sa position
 *
 * \param Pion pionJoueur, le pion représentant le joueur
 * \param unsigned int x, la direction selon l'axe des abscisses
 * \param unsigned int y, la direction selon l'axe des ordonnées
 * \param Position* pos, la position initiale du pion qui, à la fin de l'exécution de la procédure, renvoit la position du pion trouvé
 * \param Plateau* plateau, le plateau de jeu
* \param int* pionPresent, qui renvoit 0 si aucun pion conforme n'a été trouvé, 1 sinon
* \
 */
void pionEstPresent(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)

/**
 * \procedure void pionEstPresentRecursif(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)
 * \brief Procedure qui permet de savoir si un pion est présent sur le plateau selon une direction, et si oui quelle est sa position, de manière récursive à partir de la case à côté de la position initiale
 *
 * \param Pion pionJoueur, le pion représentant le joueur
 * \param unsigned int x, la direction selon l'axe des abscisses
 * \param unsigned int y, la direction selon l'axe des ordonnées
 * \param Position* pos, la position initiale du pion qui, à la fin de l'exécution de la procédure, renvoit la position du pion trouvé
 * \param Plateau* plateau, le plateau de jeu
* \param int* pionPresent, qui renvoit 0 si aucun pion conforme n'a été trouvé, 1 sinon
* \
 */
void pionEstPresentRecursif(Pion pionJoueur, unsigned int x, unsigned int y, Position* pos, Plateau* plateau, int* pionPresent)

/**
 * \procedure finPartie (Plateau plateau, int aPuJouerJoueur1,aPuJouerJoueur2 , unsigned int* scoreJoueur1, unsigned int* scoreJoueur2 , int* estFinie)
 * \brief Procedure qui permet de déterminer si la partie est finie ou non.
 *
 * \param Plateau plateau, le plateau de jeu
 * \param int aPuJouerJoueur1, 1 si le joueur 1 a pu jouer à son dernier tour, 0 sinon
 * \param int aPuJouerJoueur2, 1 si le joueur 2 a pu jouer à son dernier tour, 0 sinon
 * \param unsigned int* scoreJoueur1, le score du joueur 1
 * \param unsigned int* scoreJoueur2, le score du joueur 2
 * \param int* estFinie, 1 si la partie est finie, 0 sinon
* \
 */
void finPartie (Plateau plateau, int aPuJouerJoueur1, int aPuJouerJoueur2 , unsigned int* scoreJoueur1, unsigned int* scoreJoueur2 , int* estFinie)

/**
 * \procedure void nbPions (Plateau plateau, unsigned int* scoreJoueur1, unsigned int* scoreJoueur2)
 * \brief Procedure qui permet de compter le nombre de pions des joueurs 1 et 2 sur le plateau
 *
 * \param Plateau plateau, le plateau de jeu
 * \param unsigned int* scoreJoueur1, le nombre de pions du joueur 1
 * \param unsigned int* scoreJoueur2, le nombre de pions du joueur 2
* \
 */
void nbPions (Plateau plateau, unsigned int* scoreJoueur1, unsigned int* scoreJoueur2)
