/**
 * \file TAD_Coups.h
 * \brief Implantation du TAD Coups
 * \author Groupe 1.5
 * \version 1.0
 * \date 02/12/15
 *
 */

 #ifndef __TAD_COUPS__
 #define __TAD_COUPS__
 #include "TAD_Coup.h"
 #include "TAD_Couleur.h"

const int MAX_COUPS = 60;

/**
 * \brief Le type Coups permet de représenter un tableau de Coup
 *
 */
typedef Coup Coups[MAX_COUPS];

/**
 * \fn Coups CPS_creerCoups()
 * \brief Fonction qui retourne un Coups (tableau de Coup) vide
 *
 * \return Coups
 */
Coups CPS_creerCoups();

/**
 * \fn void CPS_ajouterCoups(Coups* coups, Coup coup)
 * \brief Fonction ajoute le Coup coup à la variable coups
 *
 * \param coups : un tableau de Coups
 * \param coup : le Coup à ajouter à coups
 */
void CPS_ajouterCoups(Coups* coups, Coup coup);

/**
 * \fn unsigned int CPS_nbCoups(Coups coups)
 * \brief Fonction qui renvoie le nombre de Coups d'une variable de type Coups
 *
 * \param coups : la variable dont on veut compter le nombre de Coups
 * \return unsigned int : le nombre de Coups
 */
unsigned int CPS_nbCoups(Coups coups);

/**
 * \fn Coup CPS_iemeCoup(Coups coups, unsigned int i)
 * \brief Fonction qui ieme Coup de la variable coups
 *
 * \param coups : la variable dont on veut obtenir le ieme Coup
 * \param i : indice du Coup à obtenir
 * \return unsigned int : le nombre de Coups
 */
Coup CPS_iemeCoup(Coups coups, unsigned int i);

 #endif
