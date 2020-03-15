#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Faça um programa que leia do usuário dois números X e Y tal que Y >= X.
Faça com que o programa imprima todos os números primos existentes entre 
X e Y, inclusive*/

int main(int argc, char **argv)
{
	int x, y;
	do{
		printf("Insira o valor de X: ");
		scanf(" %d",&x);
		printf("Insira o valor de Y: ");
		scanf(" %d",&y);
		if ( y >= x)
			break;
		else
			printf("\n\tATENÇÃO! Y PRECISA SER > QUE X.\n\n");
	}while(1);
	
	return 0;
}

