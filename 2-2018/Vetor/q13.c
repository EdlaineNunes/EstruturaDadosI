#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Crie um programa que calcule o M.M.C (mínimo múltiplo comum) e o M.D.C
(máximo divisor comum) entre dois números lidos. (p. ex.: MMC (10, 15) = 30 
e MDC (10, 15) = 5 .*/

int main(int argc, char **argv)
{
	//NÃO FUNCIONAL
	int x, y, aux = 1;
	printf("Digite o valor de X: ");
	scanf(" %d",&x);
	printf("Digite o valor de Y: ");
	scanf(" %d",&y);
	int maior = 0, menor = 99999999;
	if (x <= maior){
		maior = x;
		menor = y;
	}
	else {
		maior = y;
		menor = x;
	}
	printf("%d maior, %d menor\n",maior,menor);
	
	
	return 0;
}

