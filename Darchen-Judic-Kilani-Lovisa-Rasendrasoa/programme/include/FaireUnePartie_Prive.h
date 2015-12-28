 /**
 * \file FaireUnePartie_Prive.h
 * \brief Implantation de faireunepartie-prive pour le projet othello
 * \author groupe 1.5
 * \version 1.0
 * \date 02/12/2015
 *
 */

#ifndef __FAIREUNEPARTIE_PRIVE__
#define __FAIREUNEPARTIE_PRIVE__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"
#include "TAD_Position.h"
#include "TAD_Pion.h"
#include "TAD_Coup.h"
#include "TAD_Coups.h"
#include "FaireUnePartie.h"

/**
 * \brief FaireUnePartie-prive regroupe seulement les fonctions et procédures qu'on va utiliser dans FAIREUNEPARTIE
 *
 */


 /* Introduction d'un type privé Direction */

 typedef enum {GAUCHE,DROITE,HAUT,BAS,DIAGGH,DIAGGB,DIAGDH,DIAGDB} Direction;

 Position DIR_positionSelonDirection(Position posInit, Direction dirDeplacement);
 Direction DIR_inverserDirection(Direction dirInit);
 int DIR_deplacementValide(Position pos, Direction dirDeplacement);





/**
 * \fn Plateau InitialiserPlateau()
 * \brief Procedure permettant d'initialiser le plateau (place quatre pions au centre)
 *
 * \
 */
void initialiserPlateau(Plateau *plateau);

/**
 * \fn void jouer(Plateau* plateau , Couleur* couleurJoueur, GETCOUP(*obtenirCoupJoueur)(Plateau,Couleur,Coup), int* aPuJouer)
 * \brief Procedure qui permet à un joueur de jouer
 *
 * \param Plateau* plateau, le plateau de l'othello
 * \param Couleur* couleurJoueur, la couleur du joueur qui joue le tour
 * \param GETCOUP(*obtenirCoupJoueur)(Plateau,Couleur,Coup), permet d'obtenir le coup du joueur
 * \param int* aPuJouer, booleen qui permet de savoir si le joueur a pu placer son pion ou pas.
 * \param Coup* coupJoueur, le coup choisi et joué
 * \
 */
void jouer(Plateau* plateau , Couleur* couleurJoueur, Coup(*obtenirCoupJoueur)(Plateau,Couleur), int* aPuJouer, Coup* coupJoueur);


/**
 * \fn void jouerCoup (Coup coup, Plateau* plateau)
 * \brief Procedure qui permet de jouer un coup sur le plateau
 *
 * \param Coup coup , le coup que le joueur souhaite jouer
 * \param Plateau* plateau, le plateau de l'othello
 * \
 */
void jouerCoup(Coup coup, Plateau* plateau);

/**
 * \fn void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau)
 * \brief Procedure qui permet de retourner les pions dans toutes les directions si possible, après le coup
 *
 * \param Position pos, la position du coup
 * \param Pion pionJoueur, le pion du coup
 * \param  Plateau* plateau, le plateau sur lequel est joué le coup
 * \
 */
void inverserPions(Position pos, Pion pionJoueur, Plateau* plateau);

/**
 * \fn inverserPionsDir(Plateau* plateau, Position posInitiale, Position posCourante, Direction dirInversion);
 * \brief Procedure qui permet de retourner les pions sur le plateau selon une direction donnée
 *
 * \param Plateau* plateau, le plateau de jeu
 * \param Position posInitiale, la position du coup joué
 * \param Position posCourante, la position courante sur le plateau
 * \param  Direction dirInversion, la direction d'inversion
 * \
 */
void inverserPionsDir(Plateau* plateau, Position posInitiale, Position posCourante, Direction dirInversion);

/**
 * \fn void pionEstPresentRecursif(Pion pionJoueur, Direction dirATester, Position* pos, Plateau* plateau, int* pionPresent);
 * \brief Procedure qui permet de savoir si un pion est présent sur le plateau selon une direction, et si oui quelle est sa position, de manière récursive à partir de la case à côté de la position initiale
 *
 * \param Pion pionJoueur, le pion représentant le joueur
 * \param Direction dirATester, la direction de recherche
 * \param Position* pos, la position initiale du pion qui, à la fin de l'exécution de la procédure, renvoit la position du pion trouvé
 * \param Plateau* plateau, le plateau de jeu
 * \param int* pionPresent, qui renvoit 0 si aucun pion conforme n'a été trouvé, 1 sinon
 * \
 */
void pionEstPresentRecursif(Pion pionJoueur, Direction dirATester, Position* pos, Plateau* plateau, int* pionPresent);
/**
 * \fn finPartie (Plateau plateau, int aPuJouerJoueur1,aPuJouerJoueur2 , unsigned int* scoreJoueur1, unsigned int* scoreJoueur2 , int* estFinie)
 * \brief Procedure qui permet de déterminer si la partie est finie ou non.
 *
 * \param Plateau plateau, le plateau de jeu
 * \param int aPuJouerJoueur1, 1 si le joueur 1 a pu jouer à son dernier tour, 0 sinon
 * \param int aPuJouerJoueur2, 1 si le joueur 2 a pu jouer à son dernier tour, 0 sinon
 * \param int* nbPionsBlancs, le nombre de pions Blanc
 * \param int* nbPionsNoirs, le nombre de pions Noirs
 * \param int* estFinie, 1 si la partie est finie, 0 sinon
 * \
 */

void finPartie (Plateau plateau, int aPuJouerJoueur1, int aPuJouerJoueur2 , int* nbPionsNoirs, int* nbPionsBlancs , int* estFinie);

/** 
 * \fn int plateauRempli (Plateau plateau)
 * \brief Fonction qui renvoie un booléen indiquant si le plateau est rempli ou non.
 *
 * \param Plateau plateau, le plateau à tester.
 * \return int, le booléen indiquant si le plateau est rempli.
 */
int plateauRempli(Plateau plateau);



#endif
