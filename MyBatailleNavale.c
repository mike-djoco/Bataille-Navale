#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioNavale.h"

int main(int argc, char const *argv[]){
	char j1[10][10],j2[10][10]; 						/* Declaration des tableaux*/
	int viej1 = 17, viej2 = 17; 						/* Initialisation des vie des joueurs*/
	int a2 = 5, c2=4, s2=3, m2=3, t2=2, a = 5, c=4, s=3, m=3, t=2;  			/* Initialisation des bateaux*/
	int quijoue=1;					/*Variable pour savoir quel joueur joue*/
	srand(time(NULL));
	printf("Joueur 1 :\n");
	initPlateau(j1);
	printf("Joueur 2 :\n");
	initPlateau(j2);
	afficheduo(j1, j2);
	printf("Le joueur 1 joue.\n");
	int action = jouerJoueur(j2);					/*Stockage du retour de la fonction pour connaitre ou a atterie le coup*/
	while ((viej1 != 0) || (viej2 != 0)){ 
		while (action != -1){
			switch(action){
				case 0 : printf("Touché !\n");
					if(quijoue==1){a2--;}else if(quijoue==2){a--;}						/*Les conditions sont valable pour les deux joueur grace a la variable "quijoue"*/
					if (a2==0 || a==0){printf("Tu as coulé le Porte-Avion\n");}; break;
				case 1 : printf("Touché !\n");
					if(quijoue==1){c2--;}else if(quijoue==2){c--;}
					if (c2==0 || c==0){printf("Tu as coulé le Croisseur\n");}; break;
				case 2 : printf("Touché !\n");
					if(quijoue==1){s2--;}else if(quijoue==2){s--;}
					if (s2==0 || s==0){printf("Tu as coulé le Sous-Marin\n");};break;		/*Test de la variable action pour savoir quell bateau a été touché et test des cellule restantes pour savoir quand est-ce-que le bateau a coule*/
				case 3 : printf("Touché !\n");
					if(quijoue==1){m2--;}else if(quijoue==2){m--;}											
					if (m2==0  || m==0){printf("Tu as coulé le Mous-Sarin\n");}; break;
				case 4 : printf("Touché !\n");
					if(quijoue==1){t2--;}else if(quijoue==2){t--;}
					if (t2==0 || t==0){printf("Tu as coulé le Torpilleur\n");}; break;
				default : printf("Mauvais coup, rejouez.\n");
			}
			viej2 = a2 + c2 + s2 + m2 + t2;viej1 = a + c + s + m + t;			/*Verification des vies des joueurs*/
			if(viej2==0){printf("Victoire de joueur 1\n");return 0;}			/*Si un des joueurs n'a plus de vie, le joueur adversaire gagne et le programme s'arrete*/
			if(viej1==0){printf("Victoire de joueur 2\n");return 0;}
			afficheduo(j1, j2);
			if(quijoue==1){printf("Le joueur 1 joue.\n");action = jouerJoueur(j2);}				/*en cas de touche, coule, mauvais coup, le joueur rejoue*/
			else if(quijoue==2){printf("Le joueur 2 joue.\n");action = jouerJoueur(j1);}
		}
		printf("A l'eau !\n");
		afficheduo(j1, j2);
		if(quijoue==1){quijoue=2;}else if(quijoue==2){quijoue=1;}								/*Si le coup est à l'eau le joueuer adversaire joue*/
		if(quijoue==1){printf("Le joueur 1 joue.\n");action = jouerJoueur(j2);}
		else if(quijoue==2){printf("Le joueur 2 joue.\n");action = jouerJoueur(j1);}
	}
	return 0;
}