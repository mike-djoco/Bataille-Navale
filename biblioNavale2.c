#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "biblioNavale.h"

void MyajouNavireAleatoire(char tab[10][10],char b,int t){
	int verif=0;
	int batcheck=0;
	while(batcheck!=100){
		int hv=rand()%2;
		int ligne=rand()%(10-t+1);
		int colonne=rand()%(10-t+1);
		if (hv==0){ //horizontal
			for(int i = 0; i < t; i++){
				if (tab[ligne][colonne+i]==' '){
					verif++;
				}
			}
			if (verif==t){
				for(int i = 0; i < t; i++){
					tab[ligne][colonne+i]=b;
					batcheck=100;
				}
			}
		}
		if (hv==1){ //vertical
			for(int i = 0; i < t; i++){
				if (tab[ligne+i][colonne]==' '){
					verif++;
				}
			}
			if (verif==t){
				for(int i = 0; i < t; i++){
					tab[ligne+i][colonne]=b;
					batcheck=100;
				}
			}else{
				verif=0;
			}
		}
	}
}

int MyVerif(char tab[10][10]){
	int nbbat=0;
	for (int j = 0; j < 10; ++j){
		for (int i = 0; i < 10; ++i){
			char testchar=tab[j][i];
			if (testchar!=' '){
				nbbat++;
			}
		} 
	}
	if (nbbat==17){return(1);}else{return(0);}
}

void MyAffiche(char tab[10][10]){
	printf("_|0|1|2|3|4|5|6|7|8|9|\n");
	for (int j = 0; j < 10; ++j){
		char ctab[10]={'A','B','C','D','E','F','G','H','I','J'};
		printf("%c|",ctab[j]);
		for (int i = 0; i < 10; ++i){
			printf("%c|",tab[j][i]);
		}
		printf("\n");
	}
}

void MyAfficheduo(char tab1[10][10],char tab2[10][10]){
	char space=' ';
	printf("_|0|1|2|3|4|5|6|7|8|9|      _|0|1|2|3|4|5|6|7|8|9|\n");
	for (int j = 0; j < 10; ++j){
		char ctab[10]={'A','B','C','D','E','F','G','H','I','J'};
		printf("%c|",ctab[j]);
		for (int i = 0; i < 10; ++i){
			if (tab1[j][i]=='X'){
				printf("%c|",tab1[j][i]);
			}else if (tab1[j][i]=='.'){
				printf("%c|",tab1[j][i]);
			}else{
				printf("%c|",space);
			}
		}

		printf("      ");

		printf("%c|",ctab[j]);
		for (int i = 0; i < 10; ++i){
			if (tab2[j][i]=='X'){
				printf("%c|",tab2[j][i]);
			}else if (tab2[j][i]=='.'){
				printf("%c|",tab2[j][i]);
			}else{
				printf("%c|",space);
			}
		}

		printf("\n");
	}
}

void MyInitPlateau(char tab[10][10]){
	for (int j = 0; j < 10; ++j){
		for (int i = 0; i < 10; ++i){
			tab[j][i]=' ';
		}
	}

	char q='Z';

	while(q!='a' && q!='m'){
		printf("Souhaitez placer vos navires à la (M)ain, ou (A)leatoirement ?\n");
		scanf(" %c", &q);

		if (q=='M'||q=='m'){
			break;
		}else if (q=='A'||q=='a'){
			break;
		}
	}

	if (q=='M'||q=='m'){
		int nbbateau=0;
		char t[4];
		int tabnbbat[5]={5,4,3,3,2};
		char tabletbat[5]={'A','C','S','M','T'};
		int ligne=0;
		int colonne =0;

		printf("Vous devez placer vos navires.\n");
		printf("Pour chaque navire, indiquez horizontal (h) ou vertical (v), suivi de la case la plus au nord-ouest (ex : h,E4).\n");

		for (int i = 0; i < 5; i++){
			printf("Placez votre %c (longueur %d) : \n", tabletbat[i], tabnbbat[i]);
			scanf("%s", t);

			switch(t[2]){
				case 'A': ligne = 0; break;
				case 'B': ligne = 1; break;
				case 'C': ligne = 2; break;
				case 'D': ligne = 3; break;
				case 'E': ligne = 4; break;
				case 'F': ligne = 5; break;
				case 'G': ligne = 6; break;
				case 'H': ligne = 7; break;
				case 'I': ligne = 8; break;
				case 'J': ligne = 9; break;
			}

			switch(t[3]){				
				case '0': colonne = 0; break;
				case '1': colonne = 1; break;
				case '2': colonne = 2; break;
				case '3': colonne = 3; break;
				case '4': colonne = 4; break;
				case '5': colonne = 5; break;
				case '6': colonne = 6; break;
				case '7': colonne = 7; break;
				case '8': colonne = 8; break;
				case '9': colonne = 9; break;
			}

			int ligne2 = ligne;
			int colonne2 = colonne;

			if (t[0] == 'v'){ 
				for (int i = 0; i < tabnbbat[i]; i++){
					if (tab[ligne2][colonne2] != ' '){
						printf("Bateau empiete sur un autre\n"); return;
					}
					ligne2++;
				}
				if (ligne+tabnbbat[i] > 10){
					printf("Le tableau sort des limites\n"); return;
				}
				for(ligne2 = ligne; ligne2 < ligne+tabnbbat[i]; ligne2++){
					tab[ligne2][colonne] = tabletbat[i];
				}
				MyAffiche(tab);
			}

			if (t[0] == 'h'){
				for (int i = 0; i < tabnbbat[i]; i++){
					if (tab[ligne2][colonne2] != ' '){
						printf("Bateau empiete sur un autre\n"); return;
					}
					ligne2++;
				}
				if (colonne+tabnbbat[i] > 10){
					printf("Le tableau sort des limites\n"); return;
				}
				for (colonne2 = colonne; colonne2 < colonne+tabnbbat[i]; colonne2++){
					tab[ligne][colonne2] = tabletbat[i];
				}
				MyAffiche(tab);
			}	
		}
	}
	if (q=='A'||q=='a'){
		int taillet[5]={5,4,3,3,2};
		char chararcterb[5]={'A','C','S','M','T'};
		for (int i = 0; i < 5; i++){
			char b=chararcterb[i];
			int t=taillet[i];
			MyajouNavireAleatoire(tab,b,t);
		}
	}
}

