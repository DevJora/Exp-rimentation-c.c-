/*#include <stdio.h>
#include <stdlib.h>


int main() {
	//avoir une variable <type> <identificateur> <;>
	//le type défini la taille prise en mémoire par la variable 

	//instrucstions avec le type int 
	int toto; //déclaration/ réservation en mémoire 
	toto = 10; //affactation de la valeur 10 à toto

	//------------------------------------------------------------
	//les autres types de variable en C et leur place en mémoire 
	char c = 'A'; // 1 octet, codage ASCII
	short s = 10; // 2  octets 
	int i = 20; // 2 ou 4 octets 
	long l = 456; // 4 octets 
	float f = 3.84; // 4 octects 
	double d = 44995.5968534059; // 8 octets 

		//-----------------------------------------------------------
		// pour afficher une valeur
		// chaque format a son type :
		// char %c, short, int, long %d, float %f, double %lf
		// adresse mémoire %p
		printf_s("i vaut : %d. \n", i);
		printf_s("Autre exemple:\n");

		//chaque valeur ASCII correspond à une valeur numérique
		printf_s("c est la lettre: %c. Sa valeur numérique: %d. Son adresse: %p. Sa taille: %d.\n", c, c, &c, sizeof(c));

		//entrée d'un utilisateur 
		printf_s("test de scanf()\nEntrez une valeur:");
		scanf_s("%d", &s);
		printf("s a change de valeur. s n'est plus egale a 10. s est egale a %d.\n", s);

		//les valeurs sont exécutées de façon linéaire les unes après les autres.
		return 0; //valeur retour pour communication avec le système.

	
}*/