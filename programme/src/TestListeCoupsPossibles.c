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
#include "ListeCoupsPossibles.h"
#include "ListeCoupsPossibles_Prive.h"
#include "FaireUnePartie.h"
#include "FaireUnePartie_Prive.h"
#include "ObtenirCoupIA.h"
#include "ObtenirCoupIA_Prive.h"

int init_suite_success(void) {
  return 0;
}

int clean_suite_success(void) {
  return 0;
}

/* Tests relatifs à copierPlateau */

void test_copierPlateauInterieur(void){
  Position positionInter1,positionInter2,positionInter3,positionInter4;
  Pion pionN=PI_creerPion(CL_noir());
  Pion pionB=PI_creerPion(CL_blanc());
  Plateau plateau1,plateau2;
  plateau1=PL_creerPlateau();
  plateau2=PL_creerPlateau();

  POS_fixerPosition(4,5,&positionInter1);
  POS_fixerPosition(4,4,&positionInter2);
  POS_fixerPosition(2,3,&positionInter3);
  POS_fixerPosition(5,6,&positionInter4);

  PL_poserPion(&plateau1,positionInter1,pionN);
  PL_poserPion(&plateau1,positionInter2,pionB);
  PL_poserPion(&plateau1,positionInter3,pionN);
  PL_poserPion(&plateau1,positionInter4,pionB);

  copierPlateau(plateau1,&plateau2);

  CU_ASSERT_TRUE(PI_sontEgaux(PL_obtenirPion(plateau2,positionInter1),pionN)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionInter3),pionN)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionInter2),pionB)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionInter4),pionB)
                && !PL_estCaseVide(plateau2,positionInter1)
                && !PL_estCaseVide(plateau2,positionInter2)
                && !PL_estCaseVide(plateau2,positionInter3)
                && !PL_estCaseVide(plateau2,positionInter4));
}

void test_copierPlateauBords(void){
  Position positionBord1,positionBord2,positionBord3,positionBord4;
  Pion pionN=PI_creerPion(CL_noir());
  Pion pionB=PI_creerPion(CL_blanc());
  Plateau plateau1,plateau2;
  plateau1=PL_creerPlateau();
  plateau2=PL_creerPlateau();

  POS_fixerPosition(0,5,&positionBord1);
  POS_fixerPosition(4,0,&positionBord2);
  POS_fixerPosition(7,4,&positionBord3);
  POS_fixerPosition(5,7,&positionBord4);

  PL_poserPion(&plateau1,positionBord1,pionN);
  PL_poserPion(&plateau1,positionBord2,pionB);
  PL_poserPion(&plateau1,positionBord3,pionN);
  PL_poserPion(&plateau1,positionBord4,pionB);

  copierPlateau(plateau1,&plateau2);

  CU_ASSERT_TRUE(PI_sontEgaux(PL_obtenirPion(plateau2,positionBord1),pionN)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionBord3),pionN)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionBord2),pionB)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionBord4),pionB)
                && !PL_estCaseVide(plateau2,positionBord1)
                && !PL_estCaseVide(plateau2,positionBord2)
                && !PL_estCaseVide(plateau2,positionBord3)
                && !PL_estCaseVide(plateau2,positionBord4));
}

void test_copierPlateauCoins(void){
  Position positionCoin1,positionCoin2,positionCoin3,positionCoin4;
  Pion pionN=PI_creerPion(CL_noir());
  Pion pionB=PI_creerPion(CL_blanc());
  Plateau plateau1,plateau2;
  plateau1=PL_creerPlateau();
  plateau2=PL_creerPlateau();

  POS_fixerPosition(0,0,&positionCoin1);
  POS_fixerPosition(0,7,&positionCoin2);
  POS_fixerPosition(7,0,&positionCoin3);
  POS_fixerPosition(7,7,&positionCoin4);

  PL_poserPion(&plateau1,positionCoin1,pionN);
  PL_poserPion(&plateau1,positionCoin2,pionB);
  PL_poserPion(&plateau1,positionCoin3,pionN);
  PL_poserPion(&plateau1,positionCoin4,pionB);

  copierPlateau(plateau1,&plateau2);

  CU_ASSERT_TRUE(PI_sontEgaux(PL_obtenirPion(plateau2,positionCoin1),pionN)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionCoin3),pionN)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionCoin2),pionB)
                && PI_sontEgaux(PL_obtenirPion(plateau2,positionCoin4),pionB)
                && !PL_estCaseVide(plateau2,positionCoin1)
                && !PL_estCaseVide(plateau2,positionCoin2)
                && !PL_estCaseVide(plateau2,positionCoin3)
                && !PL_estCaseVide(plateau2,positionCoin4));
}

