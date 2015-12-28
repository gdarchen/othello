/**
 * \file TAD_Couleur.h
 * \brief Implantation du TAD Couleur
 * \author Groupe 1.5
 * \version 1.0
 * \date 02/12/15
 *
 */

 #ifndef __TAD_COULEUR__
 #define __TAD_COULEUR__

/**
 * \brief Le type Couleur représente les deux couleurs possibles
 *
 */
typedef enum{BLANC,NOIR} Couleur;

/**
 * \fn Couleur CL_blanc()
 * \brief Fonction qui retourne la couleur 'blanc'
 *
 * \return Couleur
 */
Couleur CL_blanc();

/**
 * \fn Couleur CL_noir()
 * \brief Fonction qui retourne la couleur 'noir'
 *
 * \return Couleur
 */
Couleur CL_noir();

/**
 * \fn Couleur CL_changerCouleur(couleur : Couleur)
 * \brief Fonction qui retourne l'autre couleur que celle passée en paramètre d'entrée
 *
 * \param Couleur couleur : Couleur, la couleur à changer
 * \return Couleur
 */
Couleur CL_changerCouleur(Couleur couleur);

/**
 * \fn CL_sontEgales
 * \brief Fonction testant l'égalité de deux couleurs
 *
 * \param Couleur couleur1
 * \param Couleur couleur2
 * \return int (Booleen)
 */
int CL_sontEgales(Couleur couleur1, Couleur couleur2);



 #endif
