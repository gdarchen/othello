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

/* Tests relatifs à inverserPionsDir */

void test_inverserPionsDir(void) {
  int res;
  Plateau plateau;
  Position positionPion,positionTeste;
  unsigned int x,y;
  x = 4;
  y = 5;
  Pion pionNoir=PI_creerPion(CL_noir());
  Direction dirTest = GAUCHE;
  plateau=PL_creerPlateau();
  initialiserPlateau(&plateau);
  POS_fixerPosition(x,y,&positionPion);
  POS_fixerPosition(x,y-1,&positionTeste);
  PL_poserPion(&plateau, positionPion, pionNoir);
  inverserPionsDir(&plateau,positionPion,positionTeste,dirTest);
  res = (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,positionTeste)),CL_noir()));

  CU_ASSERT_TRUE(res==TRUE);
}

/* Tests relatifs à inverserPions */

void test_inverserPions(void){
  Position positionPion;
  Position positionTest1,positionTest2,positionJoue;
  int res;
  /* Initialisation situation */
  Pion pionNoir=PI_creerPion(CL_noir());
  Pion pionBlanc=PI_creerPion(CL_blanc());
  Plateau plateau=PL_creerPlateau();
  initialiserPlateau(&plateau);
  POS_fixerPosition(3,2,&positionPion);
  PL_poserPion(&plateau, positionPion, pionNoir);
  POS_fixerPosition(3,3,&positionPion);
  PL_poserPion(&plateau, positionPion, pionNoir);
  POS_fixerPosition(4,2,&positionPion);
  PL_poserPion(&plateau, positionPion, pionBlanc);
  POS_fixerPosition(4,3,&positionPion);
  PL_poserPion(&plateau, positionPion, pionBlanc);
  /* Test */
  POS_fixerPosition(2,2,&positionJoue);
  PL_poserPion(&plateau, positionJoue, pionBlanc);
  inverserPions(positionJoue, pionBlanc,&plateau);
  POS_fixerPosition(3,2,&positionTest1);
  POS_fixerPosition(3,3,&positionTest2);
  res = (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,positionTest1)),CL_blanc())) && (CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,positionTest2)),CL_blanc()));

  CU_ASSERT_TRUE(res==TRUE);
}

/* Tests relatifs à pionEstPresent */

/* Tests relatifs à initialiserPlateau */

void test_initialiserPlateau(void){
  Plateau plateau;
  int res=TRUE;
  Position pos;
  unsigned int i,j,x,y;
  plateau=PL_creerPlateau();
  initialiserPlateau(&plateau);

  for(i=1;i<9;i++){
    for(j=1;j<9;j++){
      x=i-1;
      y=j-1;
      POS_fixerPosition(x,y,&pos);
      if ((x==3 && y==3) || (x==4 && y==4)){
        if (PL_estCaseVide(plateau,pos)){
          res=FALSE;
        }
        else if(CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),CL_blanc())){
          res=FALSE;
        }
      }
      else if ((x==3 && y==4) || (x==4 && y==3)){
        if (PL_estCaseVide(plateau,pos)){
          res=FALSE;
        }
        else if(CL_sontEgales(PI_obtenirCouleur(PL_obtenirPion(plateau,pos)),CL_noir())){
          res=FALSE;
        }
      }
      else{
        if (!PL_estCaseVide(plateau,pos)){
          res=FALSE;
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
  initialiserPlateau(&plateau);

  CU_ASSERT_TRUE(plateauRempli(plateau)==FALSE);
}

/* Tests relatifs à nbPions */

void test_nbPionsPlateauRempli(void){
  unsigned int i,j;
  unsigned int nbPionsNoirs=0,nbPionsBlancs=0;
  Position position;
  Pion pion=PI_creerPion(CL_noir());
  Plateau plateau;
  PL_creerPlateau(&plateau);
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      POS_fixerPosition(i, j, &position);
      PL_poserPion(&plateau,position,pion);
    }
  }
  nbPions(plateau,&nbPionsNoirs, &nbPionsBlancs);

  CU_ASSERT_TRUE((nbPionsBlancs==0) && (nbPionsNoirs==64));
}

void test_nbPionsPlateauInitial(void){
  Plateau plateau;
  unsigned int nbPionsNoirs=0,nbPionsBlancs=0;
  plateau=PL_creerPlateau();
  initialiserPlateau(&plateau);
  nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);

  CU_ASSERT_TRUE((nbPionsBlancs==2) && (nbPionsNoirs==2));
}

/* Tests relatifs à finPartie */

void test_finPartieJoueursBloques(void){
  Plateau plateau=PL_creerPlateau();
  int aPuJouerJoueur1 = FALSE, aPuJouerJoueur2 = FALSE;
  unsigned int nbPionsNoirs = 0, nbPionsBlancs = 0;
  int estFinie = FALSE;
  finPartie(plateau,aPuJouerJoueur1,aPuJouerJoueur2,&nbPionsNoirs,&nbPionsBlancs,&estFinie);

  CU_ASSERT_TRUE(estFinie==TRUE);
}