/* Tests relatifs à coupValide */

void test_coupValideEntoureCasesVides(void){
  Plateau plateau;
  Coup coup;
  Position positionTest;
  Pion pionTest=PI_creerPion(CL_noir());

  plateau=PL_creerPlateau();
  POS_fixerPosition(4,5,&positionTest);
  PL_poserPion(&plateau,positionTest,pionTest);
  coup=CP_creerCoup(positionTest,pionTest);
  CU_ASSERT_TRUE(!coupValide(plateau, coup));
}

void test_coupValideEntoureCasesMemeCouleur(void){
  Plateau plateau;
  Coup coup;
  Position positionTest,positionAutour1,positionAutour2,positionAutour3,positionAutour4,positionAutour5,positionAutour6,positionAutour7,positionAutour8;
  Pion pionTest=PI_creerPion(CL_blanc()), pionAutour1=PI_creerPion(CL_blanc()),
        pionAutour2=PI_creerPion(CL_blanc()), pionAutour3=PI_creerPion(CL_blanc()),
        pionAutour4=PI_creerPion(CL_blanc()), pionAutour5=PI_creerPion(CL_blanc()),
        pionAutour6=PI_creerPion(CL_blanc()), pionAutour7=PI_creerPion(CL_blanc()), pionAutour8=PI_creerPion(CL_blanc());

  plateau=PL_creerPlateau();
  POS_fixerPosition(4,5,&positionTest);
  POS_fixerPosition(3,4,&positionAutour1);
  POS_fixerPosition(4,4,&positionAutour2);
  POS_fixerPosition(5,4,&positionAutour3);
  POS_fixerPosition(3,5,&positionAutour4);
  POS_fixerPosition(5,5,&positionAutour5);
  POS_fixerPosition(3,6,&positionAutour6);
  POS_fixerPosition(4,6,&positionAutour7);
  POS_fixerPosition(5,6,&positionAutour8);

  PL_poserPion(&plateau,positionTest,pionTest);
  PL_poserPion(&plateau,positionAutour1,pionAutour1);
  PL_poserPion(&plateau,positionAutour2,pionAutour2);
  PL_poserPion(&plateau,positionAutour3,pionAutour3);
  PL_poserPion(&plateau,positionAutour4,pionAutour4);
  PL_poserPion(&plateau,positionAutour5,pionAutour5);
  PL_poserPion(&plateau,positionAutour6,pionAutour6);
  PL_poserPion(&plateau,positionAutour7,pionAutour7);
  PL_poserPion(&plateau,positionAutour8,pionAutour8);

  coup=CP_creerCoup(positionTest,pionTest);
  CU_ASSERT_TRUE(!coupValide(plateau, coup));
}

void test_coupValideQueCasesAutreCouleurPuisVide(void){
  Plateau plateau;
  Coup coup;
  Position positionTest,positionAutour1,positionAutour2,positionAutour3,positionAutour4,positionAutour5,positionAutour6,positionAutour7,positionAutour8;
  Pion pionTest=PI_creerPion(CL_noir()), pionAutour1=PI_creerPion(CL_blanc()), pionAutour2=PI_creerPion(CL_blanc()),
        pionAutour3=PI_creerPion(CL_blanc()), pionAutour4=PI_creerPion(CL_blanc()), pionAutour5=PI_creerPion(CL_blanc()),
        pionAutour6=PI_creerPion(CL_blanc()), pionAutour7=PI_creerPion(CL_blanc()), pionAutour8=PI_creerPion(CL_blanc());

  plateau=PL_creerPlateau();
  POS_fixerPosition(4,5,&positionTest);
  POS_fixerPosition(3,4,&positionAutour1);
  POS_fixerPosition(4,4,&positionAutour2);
  POS_fixerPosition(5,4,&positionAutour3);
  POS_fixerPosition(3,5,&positionAutour4);
  POS_fixerPosition(5,5,&positionAutour5);
  POS_fixerPosition(3,6,&positionAutour6);
  POS_fixerPosition(4,6,&positionAutour7);
  POS_fixerPosition(5,6,&positionAutour8);

  PL_poserPion(&plateau,positionTest,pionTest);
  PL_poserPion(&plateau,positionAutour1,pionAutour1);
  PL_poserPion(&plateau,positionAutour2,pionAutour2);
  PL_poserPion(&plateau,positionAutour3,pionAutour3);
  PL_poserPion(&plateau,positionAutour4,pionAutour4);
  PL_poserPion(&plateau,positionAutour5,pionAutour5);
  PL_poserPion(&plateau,positionAutour6,pionAutour6);
  PL_poserPion(&plateau,positionAutour7,pionAutour7);
  PL_poserPion(&plateau,positionAutour8,pionAutour8);

  coup=CP_creerCoup(positionTest,pionTest);
  CU_ASSERT_TRUE(!coupValide(plateau, coup));
}

