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
#include "FaireUnePartie.h"
#include "FaireUnePartie.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

/* Tests relatifs à initialiserPlateau */

void test_initialiserPlateau(void){
  Plateau plateau;
  int res=1;
  Position pos;
  unsigned int i,j;
  plateau=PL_creerPlateau();
  plateau=initialiserPlateau();

  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      POS_fixerPosition(i,j,&pos);
      if ((i==3 && j==3) || (i==4 && j==4)){
        if (PL_estCaseVide(plateau,pos)){
          res=0;
        }
        else if(CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),CL_blanc())){
          res=0;
        }
      }
      else if ((i==3 && j==4) || (i==4 && j==3)){
        if (PL_estCaseVide(plateau,pos)){
          res=0;
        }
        else if(CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),CL_noir())){
          res=0;
        }
      }
      else{
        if (!PL_estCaseVide(plateau,pos)){
          res=0;
        }
      }
    }
  } /* PAS FINI !*/

  CU_ASSERT_TRUE(res==1);
}

int main(int argc, char** argv){
    CU_pSuite pSuite_initialiserPlateau;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout des suites de tests */
    pSuite_initialiserPlateau = CU_add_suite("Tests boite noire : copierPlateau", init_suite_success, clean_suite_success);
    if ((NULL == pSuite_initialiserPlateau)
        /*|| (NULL == pSuite_coupValide)
        || (NULL == pSuite_listeCoupsPossibles)*/
        ){
    CU_cleanup_registry();
    return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite_initialiserPlateau, "Plateau de départ", test_initialiserPlateau))
        /*|| (NULL == CU_add_test(pSuite_copierPlateau, "Pions sur les bords", test_copierPlateauBords))
        || (NULL == CU_add_test(pSuite_copierPlateau, "Pions dans les coins", test_copierPlateauCoins))
        || (NULL == CU_add_test(pSuite_coupValide, "Pion entouré de cases vides", test_coupValideEntoureCasesVides))
        || (NULL == CU_add_test(pSuite_coupValide, "Pion entouré de cases de même couleur", test_coupValideEntoureCasesMemeCouleur))
        || (NULL == CU_add_test(pSuite_coupValide, "Pion entouré de cases de l'autre couleur mais vides après", test_coupValideQueCasesAutreCouleurPuisVide))
        || (NULL == CU_add_test(pSuite_coupValide, "Coup valide, pos initiale dans un coin", test_coupValideCoin))
        || (NULL == CU_add_test(pSuite_coupValide, "Coup valide, pos initiale quelconque", test_coupValideQuelconque))
        || (NULL == CU_add_test(pSuite_listeCoupsPossibles, "Liste des coups possibles au début de jeu", test_listeCoupsPossibles))
        || (NULL == CU_add_test(pSuite_listeCoupsPossibles, "Liste de coups possibles vide", test_listeCoupsPossiblesPlateauVide))*/
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
