#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int x,y;
	int soma;
	printf("OBS: X e Y negativos ENCERRAM\n\n");
	do{
		printf("Digite um número:\n");
		scanf(" %d",&x);
		printf("Digite um número maior que o anterior:\n");
		scanf(" %d",&y);
		if ((x<0)&&(y<0)) break;
		soma=0;
		do{
			soma = x + soma;
			x++;
		}while(x<=y);	
		printf("A soma dos intervalos de x e y é: %d\n",soma);
	}while (1);	
	return 0;
	
	
	return 0;
}

