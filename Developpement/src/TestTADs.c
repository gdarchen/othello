#include<stdlib.h>
#include<CUnit/Basic.h>
#include"GrilleJeuDeLaVie.h"
#include"JeuDeLaVie.h"
#include"JeuDeLaViePrive.h"
#define TRUE 1
#define FALSE 0

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}


//////////* On vérifie les axiomes des TADs *//////////

/* Tests relatifs au TAD Couleur */
void test_changerCouleur(void){
    CU_ASSERT_TRUE((CL_sontEgales(CL_changerCouleur(CL_noir()),CL_blanc()))
                && (CL_sontEgales(CL_changerCouleur(CL_blanc()),CL_noir())));
}


/* Tests relatifs au TAD Position */
void test_obtenirLigne(void){
    Position positionTest;
    unsigned int l,c;
    l = 3;
    c = 5;
    // la position (l,c) respectera les dimensions d'un plateau d'Othello
    CU_ASSERT_TRUE((POS_obtenirLigne(POS_fixerPosition(l,c,&positionTest))==l));
}

void test_obtenirColonne(void){
    Position positionTest;
    unsigned int l,c;
    l = 3;
    c = 5;
    // la position (l,c) respectera les dimensions d'un plateau d'Othello
    CU_ASSERT_TRUE((POS_obtenirColonne(POS_fixerPosition(l,c,&positionTest))==c));
}


/* Tests relatifs au TAD Pion */
void test_obtenirCouleur(void){
    CU_ASSERT_TRUE((CL_sontEgales(PI_obtenirCouleur(PI_creerPion(blanc())),blanc()))
                && (CL_sontEgales(PI_obtenirCouleur(PI_creerPion(noir()))==noir())));
}

void test_retournerPion(void){  // Axiome n.2 reformulé
    Pion pionTest;
    Couleur couleurAvant, couleurApres;
    couleurAvant = PI_obtenirCouleur(pionTest);
    couleurApres = PI_obtenirCouleur(PI_retournerPion(&pionTest));
    CU_ASSERT_TRUE(CL_sontEgales(couleurAvant,couleurApres));
}


/* Tests relatifs au TAD Coup */
void test_obtenirPositionCoup(void){
    Position positionTest;
    POS_fixerPosition(3,5,&positionTest);
    Pion pionTest;
    CU_ASSERT_TRUE(POS_sontEgales(CP_obtenirPositionCoup(CP_creerCoup(positionTest,pionTest)),positionTest));
}

void test_obtenirPionCoup(void){
    Position positionTest;
    Pion pionTest;
    pionTest = PI_creerPion(blanc());
    CU_ASSERT_TRUE(PI_sontEgaux(CP_obtenirPionCoup(CP_creerCoup(positionTest,pionTest)),pionTest));
}


/* Tests relatifs au TAD Coups */
void test_iemeCoup(void){
    Coup cp;
    Coups coupsTest;
    coupsTests = CPS_creerCoups();
    CPS_ajouterCoups(&coupsTest,cp);
    CU_ASSERT_TRUE(CP_sontEgaux(CPS_ieme(coupsTest,CPS_nbCoups(coupsTest)),cp));
}

void test_nbCoups(void){    // les 2 derniers axiomes du TAD Coups
    Coup coupTest;
    Coups coupsVide, coupsAjout;
    coupsVide = CPS_creerCoups();
    coupsAjout = CPS_creerCoups();
    CPS_ajouterCoups(&coupsAjout,coupsTest);
    CU_ASSERT_TRUE((CPS_nbCoups(coupsVide)==0)
                && (CPS_nbCoups(coupsAjout)==1));
}


/* Tests relatifs au TAD Plateau */



int main(int argc, char** argv){
  CU_pSuite pSuite = NULL;

  /* initialisation du registre de tests */
  if (CUE_SUCCESS != CU_initialize_registry())
    return CU_get_error();

  /* ajout d'une suite de test */
  pSuite = CU_add_suite("Tests boite noire : nb voisins", init_suite_success, clean_suite_success);
  if (NULL == pSuite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* Ajout des tests à la suite de tests boite noire */
  if ((NULL == CU_add_test(pSuite, "nb voisins d'une cellule morte", test_nb_voisins_general_morte))
      || (NULL == CU_add_test(pSuite, "nb voisins d'une cellule vivante", test_nb_voisins_general_vivante))
      || (NULL == CU_add_test(pSuite, "nb voisins dans un coin", test_nb_voisins_coin))
      )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Lancement des tests */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  printf("\n");
  CU_basic_show_failures(CU_get_failure_list());
  printf("\n\n");

  /* Nettoyage du registre */
  CU_cleanup_registry();
  return CU_get_error();
}
