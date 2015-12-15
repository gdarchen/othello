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
    POS_fixerPosition(l,c,&positionTest);
    // la position (l,c) respectera les dimensions d'un plateau d'Othello
    CU_ASSERT_TRUE((POS_obtenirLigne(positionTest)==l));
}

void test_obtenirColonne(void){
    Position positionTest;
    unsigned int l,c;
    l = 3;
    c = 5;
    POS_fixerPosition(l,c,&positionTest);
    // la position (l,c) respectera les dimensions d'un plateau d'Othello
    CU_ASSERT_TRUE(POS_obtenirColonne(positionTest)==c);
}


/* Tests relatifs au TAD Pion */
void test_obtenirCouleur(void){
    CU_ASSERT_TRUE((CL_sontEgales(PI_obtenirCouleur(PI_creerPion(CL_blanc())),CL_blanc()))
                && (CL_sontEgales(PI_obtenirCouleur(PI_creerPion(CL_noir())),CL_noir())));
}

void test_retournerPion(void){  // Axiome 2 reformulé
    Couleur couleurAvant, couleurApres;
    Pion pionTest = PI_creerPion(CL_blanc());
    couleurAvant = PI_obtenirCouleur(pionTest);
    PI_retournerPion(&pionTest);
    couleurApres = PI_obtenirCouleur(pionTest);
    CU_ASSERT_TRUE(!CL_sontEgales(couleurAvant,couleurApres));
}


/* Tests relatifs au TAD Coup */
void test_obtenirPositionCoup(void){
    Position positionTest;
    POS_fixerPosition(3,5,&positionTest);
    Pion pionTest = PI_creerPion(CL_blanc());
    CU_ASSERT_TRUE(POS_sontEgales(CP_obtenirPositionCoup(CP_creerCoup(positionTest,pionTest)),positionTest));
}

void test_obtenirPionCoup(void){
    Position positionTest;
    Pion pionTest;
    pionTest = PI_creerPion(CL_blanc());
    CU_ASSERT_TRUE(PI_sontEgaux(CP_obtenirPionCoup(CP_creerCoup(positionTest,pionTest)),pionTest));
}
 //

/* Tests relatifs au TAD Coups */
void test_iemeCoup(void){
    Position positionTest;
    Coup cp;
    Coups coupsTest;
    POS_fixerPosition(0,0,&positionTest);
    cp = CP_creerCoup(positionTest,PI_creerPion(CL_blanc()));
    CPS_creerCoups(&coupsTest);
    CPS_ajouterCoups(&coupsTest,cp);
    CU_ASSERT_TRUE(CP_sontEgaux(CPS_iemeCoup(coupsTest,CPS_nbCoups(coupsTest)-1),cp));
}

void test_nbCoups(void){    // les 2 derniers axiomes du TAD Coups
    Coup coupTest;
    Coups coupsVide, coupsAjout;
    CPS_creerCoups(&coupsVide);
    CPS_creerCoups(&coupsAjout);
    CPS_ajouterCoups(&coupsAjout,coupTest);
    CU_ASSERT_TRUE((CPS_nbCoups(coupsVide)==0)
                && (CPS_nbCoups(coupsAjout)==1));
}


/* Tests relatifs au TAD Plateau */
void test_estCaseVide(void){
    Plateau plateauTest;
    Position positionCaseVide, positionCaseAVider, positionCaseNonVide;
    plateauTest=PL_creerPlateau();
    Pion pionTest=PI_creerPion(CL_blanc());
    POS_fixerPosition(0,0,&positionCaseVide);
    POS_fixerPosition(0,1,&positionCaseAVider);
    POS_fixerPosition(1,0,&positionCaseNonVide);
    PL_poserPion(&plateauTest,positionCaseAVider,pionTest);
    PL_viderCase(&plateauTest,positionCaseAVider);
    PL_poserPion(&plateauTest,positionCaseNonVide,pionTest);
    CU_ASSERT_TRUE( (PL_estCaseVide(plateauTest,positionCaseVide))   // Axiome 1
                && (PL_estCaseVide(plateauTest,positionCaseAVider)) // Axiome 2
                && !(PL_estCaseVide(plateauTest,positionCaseNonVide))); // Axiome 3
}

void test_obtenirPion(void){
    Plateau plateauTest;
    Pion pionTest;
    Position positionTest;
    POS_fixerPosition(0,0,&positionTest);
    pionTest = PI_creerPion(CL_blanc());
    PL_poserPion(&plateauTest,positionTest,pionTest);
    CU_ASSERT_TRUE(PI_sontEgaux(PL_obtenirPion(plateauTest,positionTest),pionTest));
}

void test_inverserPion(void){
    Plateau plateauTest;
    Pion pionTest;
    Position positionTest;
    POS_fixerPosition(0,0,&positionTest);
    pionTest = PI_creerPion(CL_blanc());
    PL_poserPion(&plateauTest,positionTest,pionTest);
    PL_inverserPion(&plateauTest,positionTest);
    PI_retournerPion(&pionTest);
    CU_ASSERT_TRUE(PI_sontEgaux(PL_obtenirPion(plateauTest,positionTest),pionTest));
}



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
