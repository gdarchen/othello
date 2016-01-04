Pour compiler le programme :
	-se déplacer dans le dossier programme
	-"make" pour obtenir l'éxécutable Othello dans le dossier bin ainsi que la documentation
	-"make tests" pour obtenir les éxécutables des tests unitaires dans le dossier tests
	-"make clean" pour supprimer tous les fichiers générés par les différentes compilations

---------------------------------------------------------------------------------------------------------------------------------------

Une fois l'éxécutable créé, entrer "./bin/Othello standard blanc" pour exécuter le programme en mode joueur contre ordinateur,
le joueur a les pions blancs. Remplacer blanc par noir pour avoir les pions noirs.

Entrer "./bin/Othello tournoi blanc" pour faire jouer l'ordinateur contre l'ordinateur avec celui ayant les pions blancs qui commence.

---------------------------------------------------------------------------------------------------------------------------------------

Les pré-requis pour une bonne utilisation du programme, en mode standard :
— lorsque le tour est celui du joueur humain, il est ammené à entrer les coordonnées du pion qu'il souhaite placer :
     — la ligne, entre 1 et 8		
     — la colonne, entre 1 et 8

Les pré-requis pour une bonne utilisation du programme, en mode tournoi :
— un coup sera exprime par une chaine de caractères de longueur 3 :  
     — le premier caractère représentera la colonne  a l’aide d’une lettre en minuscule comprise entre ’a’ et ’h’ ; 
     — le deuxième caractère representera la ligne a l’aide d’un chiffre compris entre  ’1’ et ’8’ ; 
     — le troisieme caractere sera le retour chariot unix (  ’\n’). 
Par exemple si le programme veut jouer le coup e5, il écrira dans la sortie standard la chaine de caractères  "e5\n" ; 
— l’état final de la partie sera exprimé par une chaîne de caractères se finissant par le retour chariot  unix (’\n’) : 
         — "blanc\n" si les blancs ont gagne ; ´
         — "noir\n" si les noirs ont gagne ; 
         — "nulle\n" si la partie est nulle. 
— lorsque le programme ne peut pas jouer, il utilisera la chaine de caractères  "passe\n" à la place du coup qu’il aurait pu jouer.

---------------------------------------------------------------------------------------------------------------------------------------

Programme développé dans le cadre du projet d'algorithmique et bases de la programmation en ASI3 à l'INSA de Rouen par :
	Gautier DARCHEN
	Romain JUDIC
	Riadh KILANI
	Claire LOVISA
	Sandratra RASENDRASOA
	
Projet encadré par Geraldine DEL MONDO et Nicolas DELESTRE, enseignants.
Date de rendu : 05/01/16