void test_finPartieUnSeulJoueurBloque(void){
  Plateau plateau=PL_creerPlateau();
  initialiserPlateau(&plateau);
  int aPuJouerJoueur1 = TRUE, aPuJouerJoueur2 = FALSE;
  unsigned int nbPionsNoirs = 4, nbPionsBlancs = 4;
  int estFinie = FALSE;
  finPartie(plateau,aPuJouerJoueur1,aPuJouerJoueur2,&nbPionsNoirs,&nbPionsBlancs,&estFinie);

  CU_ASSERT_TRUE(estFinie==FALSE);
}

void test_finPartiePlateauRempli(void){
  Plateau plateau=PL_creerPlateau();
  Pion pionBlanc=PI_creerPion(CL_blanc());
  Position pos;
  int aPuJouerJoueur1 = TRUE, aPuJouerJoueur2 = TRUE;
  int estFinie = FALSE;
  unsigned int nbPionsNoirs = 0, nbPionsBlancs = 0;
  int i,j;
  for(i=0;i<8;i++){
    for(j=0;j<8;j++){
      POS_fixerPosition(i,j,&pos);
      PL_poserPion(&plateau,pos,pionBlanc);
    }
  }
  finPartie(plateau,aPuJouerJoueur1,aPuJouerJoueur2,&nbPionsNoirs,&nbPionsBlancs,&estFinie);

  CU_ASSERT_TRUE(estFinie==TRUE);
}

/* Tests relatifs à jouerCoup */

void test_jouerCoup(void){
  Plateau plateau;
  Coup coup;
  Position position;
  Pion pion;
  Couleur blanc=CL_blanc();
  plateau=PL_creerPlateau();
  initialiserPlateau(&plateau);
  pion=PI_creerPion(blanc);
  POS_fixerPosition(2,4,&position);
  coup=CP_creerCoup(position, pion);

  jouerCoup(coup,&plateau);

  CU_ASSERT_TRUE( !(PL_estCaseVide(plateau,position)) && PI_sontEgaux(PL_obtenirPion(plateau,position),pion) );
}


int main(int argc, char** argv){
    CU_pSuite pSuite_initialiserPlateau;
    CU_pSuite pSuite_plateauRempli;
    CU_pSuite pSuite_nbPions;
    CU_pSuite pSuite_finPartie;
    CU_pSuite pSuite_jouerCoup;
    CU_pSuite pSuite_inverserPionsDir;
    CU_pSuite pSuite_inverserPions;

    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout des suites de tests */
    pSuite_initialiserPlateau = CU_add_suite("Tests boite noire : copierPlateau", init_suite_success, clean_suite_success);
    pSuite_plateauRempli = CU_add_suite("Tests boite noire : plateauRempli", init_suite_success, clean_suite_success);
    pSuite_nbPions = CU_add_suite("Tests boite noire : nbPions", init_suite_success, clean_suite_success);
    pSuite_finPartie = CU_add_suite("Tests boite noire : finPartie", init_suite_success, clean_suite_success);
    pSuite_jouerCoup = CU_add_suite("Tests boite noire : jouerCoup", init_suite_success, clean_suite_success);
    pSuite_inverserPionsDir = CU_add_suite("Tests boite noire : inverserPionsDir", init_suite_success, clean_suite_success);
    pSuite_inverserPions = CU_add_suite("Tests boite noire : inverserPions", init_suite_success, clean_suite_success);
    if ((NULL == pSuite_initialiserPlateau)
        || (NULL == pSuite_plateauRempli)
        || (NULL == pSuite_nbPions)
        || (NULL == pSuite_finPartie)
        || (NULL == pSuite_jouerCoup)
        || (NULL == pSuite_inverserPionsDir)
	      || (NULL == pSuite_inverserPions)
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
        || (NULL == CU_add_test(pSuite_finPartie, "Joueurs bloqués", test_finPartieJoueursBloques)) 
        || (NULL == CU_add_test(pSuite_finPartie, "Plateau rempli", test_finPartiePlateauRempli)) 
        || (NULL == CU_add_test(pSuite_finPartie, "Un seul joueur bloqué", test_finPartieUnSeulJoueurBloque)) 
        || (NULL == CU_add_test(pSuite_jouerCoup, "Jouer un coup", test_jouerCoup))
       	|| (NULL == CU_add_test(pSuite_inverserPionsDir, "Inverser pions vers la gauche",test_inverserPionsDir))
	      || (NULL == CU_add_test(pSuite_inverserPions, "Inverser pions ",test_inverserPions))
        /*|| (NULL == CU_add_test(pSuite_coupValide, "Coup valide, pos initiale dans un coin", test_coupValideCoin))
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
