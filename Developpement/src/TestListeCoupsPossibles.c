#include <stdlib.h>
#include <CUnit/Basic.h>
#define TRUE 1
#define FALSE 0
#include "TAD_Couleur.h"
#include "TAD_Couleur.h"
#include "TAD_Pion.h"
#include "TAD_Coup.h"
#include "TAD_Coups.h"
#include "TAD_Plateau.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

/* Tests relatifs à copierPlateau */

void test_copierPlateau(void){
  Plateau plateau1,plateau2;
    plateau1=PL_creerPlateau();
    plateau2=PL_creerPlateau();
    Pion pion=CL_noir();
    Position positionMilieu, positionBord, positionCoin1, positionCoin2;

    POS_fixerPosition(4,3,&positionMilieu);
    POS_fixerPosition(0,5,&positionBord);
    POS_fixerPosition(0,0,&positionCoin1);
    POS_fixerPosition(7,0,&positionCoin2);

    PL_poserPion(&plateau1,positionMilieu,pion);
    PL_poserPion(&plateau1,positionBord,pion);
    PL_poserPion(&plateau1,positionCoin1,pion);
    PL_poserPion(&plateau1,positionCoin2,pion);

    plateau2=copierPlateau(plateau1);

    CU_ASSERT_TRUE( PL_obtenirPion(plateau2,positionMilieu)==pion && !(PL_estCaseVide(plateau2,positionMilieu))
      && PL_obtenirPion(plateau2,positionBord)==pion && !(PL_estCaseVide(plateau2,positionBord))
      && PL_obtenirPion(plateau2,positionCoin1)==pion && !(PL_estCaseVide(plateau2,positionCoin1))
      && PL_obtenirPion(plateau2,positionCoin2)==pion && !(PL_estCaseVide(plateau2,positionCoin2)));
}



/* A MODIFIER - COPIER COLLER DES TESTS DES TAD*/
int main(int argc, char** argv){
    CU_pSuite pSuite_Couleur;
    CU_pSuite pSuite_Position;
    CU_pSuite pSuite_Pion;
    CU_pSuite pSuite_Coup;
    CU_pSuite pSuite_Coups;
    CU_pSuite pSuite_Plateau;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout des suites de tests */
    pSuite_Couleur = CU_add_suite("Tests boite noire : TAD Couleur", init_suite_success, clean_suite_success);
    pSuite_Position = CU_add_suite("Tests boite noire : TAD pSuite_Position", init_suite_success, clean_suite_success);
    pSuite_Pion = CU_add_suite("Tests boite noire : TAD Pion", init_suite_success, clean_suite_success);
    pSuite_Coup = CU_add_suite("Tests boite noire : TAD Coup", init_suite_success, clean_suite_success);
    pSuite_Coups = CU_add_suite("Tests boite noire : TAD Coups", init_suite_success, clean_suite_success);
    pSuite_Plateau = CU_add_suite("Tests boite noire : TAD Plateau", init_suite_success, clean_suite_success);
    if ((NULL == pSuite_Couleur)
        || (NULL == pSuite_Position)
        || (NULL == pSuite_Coup)
        || (NULL == pSuite_Coups)
        || (NULL == pSuite_Pion)
        || (NULL == pSuite_Plateau)
        ){
    CU_cleanup_registry();
    return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite_Couleur, "CL_changerCouleur", test_changerCouleur))
        || (NULL == CU_add_test(pSuite_Position, "POS_obtenirLigne", test_obtenirLigne))
        || (NULL == CU_add_test(pSuite_Position, "POS_obtenirColonne", test_obtenirColonne))
        || (NULL == CU_add_test(pSuite_Pion, "PI_obtenirCouleur", test_obtenirCouleur))
        || (NULL == CU_add_test(pSuite_Pion, "PI_retournerPion", test_retournerPion))
        || (NULL == CU_add_test(pSuite_Coup, "CP_obtenirPositionCoup", test_obtenirPositionCoup))
        || (NULL == CU_add_test(pSuite_Coup, "CP_obtenirPionCoup", test_obtenirPionCoup))
        || (NULL == CU_add_test(pSuite_Coups, "CPS_iemeCoup", test_iemeCoup))
        || (NULL == CU_add_test(pSuite_Coups, "CPS_nbCoups", test_nbCoups))
        || (NULL == CU_add_test(pSuite_Plateau, "PL_estCaseVide", test_estCaseVide))
        || (NULL == CU_add_test(pSuite_Plateau, "PL_obtenirPion", test_obtenirPion))
        || (NULL == CU_add_test(pSuite_Plateau, "PL_inverserPion", test_inverserPion))
        ){
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