void test_coupValideCoin(void){
  Plateau plateau;
  Coup coup;
  Position positionTest,positionAutreCouleur1,positionAutreCouleur2,positionMemeCouleur;
  Pion pionTest=PI_creerPion(CL_noir()), pionAutreCouleur1=PI_creerPion(CL_blanc()), pionAutreCouleur2=PI_creerPion(CL_blanc()),
        pionMemeCouleur=PI_creerPion(CL_noir());

  plateau=PL_creerPlateau();
  POS_fixerPosition(0,0,&positionTest);
  POS_fixerPosition(1,0,&positionAutreCouleur1);
  POS_fixerPosition(2,0,&positionAutreCouleur2);
  POS_fixerPosition(3,0,&positionMemeCouleur);

  PL_poserPion(&plateau,positionAutreCouleur1,pionAutreCouleur1);
  PL_poserPion(&plateau,positionAutreCouleur2,pionAutreCouleur2);
  PL_poserPion(&plateau,positionMemeCouleur,pionMemeCouleur);

  coup=CP_creerCoup(positionTest,pionTest);
  CU_ASSERT_TRUE(coupValide(plateau, coup));
}

void test_coupValideQuelconque(void){
  Plateau plateau;
  Coup coup;
  Position positionTest,positionAutreCouleur1,positionAutreCouleur2,positionMemeCouleur;
  Pion pionTest=PI_creerPion(CL_noir()), pionAutreCouleur1=PI_creerPion(CL_blanc()), pionAutreCouleur2=PI_creerPion(CL_blanc()),
        pionMemeCouleur=PI_creerPion(CL_noir());

  plateau=PL_creerPlateau();
  POS_fixerPosition(4,3,&positionTest);
  POS_fixerPosition(4,4,&positionAutreCouleur1);
  POS_fixerPosition(4,5,&positionAutreCouleur2);
  POS_fixerPosition(4,6,&positionMemeCouleur);

  PL_poserPion(&plateau,positionAutreCouleur1,pionAutreCouleur1);
  PL_poserPion(&plateau,positionAutreCouleur2,pionAutreCouleur2);
  PL_poserPion(&plateau,positionMemeCouleur,pionMemeCouleur);

  coup=CP_creerCoup(positionTest,pionTest);
  CU_ASSERT_TRUE(coupValide(plateau, coup));
}

/* Tests relatifs à listeCoupsPossibles */

