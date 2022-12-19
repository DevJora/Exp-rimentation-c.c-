//Implémentation de course à plusieurs voitures afin de tester la montée en puissance donnée par un type  de données, tableau ou structure 

/*Principe de circuit 
- Un circuit est considéré comme un ensemble de traits
- Chaque trait correspond à une direction et à un nombre de pas dans cette direction
- Nord  = 0, Est = 1, Sud = 2, ouest = 3. 
- pour avoir un circuit il faut une position de départ et plusieurs traits
- Pour suivre le circuit il faut parcourir chaque trait l'un après l'autre 

Le circuit ici est un carré
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//taille de la zone de jeu 
#define TX 80
#define TY 80


//position de départ de la zone de jeu 
#define STARTX 2
#define STARTY 2

//les quatres directions 
enum{NORD, EST, SUD, OUEST};

//l'ensemble des variables 
int P1, D1, P2, D2, P3, D3, P4, D4, P5, D5, P6, D6, NBTRAIT, NBTOUR;

//ensemble des variables pour une voiture
int X, Y, VIT, DIR, PAS, IDTRAIT, TOUR;

// les fonctions 
void create_circuit1(void);
void select_trait(void);
void avancer(int l, int color1, int color2);
void afficher(int x, int y, int l, int color);
void gotoxy(int x, int y);
void textcolor(int color);

/****************************************************************
CREATION DE CIRCUIT
*****************************************************************/
void create_circuit1(void) {
	//Définition du circuit 
	D1 = EST;
	P1 = 10;
	D2 = SUD;
	P2 = 10;
	D3 = OUEST;
	P3 = 10;
	D4 = NORD;
	P4 = 10;
	NBTRAIT = 4;
	NBTOUR = 2;

	//la voiture 
	X = STARTX;
	Y = STARTY;
	PAS = 0;
	IDTRAIT = 0; 
	TOUR = 0; 
	VIT = 0;

}

/****************************************************************
AVANCER
*****************************************************************/
//Sélection du trait à parcourir 
void select_trait(void) {
	//controler si un tour est effectué et afficher le nombre de tours réalisés 
	if (IDTRAIT == NBTRAIT) {
		TOUR++;
		IDTRAIT = 0;
		gotoxy(TX/2, TY/2);
		textcolor(12); //couleur vert
		printf("TOUR: %d, TOUR", TOUR);
	}

	//changement de vitesse de la voiture 
	VIT = 150 + rand() % 150;

	//sélection du trait 
	switch (IDTRAIT) {
		case 0: //trait 1
			DIR = D1;
			PAS = P1;
			break;
		case 1: //trait 2
			DIR = D2;
			PAS = P2;
			break;
		case 2: //trait 3
			DIR = D3;
			PAS = P3;
			break;
		case 3: //etc
			DIR = D4;
			PAS = P4;
			break;
		case 4: 
			DIR = D5;
			PAS = P5;
			break;
		case 5:
			DIR = D6;
			PAS = P6;
			break;
	}
	//préparer le trait suivant 
	IDTRAIT++;
}
//Parcourir le trait suivant
void avancer(int l, int color1, int color2) {
	//supprimer un pas 
	if (PAS > 0)
	{
		PAS--;
		//effacer
		afficher(X, Y, l, color1);

		//déplacer selon la direction 
		switch (DIR)
		{
		case NORD: Y--;
			break;
		case SUD: Y++;
			break;
		case EST: X++;
			break;
		case OUEST: X--;
			break;
		}

		//afficher la nouvelle position 
		afficher(X, Y, l, color2);
	}
		
}
/****************************************************************
AFFICHER
*****************************************************************/

void afficher(int x, int y, int l, int color) {
	gotoxy(X, Y);
	textcolor(color);
	putchar(l);
}

/****************************************************************
OUTILS
*****************************************************************/
void gotoxy(int x, int y) {
	COORD c; 
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void textcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

/****************************************************************
ACTION
*****************************************************************/

int main()
{
	int start = 0; // pour contrôler le temps 

	srand(time(NULL));

	//Création et initialisation de la voiture 

	create_circuit1();
	while (TOUR < NBTOUR)
	{
		//contrôle vitesse voiture 
		if (clock() > start + VIT) {
			start = clock();

			//nouveau trait ?
			if (PAS == 0) 
				select_trait();

			//avancer, lettre v pour voiture 
			//effacement en noir, vouleur voiture rouge 
			avancer('v', 0, 10);
			
		}
	}

	gotoxy(0, TY);
	system("PAUSE");
	return 0;
}

