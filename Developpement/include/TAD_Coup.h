/**
 * \file TAD_Coup.h
 * \brief Implantation du TAD Coup
 * \author Groupe 1.5
 * \version 1.0
 * \date 02/12/15
 *
 */

 #ifndef __TAD_COUP__
 #define __TAD_COUP__
 #include "TAD_Position"
 #include "TAD_Pion"

/**
 * \brief Le type Coup permet de représenter le coup d'un joueur, en regroupant une position (sur le plateau) et un pion
 *
 */
typedef struct {
  Position position; /**< la largeur de la grille */
  Pion pion; /**< la hauteur de la grille */
} Coup;

/**
 * \fn Coup COUP_creerCoup(Position position, Pion pion)
 * \brief Fonction qui retourne un coup à partir d'une position et d'un pion
 *
 * \return Coup
 */
Coup COUP_creerCoup(Position position, Pion pion);

/**
 * \fn Position COUP_obtenirPositionCoup(Coup coup)
 * \brief Fonction qui retourne la position d'un coup
 *
 * \param position : la position à affecter au Coup
 * \param pion : le Pion à affecter au Coup
 * \return Coup
 */
Position COUP_obtenirPositionCoup(Coup coup);

/**
 * \fn Position COUP_obtenirPionCoup(Coup coup)
 * \brief Fonction qui retourne le pion d'un coup
 *
 * \return Coup
 */
Pion COUP_obtenirPionCoup(Coup coup);


 #endif