void test_listeCoupsPossibles(void){
  Plateau plateau;
  Coup coup1,coup2,coup3,coup4;
  Coups listeCoups;
  Couleur couleurJoueur=CL_blanc();
  Position position1,position2,position3,position4,positionCoup1,positionCoup2,positionCoup3,positionCoup4;
  Pion pion1=PI_creerPion(CL_blanc()), pion2=PI_creerPion(CL_noir()), pion3=PI_creerPion(CL_noir()), pion4=PI_creerPion(CL_blanc()); /* Configuration initiale du plateau */
  Pion pionCoup1=PI_creerPion(CL_blanc()), pionCoup2=PI_creerPion(CL_blanc()), pionCoup3=PI_creerPion(CL_blanc()), pionCoup4=PI_creerPion(CL_blanc());

  plateau=PL_creerPlateau();
  CPS_creerCoups(&listeCoups);

  POS_fixerPosition(3,3,&position1);
  POS_fixerPosition(3,4,&position2);
  POS_fixerPosition(4,3,&position3);
  POS_fixerPosition(4,4,&position4);
  POS_fixerPosition(2,4,&positionCoup1);
  POS_fixerPosition(3,5,&positionCoup2);
  POS_fixerPosition(4,2,&positionCoup3);
  POS_fixerPosition(5,3,&positionCoup4);

  PL_poserPion(&plateau,position1,pion1);
  PL_poserPion(&plateau,position2,pion2);
  PL_poserPion(&plateau,position3,pion3);
  PL_poserPion(&plateau,position4,pion4);

  coup1=CP_creerCoup(positionCoup1,pionCoup1);
  coup2=CP_creerCoup(positionCoup2,pionCoup2);
  coup3=CP_creerCoup(positionCoup3,pionCoup3);
  coup4=CP_creerCoup(positionCoup4,pionCoup4);

  listeCoups=listeCoupsPossibles(plateau,couleurJoueur);

  CU_ASSERT_TRUE(CP_sontEgaux(CPS_iemeCoup(listeCoups, 0),coup1)
                && CP_sontEgaux(CPS_iemeCoup(listeCoups, 1),coup2)
                && CP_sontEgaux(CPS_iemeCoup(listeCoups, 2),coup3)
                && CP_sontEgaux(CPS_iemeCoup(listeCoups, 3),coup4));
}

void test_listeCoupsPossiblesPlateauVide(void){
  Plateau plateau;
  Coups listeCoups;
  Couleur couleurJoueur=CL_blanc();

  plateau=PL_creerPlateau();
  CPS_creerCoups(&listeCoups);

  listeCoups=listeCoupsPossibles(plateau,couleurJoueur);
  CU_ASSERT_TRUE(CPS_nbCoups(listeCoups)==0);
}



/* Tests relatifs à ObtenirCoupIA */

void test_ObtenirCoupIA(void)
{
    Plateau plateau=PL_creerPlateau();
    Couleur couleurJoueur=CL_noir();
    Coup Meilleurcoup,meilleurCoupIA;
    Position positionPionBlanc,positionMeilleurcoup;
    Pion pionBlanc=PI_creerPion(CL_blanc()),pionMeilleurcoup=PI_creerPion(CL_noir());

    initialiserPlateau(&plateau);
    POS_fixerPosition(2,4,&positionPionBlanc);
    PL_poserPion(&plateau, positionPionBlanc, pionBlanc);
    POS_fixerPosition(2,3,&positionMeilleurcoup);

    Meilleurcoup=CP_creerCoup(positionMeilleurcoup,pionMeilleurcoup);

    meilleurCoupIA=obtenirCoupIA(plateau,couleurJoueur);


    CU_ASSERT_TRUE(CP_sontEgaux(Meilleurcoup,meilleurCoupIA));
}
/* Tests relatifs à scoreDUnCoup */

void test_scoreDUnCoup(void)
{
    Plateau plateau=PL_creerPlateau();
    Couleur couleurJoueur=CL_noir();
    unsigned int profondeurMinMax=profondeur();
    Coup coup1, Meilleurcoup;
    int scoreCourant, meilleurScore;
    Position positionPionBlanc,positionCoup1,positionMeilleurcoup;
    Pion pionCoup1=PI_creerPion(CL_noir()), pionMeilleurcoup=PI_creerPion(CL_noir()), pionBlanc=PI_creerPion(CL_blanc());
    int** grilleScore=initialiserGrilleScore();

    /* Configuration initiale du plateau */

    initialiserPlateau(&plateau);
    POS_fixerPosition(2,4,&positionPionBlanc);
    PL_poserPion(&plateau, positionPionBlanc, pionBlanc);
    POS_fixerPosition(1,4,&positionCoup1);
    POS_fixerPosition(3,2,&positionMeilleurcoup);

    coup1=CP_creerCoup(positionCoup1,pionCoup1);
    Meilleurcoup=CP_creerCoup(positionMeilleurcoup,pionMeilleurcoup);

    meilleurScore = scoreDUnCoup(plateau,Meilleurcoup,couleurJoueur,couleurJoueur,profondeurMinMax,grilleScore);
    scoreCourant = scoreDUnCoup(plateau,coup1,couleurJoueur,couleurJoueur,profondeurMinMax,grilleScore);


    CU_ASSERT_TRUE    ((coupValide(plateau, coup1))
                       && (coupValide(plateau, Meilleurcoup))
                       && (meilleurScore>scoreCourant));
}


