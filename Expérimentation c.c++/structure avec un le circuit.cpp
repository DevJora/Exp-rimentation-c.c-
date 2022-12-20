//On va rajouter quatre voiture au programme du circuit 
//Implémentation de course à plusieurs voitures afin de tester la montée en puissance donnée par un type  de données, tableau ou structure 

/*Principe de circuit
- Un circuit est considéré comme un ensemble de traits
- Chaque trait correspond à une direction et à un nombre de pas dans cette direction
- Nord  = 0, Est = 1, Sud = 2, ouest = 3.
- pour avoir un circuit il faut une position de départ et plusieurs traits
- Pour suivre le circuit il faut parcourir chaque trait l'un après l'autre

Le circuit ici est un carré

*/
/*
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

//pour avoir un circuit
typedef struct {
	int P1, D1, P2, D2, P3, D3, P4, D4, P5, D5, P6, D6, NBTRAIT, NBTOUR;
} circuit;

//pour une voiture
typedef struct {
	int X, Y, VIT, DIR, PAS, IDTRAIT, TOUR, tmps, lettre, color1, color2;
} voiture;


// les fonctions
circuit create_circuit1(void);
voiture create_voiture(int startx, int starty, int c1, int c2, int l);
voiture bouge(voiture v, circuit c);
int run(voiture v1, voiture v2, voiture v3, voiture v4, circuit c);
voiture select_trait(voiture v, circuit c);
voiture avancer(voiture v);
void afficher(voiture v, int color);
int top(voiture v);
void gotoxy(int x, int y);
void textcolor(int color);

//****************************************************************
//CREATION DE CIRCUIT ET VOITURE
//*****************************************************************
circuit create_circuit1(void) {
	//Définition du circuit

	circuit c;
	c.D1 = EST;
	c.P1 = 10;
	c.D2 = SUD;
	c.P2 = 10;
	c.D3 = OUEST;
	c.P3 = 10;
	c.D4 = NORD;
	c.P4 = 10;
	c.NBTRAIT = 4;
	c.NBTOUR = 2;

	return c;

}

voiture create_voiture(int startx, int starty, int c1, int c2, int l)
{
	//la voiture
	voiture v;
	v.X = STARTX;
	v.Y = STARTY;
	v.PAS = 0;
	v.tmps = 0;
	v.IDTRAIT = 0;
	v.TOUR = 0;
	v.VIT = 0;
	v.color1 = c1;
	v.color2 = c2;

	return v;
}
//****************************************************************
//AVANCER ET BOUGER
//*****************************************************************
// La course continue tant qu'aucune voiture n'a fini
//Sélection du trait à parcourir

int run(voiture v1, voiture v2, voiture v3, voiture v4, circuit c) {
	return (v1.TOUR < c.NBTOUR && v2.TOUR < c.NBTOUR && v3.TOUR < c.NBTOUR && v4.TOUR < c.NBTOUR);
}
int top(voiture v) {
	return(clock() > v.tmps + v.VIT);
}

voiture bouge(voiture v, circuit c) {
	if (top(v)) {
		v.tmps = clock();
		if (v.PAS == 0) {
			v = select_trait(v, c);
			v = avancer(v);
		}
	}

	return v;
}
voiture select_trait(voiture v, circuit c) {
	//controler si un tour est effectué et afficher le nombre de tours réalisés
	if (v.IDTRAIT == c.NBTRAIT) {
		v.TOUR++;
		v.IDTRAIT = 0;
		gotoxy(TX/2, TY/2);
		textcolor(12); //couleur vert
		printf("TOUR: %d, TOUR", v.TOUR);
	}

	//changement de vitesse de la voiture
	v.VIT = 150 + rand() % 150;

	//sélection du trait
	switch (v.IDTRAIT) {
		case 0: //trait 1
			v.DIR = c.D1;
			v.PAS = c.P1;
			break;
		case 1: //trait 2
			v.DIR = c.D2;
			v.PAS = c.P2;
			break;
		case 2: //trait 3
			v.DIR = c.D3;
			v.PAS = c.P3;
			break;
		case 3: //etc
			v.DIR = c.D4;
			v.PAS = c.P4;
			break;
		case 4:
			v.DIR = c.D5;
			v.PAS = c.P5;
			break;
		case 5:
			v.DIR = c.D6;
			v.PAS = c.P6;
			break;
	}
	//préparer le trait suivant
	v.IDTRAIT++;

	return v;
}
//Parcourir le trait suivant
voiture avancer(voiture v) {
	//supprimer un pas
	if (v.PAS > 0)
	{
		v.PAS--;
		//effacer
		afficher(v, v.color2);

		//déplacer selon la direction
		switch (v.DIR)
		{
		case NORD: v.Y--;
			break;
		case SUD: v.Y++;
			break;
		case EST: v.X++;
			break;
		case OUEST: v.X--;
			break;
		}

		//afficher la nouvelle position
		afficher(v , v.color2);
	}

	return v;
}
//****************************************************************
//AFFICHER
//*****************************************************************

void afficher(voiture v, int color) {
	gotoxy(v.X, v.Y);
	textcolor(color);
	putchar(v.lettre);
}

//****************************************************************
//OUTILS
//*****************************************************************
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void textcolor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

//****************************************************************
//ACTION
//*****************************************************************

int main()
{
	circuit c;
	voiture v1, v2, v3, v4;

	srand(time(NULL));
	c = create_circuit1();
	v1 = create_voiture(2, 2, 0, 10, '1');
	v2 = create_voiture(3, 3, 1, 11, '2');
	v3 = create_voiture(4, 4, 2, 12, '3');
	v4 = create_voiture(5, 5, 0, 13, '4');



	//Création et initialisation de la voiture

	while (run(v1, v2, v3, v4, c))
	{
		//généralisé pour toutes les voitures avec bouge()
		if (top(v1)) {
			v1.tmps = clock();
			if (v1.PAS == 0) 
				v1 = select_trait(v1, c);
				v1 = avancer(v1);
		}
		if (top(v2)) {
			v2.tmps = clock();
			if (v2.PAS == 0)
				v2 = select_trait(v2, c);
			v2 = avancer(v2);
		}
		if (top(v3)) {
			v3.tmps = clock();
			if (v3.PAS == 0)
				v3 = select_trait(v3, c);
			v3 = avancer(v3);
		}
		if (top(v4)) {
			v4.tmps = clock();
			if (v4.PAS == 0)
				v4 = select_trait(v4, c);
			v4 = avancer(v4);
		}

		//bouge() par voiture 
		v1 = bouge(v1, c);
		v2 = bouge(v2, c);
		v3 = bouge(v3, c);
		v4 = bouge(v4, c);
		}
	gotoxy(0, TY);
	system("PAUSE");
	return 0;
	}
	

	*/