int MyJouerJoueur(char tab[10][10]){
	int res = -2;
	char t[2];
	int ligne = 0;
	int colonne = 0;

	scanf("%s", t);

	switch(t[0]){
		case 'A': ligne = 0; break;
		case 'B': ligne = 1; break;
		case 'C': ligne = 2; break;
		case 'D': ligne = 3; break;
		case 'E': ligne = 4; break;
		case 'F': ligne = 5; break;
		case 'G': ligne = 6; break;
		case 'H': ligne = 7; break;
		case 'I': ligne = 8; break;
		case 'J': ligne = 9; break;
	}

	switch(t[1]){
		case '0': colonne = 0; break;
		case '1': colonne = 1; break;
		case '2': colonne = 2; break;
		case '3': colonne = 3; break;
		case '4': colonne = 4; break;
		case '5': colonne = 5; break;
		case '6': colonne = 6; break;
		case '7': colonne = 7; break;
		case '8': colonne = 8; break;
		case '9': colonne = 9; break;
	}
	/*
	printf("Apres convertion ligne vaux : %d\n", ligne );
	printf("Apres convertion colonne vaut : %d\n", colonne);
	printf("la case du tableau contient : %c\n", tab[ligne][colonne]);
	*/

	if (ligne > 9 || colonne > 9){
		printf("Le coup est hors plateau\n"); return -3;
	}
	switch(tab[ligne][colonne]){
		case ' ': tab[ligne][colonne]= '.'; res = -1; break;
		case 'A': tab[ligne][colonne]= 'X'; res = 0; break;
		case 'C': tab[ligne][colonne]= 'X'; res = 1; break;
		case 'S': tab[ligne][colonne]= 'X'; res = 2; break;
		case 'M': tab[ligne][colonne]= 'X'; res = 3; break;
		case 'T': tab[ligne][colonne]= 'X'; res = 4;break;
		//default : return -2;
	}
	return res;
}

char* MyNavire(int i){
	char* charbateau;
	switch(i){
		case 0 :
			*charbateau='A';break;
		case 1 : 
			*charbateau='C';break;
		case 2 : 
			*charbateau='S';break;
		case 3 : 
			*charbateau='M';break;
		case 4 :
			*charbateau='T';break;
	}
	return charbateau;
}

int main(int argc, char const *argv[]){
	/*
	char j1[10][10],j2[10][10];
	int viej1 = 17, viej2 = 17; 
	int a2 = 5, c2=4, s2=3, m2=3, t2=2, a = 5, c=4, s=3, m=3, t=2;
	int quijoue=1;
	srand(time(NULL));

	printf("Joueur 1 :\n");
	MyInitPlateau(j1);
	printf("Joueur 2 :\n");
	MyInitPlateau(j2);
	MyAfficheduo(j1, j2);
	printf("Le joueur 1 joue.\n");
	int action = MyJouerJoueur(j2);					
	 while ((viej1 != 0) || (viej2 != 0)){ 
		while (action != -1){
			switch(action){
				case 0 : printf("Touché !\n");
					if(quijoue==1){a2--;}else if(quijoue==2){a--;}						
					if (a2==0 || a==0){printf("Tu as coulé le Porte-Avion\n");}; break;
				case 1 : printf("Touché !\n");
					if(quijoue==1){c2--;}else if(quijoue==2){c--;} 
					if (c2==0 || c==0){printf("Tu as coulé le Croisseur\n");}; break;
				case 2 : printf("Touché !\n");
					if(quijoue==1){s2--;}else if(quijoue==2){s--;}
					if (s2==0 || s==0){printf("Tu as coulé le Sous-Marin\n");};break;		
				case 3 : printf("Touché !\n");
					if(quijoue==1){m2--;}else if(quijoue==2){m--;}											
					if (m2==0  || m==0){printf("Tu as coulé le Mous-Sarin\n");}; break;
				case 4 : printf("Touché !\n");
					if(quijoue==1){t2--;}else if(quijoue==2){t--;}
					if (t2==0 || t==0){printf("Tu as coulé le Torpilleur\n");}; break;
				default : printf("Mauvais coup, rejouez.\n");
			}
			viej2 = a2 + c2 + s2 + m2 + t2;viej1 = a + c + s + m + t;			
			if(viej2==0){printf("Victoire de joueur 1\n");return 0;}			
			if(viej1==0){printf("Victoire de joueur 2\n");return 0;}
			MyAfficheduo(j1, j2);
			if(quijoue==1){printf("Le joueur 1 joue.\n");action = MyJouerJoueur(j2);}				
			else if(quijoue==2){printf("Le joueur 2 joue.\n");action = MyJouerJoueur(j1);}
		}
		printf("A l'eau !\n");
		MyAfficheduo(j1, j2);
		if(quijoue==1){quijoue=2;}else if(quijoue==2){quijoue=1;}								
		if(quijoue==1){printf("Le joueur 1 joue.\n");action = MyJouerJoueur(j2);}
		else if(quijoue==2){printf("Le joueur 2 joue.\n");action = MyJouerJoueur(j1);}
	}
	return 0;
	*/
}