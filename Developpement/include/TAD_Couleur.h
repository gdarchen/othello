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
typedef enum{'blanc','noir'} Couleur;

/**
 * \fn Couleur COULEUR_blanc()
 * \brief Fonction qui retourne la couleur 'blanc'
 *
 * \return Couleur
 */
Couleur COULEUR_blanc();

/**
 * \fn Couleur COULEUR_noir()
 * \brief Fonction qui retourne la couleur 'noir'
 *
 * \return Couleur
 */
Couleur COULEUR_noir();

/**
 * \fn Couleur COULEUR_changerCouleur(couleur : Couleur)
 * \brief Fonction qui retourne l'autre couleur que celle passée en paramètre d'entrée
 *
 * \param couleur : Couleur, la couleur à changer
 * \return Couleur
 */
Couleur COULEUR_changerCouleur(couleur : Couleur);


 #endif