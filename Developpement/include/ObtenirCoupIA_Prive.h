#ifndef OBTENIR_COUP_IA_PRIVE
#define OBTENIR_COUP_IA_PRIVE
#include "TAD_Plateau.h"
#include "TAD_Couleur.h"


/* Récupération de la profondeur maximale d'exploration */
unsigned int profondeur(void);

/* Score associé à un coup joué par le joueur de la couleur couleurCourante */
int scoreDUnCoup(Plateau plateau, Couleur couleurRef, Couleur couleurCourante, unsigned int profondeurCourante);

/* Permet de "remonter" le score du meilleur coup dans l'arbre des possibilités de jeu */
int minMax(Plateau plateau, Couleur couleurRef, Couleur couleurCourante, int profondeurCourante);

/* Permet d'obtenir le score de la partie pour la couleur donnée en entrée */
int score(Plateau plateau, Couleur couleur);

/* Evaluation du plateau selon différentes règles de jeu et de priorité */
int evaluerPlateau(Plateau plateau, Couleur couleur);

#endif
