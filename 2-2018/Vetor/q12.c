#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Faça um programa que leia dois valores inteiros X e Y, tal que Y >=X. 
O programa deverá sortear N valores no intervalo entre X e Y (inclusive).
Obs.: Os números sorteados no intervalo entre X e Y não podem ser gerados 
por lógica de tentativa e erro!*/

int main(int argc, char **argv)
{
	int x, y, sorte, cont;
	srand(time(NULL));
	do{
		printf("Digite o valor de X: ");
		scanf(" %d",&x);
		printf("Digite o valor de Y: ");
		scanf(" %d",&y);
		if ( y >= x){
			printf("Digite quantas vezes deseja sortear: ");
			scanf(" %d",&cont);
			for( int i = 1; i <= cont; i++){
				sorte = x + rand() % ( 1 + y - x );
				printf("%dº n sorteado: %d\n",i,sorte);
			}
			break;
		}
		else
			printf("\n\tY precisa ser igual ou maior a X!\n\n");
	
	}while(1);
	
	return 0;
}

