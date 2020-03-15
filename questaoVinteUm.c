#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//FUNCIONAL

/*21. Um baralho tem N cartas, não-repetidas, numeradas entre 1 e N. Faça um programa que leia o valor de N e
embaralhe todas as cartas. Imprima ao final a sequencia de cartas do baralho.*/

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n, rep,a;
	printf("Digite o valor de N: ");
	scanf(" %d",&n);
	int vet[n];
	printf("\nO sorteio é:\n");
	for (int i=0; i<n; i++){
		do{
			a = 1 + rand()%n;
			rep = 0;
			for (int j=0; j<i; j++)
				if (vet[j]== a)
					rep=1;
		}while(rep==1);
	vet[i] = a;
	printf("%d\t",vet[i]);
	}
	return 0;
}

