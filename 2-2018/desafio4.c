#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//DESAFIO 24 e 27
//jogo da memoria, calcular qntas tentativas feitas pelo usuario. SORTEIO n rep
int main(int argc, char **argv)
{
	srand(time(NULL));
	int aux,vet[50],rep,i=0;
	printf("\t\tJOGO DA MEMÓRIA\n\n");
	printf("O intervalo de sorteio é 0 a 50.\n");
	do{
		aux = rand () % ( 50 + 1 );
		rep=0;
		for(int i=0; i<50; i++)
			if( aux == vet[i] )
				rep = 1;
		if (rep)
			continue;
		vet[i] = aux;	
		printf("O numero sorteado foi: %d\n",vet[i]);
		i++;	
		
	}while(i<10);
	return 0;
}