/* Tests relatifs à evaluerPlateau */

void test_evaluerNbCoupsPossiblesAdversaire(void){
    Plateau plateau=PL_creerPlateau();
    Couleur couleurJoueur=CL_blanc(), couleurAdversaire;
    int NbCoupsAdversaire,resultat;
    Position position1,position2,position3,position4;
    Pion pion1=PI_creerPion(CL_blanc()), pion2=PI_creerPion(CL_noir()), pion3=PI_creerPion(CL_noir()), pion4=PI_creerPion(CL_blanc());

    POS_fixerPosition(3,3,&position1);
    POS_fixerPosition(3,4,&position2);
    POS_fixerPosition(4,3,&position3);
    POS_fixerPosition(4,4,&position4);

    PL_poserPion(&plateau,position1,pion1);
    PL_poserPion(&plateau,position2,pion2);
    PL_poserPion(&plateau,position3,pion3);
    PL_poserPion(&plateau,position4,pion4);

    couleurAdversaire=CL_changerCouleur(couleurJoueur);
    NbCoupsAdversaire=4;
    resultat=(60-10*NbCoupsAdversaire);

    CU_ASSERT_TRUE(evaluerNbCoupsPossiblesAdversaire(plateau,couleurAdversaire) == resultat);

}

void test_evaluerNbPionsCouleur(void){
    Plateau plateau=PL_creerPlateau();
    Couleur couleurJoueur=CL_blanc();
    int nbPionsNoirs,nbPionsBlancs;
    Position position1,position2,position3,position4,positionCoup1,positionCoup2;
    Pion pion1=PI_creerPion(CL_blanc()), pion2=PI_creerPion(CL_noir()), pion3=PI_creerPion(CL_noir()),
          pion4=PI_creerPion(CL_blanc()),pionCoup1=PI_creerPion(CL_blanc()),pionCoup2=PI_creerPion(CL_blanc());

    POS_fixerPosition(3,3,&position1);
    POS_fixerPosition(3,4,&position2);
    POS_fixerPosition(4,3,&position3);
    POS_fixerPosition(4,4,&position4);
    POS_fixerPosition(3,2,&positionCoup1);
    POS_fixerPosition(4,2,&positionCoup2);

    PL_poserPion(&plateau,position1,pion1);
    PL_poserPion(&plateau,position2,pion2);
    PL_poserPion(&plateau,position3,pion3);
    PL_poserPion(&plateau,position4,pion4);
    PL_poserPion(&plateau,positionCoup1,pionCoup1);
    PL_poserPion(&plateau,positionCoup2,pionCoup2);

    nbPions(plateau,&nbPionsNoirs,&nbPionsBlancs);

    CU_ASSERT_TRUE (evaluerNbPionsCouleur(plateau,couleurJoueur)==2);
}


void test_evaluerPositionsPionsPlateau(void){
    int** grilleScore=initialiserGrilleScore();
    Plateau plateau=PL_creerPlateau();
    Couleur couleurJoueur=CL_blanc();
    Position position1,position2,position3,position4,positionCoup1,positionCoup2;
    Pion pion1=PI_creerPion(CL_blanc()), pion2=PI_creerPion(CL_noir()), pion3=PI_creerPion(CL_noir()),
          pion4=PI_creerPion(CL_blanc()),pionCoup1=PI_creerPion(CL_blanc()),pionCoup2=PI_creerPion(CL_blanc());
    int resJoueurTEST,resAdversaireTEST;

    resJoueurTEST=0;
    resAdversaireTEST=0;

    POS_fixerPosition(3,3,&position1);
    POS_fixerPosition(3,4,&position2);
    POS_fixerPosition(4,3,&position3);
    POS_fixerPosition(4,4,&position4);
    POS_fixerPosition(3,2,&positionCoup1);
    POS_fixerPosition(4,2,&positionCoup2);

    PL_poserPion(&plateau,position1,pion1);
    PL_poserPion(&plateau,position2,pion2);
    PL_poserPion(&plateau,position3,pion3);
    PL_poserPion(&plateau,position4,pion4);
    PL_poserPion(&plateau,positionCoup1,pionCoup1);
    PL_poserPion(&plateau,positionCoup2,pionCoup2);

    resJoueurTEST=grilleScore[3][3]+grilleScore[4][4]+grilleScore[3][2]+grilleScore[4][2];
    resAdversaireTEST=grilleScore[3][4]+grilleScore[4][3];

    CU_ASSERT_TRUE ( evaluerPositionsPionsPlateau(plateau,couleurJoueur,grilleScore)==(resJoueurTEST-resAdversaireTEST));

}



