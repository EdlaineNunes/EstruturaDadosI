#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Crie um programa que receba um número e verifique se ele é um número triangular. 
Um número é triangular quando é resultado do produto de três números consecutivos. 
Exemplo: 120 = 4 x 5 x 6.*/

int main(int argc, char **argv)
{
	int n;
	printf("Insira o valor de N: ");
	scanf(" %d",&n);
	int aux, i;
	for (i = 1; i <= 9; i++){
		aux = i * ( i + 1 ) * ( i + 2 );
		if ( aux == n ){
			printf("\n\tO numero %d é triangular perfeito.\nEle é produto dos números: %d, %d e %d",n,i, i+1, i+2);
			return 0;
		}
	}
	printf("\nNÃO É TRIANGULAR PERFEITO");
	
	return 0;
}

