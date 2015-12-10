#ifndef __OBTENIR_COUP_IA_PRIVE__
#define __OBTENIR_COUP_IA_PRIVE__
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"


/* Récupération de la profondeur maximale d'exploration */
unsigned int profondeur(void);

/* Score associé à un coup joué par le joueur de la couleur couleurCourante */
int scoreDUnCoup(Plateau plateau, Coup coup, Couleur couleurRef, Couleur couleurCourante, unsigned int profondeurCourante);

/* Permet de "remonter" le score du meilleur coup dans l'arbre des possibilités de jeu */
int minMax(Plateau plateau, Couleur couleurRef, Couleur couleurCourante, unsigned int profondeurCourante);

/* Permet d'obtenir le score de la partie pour la couleur donnée en entrée */
int score(Plateau plateau, Couleur couleur);

/* Evaluation du plateau selon différentes règles de jeu et de priorité */
int evaluerPlateau(Plateau plateau, Couleur couleur);

/* Evaluation du nombre de coups possibles de l'adversaire*/
int evaluerNbCoupsPossiblesAdversaire(Plateau plateau, Couleur couleur);

/* Evaluation de la différence du nombre de pions possédés et du nombre de pions possédés par l'adversaire */
int evaluerNbPionsCouleur(Plateau plateau, Couleur couleur);

/* Evaluation du plateau selon la position des différents pions */
int evaluerPositionsPionsPlateau(Plateau plateau, Couleur couleur);

/* Initialisation de la grille qui attribue à chaque position un poids */
int[8][8] initialiserGrilleScore();

#endif