int main(int argc, char** argv){
    CU_pSuite pSuite_copierPlateau;
    CU_pSuite pSuite_coupValide;
    CU_pSuite pSuite_listeCoupsPossibles;
    CU_pSuite pSuite_ObtenirCoupIA;
    CU_pSuite pSuite_scoreDUnCoup;
    CU_pSuite pSuite_evaluerPlateau;


    /* initialisation du registre de tests */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    /* ajout des suites de tests */
    pSuite_copierPlateau = CU_add_suite("Tests boite noire : copierPlateau", init_suite_success, clean_suite_success);
    pSuite_coupValide = CU_add_suite("Tests boite noire : coupValide", init_suite_success, clean_suite_success);
    pSuite_listeCoupsPossibles = CU_add_suite("Tests boite noire : listeCoupsPossibles", init_suite_success, clean_suite_success);
    pSuite_scoreDUnCoup = CU_add_suite("Tests boite noire : scoreDUnCoup", init_suite_success, clean_suite_success);
    pSuite_ObtenirCoupIA = CU_add_suite("Tests boite noire : ObtenirCoupIA", init_suite_success, clean_suite_success);
    pSuite_evaluerPlateau = CU_add_suite("Tests boite noire : evaluerPlateau", init_suite_success, clean_suite_success);
    if ((NULL == pSuite_copierPlateau)
        || (NULL == pSuite_coupValide)
        || (NULL == pSuite_listeCoupsPossibles)
        || (NULL == pSuite_scoreDUnCoup)
        || (NULL == pSuite_ObtenirCoupIA)
        || (NULL == pSuite_evaluerPlateau)
        ){
        CU_cleanup_registry();
        return CU_get_error();
    }

    /* Ajout des tests à la suite de tests boite noire */
    if ((NULL == CU_add_test(pSuite_copierPlateau, "Pions à l'intérieur", test_copierPlateauInterieur))
        || (NULL == CU_add_test(pSuite_copierPlateau, "Pions sur les bords", test_copierPlateauBords))
        || (NULL == CU_add_test(pSuite_copierPlateau, "Pions dans les coins", test_copierPlateauCoins))
        || (NULL == CU_add_test(pSuite_coupValide, "Pion entouré de cases vides", test_coupValideEntoureCasesVides))
        || (NULL == CU_add_test(pSuite_coupValide, "Pion entouré de cases de même couleur", test_coupValideEntoureCasesMemeCouleur))
        || (NULL == CU_add_test(pSuite_coupValide, "Pion entouré de cases de l'autre couleur mais vides après", test_coupValideQueCasesAutreCouleurPuisVide))
        || (NULL == CU_add_test(pSuite_coupValide, "Coup valide, pos initiale dans un coin", test_coupValideCoin))
        || (NULL == CU_add_test(pSuite_coupValide, "Coup valide, pos initiale quelconque", test_coupValideQuelconque))
        || (NULL == CU_add_test(pSuite_listeCoupsPossibles, "Liste des coups possibles au début de jeu", test_listeCoupsPossibles))
        || (NULL == CU_add_test(pSuite_listeCoupsPossibles, "Liste de coups possibles vide", test_listeCoupsPossiblesPlateauVide))
        || (NULL == CU_add_test(pSuite_scoreDUnCoup, "calcul le bon score du coup", test_scoreDUnCoup))
        || (NULL == CU_add_test(pSuite_ObtenirCoupIA, "Renvoie le bon coup", test_ObtenirCoupIA))
        || (NULL == CU_add_test(pSuite_evaluerPlateau, "evaluer le nombre de coups possibles de l'adversaire", test_evaluerNbCoupsPossiblesAdversaire))
        || (NULL == CU_add_test(pSuite_evaluerPlateau, "evaluer le nombre de pions de la meme couleur", test_evaluerNbPionsCouleur))
        || (NULL == CU_add_test(pSuite_evaluerPlateau, "evaluer la position des pions sur le plateau", test_evaluerPositionsPionsPlateau))
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
