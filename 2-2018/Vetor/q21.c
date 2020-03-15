#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Um baralho tem N cartas, não-repetidas, numeradas entre 1 e N.Faça um 
programa que leia o valor de N e embaralhe todas as cartas. Imprima ao 
final a sequência de cartas do baralho.*/

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n, i=0, rep;
	printf("Digite o valor de N:");
	scanf(" %d",&n);
	int vet[n];
	do{
		int aux = 1 + rand()% n ;
		rep=0;
		for(int t=0; t<i; t++)
			if(aux==vet[t]){
				rep=1;
				break;
			}
		if(rep)
			continue;
		vet[i] = aux;
		printf("%d\t",vet[i]);
		i++;
	}while(i<n);
	
	return 0;
}

