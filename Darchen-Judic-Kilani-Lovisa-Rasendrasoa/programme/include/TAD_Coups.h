/**
 * \file TAD_Coups.h
 * \brief Implantation du TAD Coups
 * \author Groupe 1.5
 * \version 1.0
 * \date 02/12/15
 *
 */

#define MAX_COUPS 60

 #ifndef __TAD_COUPS__
 #define __TAD_COUPS__
 #include "TAD_Coup.h"
 #include "TAD_Couleur.h"



/**
 * \struct Coups
 * \brief Le type Coups permet de représenter un tableau de Coup et le nombre de Coup possibles
 *
 */

typedef struct {
	Coup tabCoups[MAX_COUPS];
	unsigned int nbCps;
} Coups;

/**
 * \fn Coups CPS_creerCoups()
 * \brief Fonction qui retourne un Coups (tableau de Coup) vide
 *
 * \return Coups
 */
void CPS_creerCoups(Coups* coups);

/**
 * \fn void CPS_ajouterCoups(Coups* coups, Coup coup)
 * \brief Fonction ajoute le Coup coup à la variable coups
 *
 * \param Coups* coups : un tableau de Coups
 * \param Coup coup : le Coup à ajouter à coups
 */
void CPS_ajouterCoups(Coups* coups, Coup coup);

/**
 * \fn unsigned int CPS_nbCoups(Coups coups)
 * \brief Fonction qui renvoie le nombre de Coups d'une variable de type Coups
 *
 * \param Coups coups : la variable dont on veut compter le nombre de Coups
 * \return unsigned int : le nombre de Coups
 */
unsigned int CPS_nbCoups(Coups coups);

/**
 * \fn Coup CPS_iemeCoup(Coups coups, unsigned int i)
 * \brief Fonction qui ieme Coup de la variable coups
 *
 * \param Coups coups : la variable dont on veut obtenir le ieme Coup
 * \param unsigned int i : indice du Coup à obtenir
 * \return Coup : le nombre de Coups
 */
Coup CPS_iemeCoup(Coups coups, unsigned int i);

 #endif
