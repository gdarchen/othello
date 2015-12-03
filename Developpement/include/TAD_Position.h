/**
 * \file TAD_POSITION.h
 * \brief Implantation du TAD Position pour le jeu Othello
 * \author Groupe 1.5
 * \version 1.0
 * \date 2/12/2015
 *
 */

#ifndef __TAD_POSITION__
#define __TAD_POSITION__

/**
 * \brief Le type Position permet de représenter une position sur le plateau
 *
 */

 typedef struct {
  unsigned int ligne; /**< l'indice de la ligne du plateau */
  unsigned int colonne; /**< l'indice' de la colonne du plateau */
} Position;

/**
 * \fn unsigned int POS_obtenirLigne(Position position)
 * \brief Fonction d'obtention de l'indice de la ligne
 *
 * \param Position position, la position dont on veut la ligne
* \return unsigned int
 */
unsigned int POS_obtenirLigne(Position position);

/**
 * \fn unsigned int POS_obtenirColonne(Position position)
 * \brief Fonction d'obtention de l'indice de la colonne
 *
 * \param Position position, la position dont on veut la colonne
* \return unsigned int
 */
unsigned int POS_obtenirColonne(Position position);

/**
 * \fn void POS_fixerPosition(unsigned int ligne, unsigned int colonne, Position* position)
 * \brief Fonction permettant de fixer une position en fonction de ses coordonnées
 *
 * \param unsigned int ligne, l'indice de la ligne
 * \param unsigned int colonne, l'indice de la colonne
 * \param Position* position, la position que l'on veut fixer
 */
void POS_fixerPosition(unsigned int ligne, unsigned int colonne, Position* position);

#endif
