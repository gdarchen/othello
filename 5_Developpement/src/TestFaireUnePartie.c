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
  unsigned int i,j,x,y;
  plateau=PL_creerPlateau();
  plateau=initialiserPlateau();

  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      x=i-1;
      y=j-1;
      POS_fixerPosition(x,y,&pos);
      if ((x==3 && y==3) || (x==4 && y==4)){
        if (PL_estCaseVide(plateau,pos)){
          res=0;
        }
        else if(CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),CL_blanc())){
          res=0;
        }
      }
      else if ((x==3 && y==4) || (x==4 && y==3)){
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
  }
  CU_ASSERT_TRUE(res==TRUE);
}

/* Tests relatifs à plateauRempli */
void test_plateauRempliVrai(void){
  unsigned int i,j,x,y;
  Position position;
  Pion pion=CL_noir();
  Plateau plateau;
  plateau=PL_creerPlateau();
  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      x=i-1;
      y=j-1;
      POS_fixerPosition(x, y, &position);
      PL_poserPion(&plateau,position,pion);
    }
  }
  CU_ASSERT_TRUE(plateauRempli(plateau)==TRUE);
}

void test_plateauRempliFaux(void){
  Plateau plateau;
  plateau=PL_creerPlateau();
  plateau=initialiserPlateau();

  CU_ASSERT_TRUE(plateauRempli(plateau)==FALSE);
}

/* Tests relatifs à nbPions */

void test_nbPionsPlateauRempli(void){
unsigned int i,j,x,y;
unsigned int nbPionsNoirs,nbPionsBlancs;
Position position;
Pion pion=CL_noir();
Plateau plateau;
plateau=PL_creerPlateau();
for(i=1;i<9;i++){
  for(j=1;j<9;j++){
    x=i-1;
    y=j-1;
    POS_fixerPosition(x, y, &position);
    PL_poserPion(&plateau,position,pion);
  }
}
CU_ASSERT_TRUE((nbPionsBlancs==0) && (nbPionsNoirs==64));
}

void test_nbPionsPlateauInitial(void){
  Plateau plateau;
  unsigned int nbPionsNoirs,nbPionsBlancs;
  plateau=PL_creerPlateau();
  plateau=initialiserPlateau();
  nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);

  CU_ASSERT_TRUE((nbPionsBlancs==2) && (nbPionsNoirs==2));
}


int main(int argc, char** argv){
    CU_pSuite pSuite_initialiserPlateau;
    CU_pSuite pSuite_plateauRempli;
    CU_pSuite pSuite_nbPions;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout des suites de tests */
    pSuite_initialiserPlateau = CU_add_suite("Tests boite noire : copierPlateau", init_suite_success, clean_suite_success);
    pSuite_plateauRempli = CU_add_suite("Tests boite noire : plateauRempli", init_suite_success, clean_suite_success);
    pSuite_nbPions = CU_add_suite("Tests boite noire : nbPions", init_suite_success, clean_suite_success);
    if ((NULL == pSuite_initialiserPlateau)
        || (NULL == pSuite_plateauRempli)
        || (NULL == pSuite_nbPions)
        ){
    CU_cleanup_registry();
    return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite_initialiserPlateau, "Plateau de départ", test_initialiserPlateau))
        || (NULL == CU_add_test(pSuite_plateauRempli, "Plateau réellement rempli", test_plateauRempliVrai))
        || (NULL == CU_add_test(pSuite_plateauRempli, "Plateau non rempli", test_plateauRempliFaux))
        || (NULL == CU_add_test(pSuite_nbPions, "Plateau rempli de pions noirs", test_nbPionsPlateauRempli))
        || (NULL == CU_add_test(pSuite_nbPions, "Plateau initial", test_nbPionsPlateauInitial))
        /*|| (NULL == CU_add_test(pSuite_coupValide, "Pion entouré de cases de l'autre couleur mais vides après", test_coupValideQueCasesAutreCouleurPuisVide))
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
