/* A résoudre 
//=========== UNE FOURMI MOBILE A L'ECRAN ==================

//l'objectif est de faire circuler une fourmi à l'écran. Elle ne se nourrit pas et ne rencontre pas d'autres bestiole
// Elle se contente de bouger 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

//définition globale d'une structure fourmi
typedef struct {

	float x, y; //position 
	float dx, dy; //déplacement
	int lettre; //apparence
	int color;	//couleur 
} fourmi;

//les limites du jeu 
const int TX=40;
const int TY=20; 

fourmi init(void);
void afficher(fourmi f, int color);
fourmi avancer(fourmi f);
int top(int *start, int dur);
void gotoxy(int x, int y);
void textcolor(int color);

//**************************** ACTION ****************************************************

int main()
{
	int start = 0;
	fourmi f;
	srand(time(NULL));

	f = init();

	while (!_kbhit())
	{
		if (top(&start, 75)) {
			afficher(f, 0);
			f = avancer(f);
			afficher(f, f.color);
		}
	}
}
*/
