/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	
	printf("*************** Operateur bit a bit *****************\n\n");
	//opérateur bit à bit;
	int a = 2;// a = 10
	int b = 3;// b = 11
	printf_s("a = %d\n", a);
	printf_s("b = %d\n", b);
	a ^= b; //a = 01
	printf_s("a = %d\n", a);
	b ^= a; //b = 10
	printf_s("b = %d\n", b);
	a ^= b; //a = 11
	printf_s("a = %d, b = %d\n", a, b);
	printf("\n");
	printf("Autre exemple\n");
	//expérimentation: opération bit à bit
	int x = 1;//01 
	int y = 2;//10
	int z = 3;//11
	printf("%d\n", x);
	printf("%d\n", y);
	printf("%d\n", x | y & z); //11, 3 
	printf("%d\n", x | y & z); //00, 0 correction => 01, 1
	printf("%d\n", x ^ z & y); // 10, 2 correction => 11, 3
	printf("%d\n", x & y & z); //00, 0

	//x >>= 3;
	//y <<= 3;
	
	printf_s("********** Operations arithmetiques ***********\n\n");
	int c = 90, d = 10; 

	//les  différents opérateurs arithmétiques sont +, -, *, /, %
	printf_s("ADDITION\n");
	printf_s("a + b = %d\n", c + d);
	printf_s("SOUSTRACTION\n");
	printf_s("a - b = %d\n", c - d);
	printf_s("MULTIPLICATION\n");
	printf_s("a * b = %d\n", c * d);
	printf_s("DIVISION\n");
	printf_s("a / b = %d\n", c / d);
	printf_s("MODULO\n");
	printf_s("a % b = %d\n\n", c % d);
	
	printf_s("INCREMENTATION\n");
	int i = 0;
	printf_s("Post incrementation\n");
	printf_s("i++ = %d\n", i++);//affiche toujours i mais l'incrémente après l'exécution
	printf_s("Pre incrementation\n");
	printf_s("++i = %d\n", ++i);
	printf_s("DECREMENTATION\n");
	int j = 5;
	printf_s("Post decrementation\n");
	printf_s("j-- = %d\n", j--);
	printf_s("Pre decrementation\n");
	printf_s("--j = %d\n", --j);//affiche toujours j mais le décrémente après l'exécution


	printf_s("****************Valeurs aleatoires******************\n");
	i = rand();// la fonction rand retourne le resultat d'une suite et donnera toujours ce résultat 
	printf_s("i = %d\n", i);
	i = rand() % 10; // un nombre au hasard dans la fourchette de 0 et 9
	printf_s("i = %d , [0, 9] \n", i);
	i = 5 + rand() % 10; // entre 5 et 5 +9
	printf_s("i = %d , [5, 14] \n", i);

	//Chaque fois qu'on exécutera le programme il donnera toujours le même résultat partant d'une même suite.
	//Pour avoir un résultat différent il faut initialiser la suite de nombre aléatoire en fonction de l'horloge.

	srand(time(NULL));

	float f = (float)rand() / RAND_MAX;//obtient un nombre entre 0 et 1
	printf_s("f = %f , [0, 1] \n", f);
	double d = ((float)rand() / RAND_MAX)*10;//obtient un nombre entre 0 et 10
	printf_s("d = %f , [0, 10] \n", d);




	return 0;
}*/