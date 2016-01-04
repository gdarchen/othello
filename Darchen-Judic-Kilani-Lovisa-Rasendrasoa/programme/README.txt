Pour compiler le programme :
	-se déplacer dans le dossier programme
	-"make" pour obtenir l'éxécutable Othello dans le dossier bin
	-"make tests" pour obtenir les éxécutables des tests unitaires dans le dossier tests
	-"make clean" pour supprimer tous les fichiers générés par les différentes compilations

-------------------------------------------------------------------------------------------------

Une fois l'éxécutable créé, entrer "bin/Othello  pour exécuter le programme .

-------------------------------------------------------------------------------------------------

Les pré-requis pour une bonne utilisation du programme :
— un coup sera exprime par une chaine de caractères de longueur 3 :  
     — le premier caractère représentera la colonne  a l’aide d’une lettre en minuscule comprise entre ’a’ et ’h’ ; 
     — le deuxième caractère representera la ligne a l’aide d’un chiffre compris entre  ’1’ et ’8’ ; 
     — le troisieme caractere sera le retour chariot unix (  ’\n’). 
Par exemple si le programme veut jouer le coup e5, il écrira dans la sortie standard la chaine de caractères  "e5\n" ; 
— l’état final de la partie sera exprime par une chaine de caractères se finissant par le retour chariot  unix (’\n’) : 
         — "blanc\n" si les blancs ont gagne ; ´
         — "noir\n" si les noirs ont gagne ; 
          — "nulle\n" si la partie est nulle. 
— lorsque le programme ne peut pas jouer, il utilisera la chaine de caractères  "passe\n" a la place du coup qu’il aurait pu jouer.
--------------------------------------------------------------------------------------------------

Programme développé dans le cadre du projet d'algorithmique et bases de la programmation en ASI3 à l'INSA de Rouen par :
	Claire LOVISA
	Gautier DARCHEN
	Romain JUDIC
	Sandratra RASENDRASOA
	Riadh KILANI
Projet encadré par Geraldine DEL MONDO et Nicolas DELESTRE , enseignants.
Date de rendu : 05/01/16