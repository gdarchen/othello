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
 #include "TAD_Position.h"
 #include "TAD_Pion.h"

/**
 * \brief Le type Coup permet de représenter le coup d'un joueur, en regroupant une position (sur le plateau) et un pion
 *
 */
typedef struct {
  Position position; /**< la largeur de la grille */
  Pion pion; /**< la hauteur de la grille */
} Coup;

/**
 * \fn Coup CP_creerCoup(Position position, Pion pion)
 * \brief Fonction qui retourne un coup à partir d'une position et d'un pion
 *
 * \return Coup
 */
Coup CP_creerCoup(Position position, Pion pion);

/**
 * \fn Position CP_obtenirPositionCoup(Coup coup)
 * \brief Fonction qui retourne la position d'un coup
 *
 * \param position : la position à affecter au Coup
 * \param pion : le Pion à affecter au Coup
 * \return Coup
 */
Position CP_obtenirPositionCoup(Coup coup);

/**
 * \fn Position CP_obtenirPionCoup(Coup coup)
 * \brief Fonction qui retourne le pion d'un coup
 *
 * \return Coup
 */
Pion CP_obtenirPionCoup(Coup coup);


 #endif
