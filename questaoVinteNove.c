#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//quase funcional

/*29. Declare um vetor de K números inteiros e preencha-o com números informados pelo usuário.
Imprima o vetor original, e o número de comparações e permutações necessárias para ordenação do vetor utilizando
os seguintes algoritmos de ordenação: Bubble Sort e Selection Sort. Imprima também o vetor após a ordenação.*/

int main(int argc, char **argv)
{
	srand(time(NULL));
	int k,a,rep=0;
	printf("Digite o valor de K: ");
	scanf(" %d",&k);
	int vet[k];
	
	for (int i=0; i<k; i++){
		do{
			rep=0;
			a = rand()%100;
			for (int j=0; j<i; j++)
				if(vet[j]==a)
					rep = 1;
		}while(rep==1);
		vet[i] = a;
		printf("%d\t",vet[i]);
	}
	
	//bubble sort
	printf("\n\n\t\t =======ORDENAÇÃO======\n");
	for(int i=0; i<k; i++)
		for (int j=0; j<k-1-i; j++)
			if(vet[j]>vet[j+1]){
				int aux = vet[j];
				vet[j]=vet[j+1];
				vet[j+1]=aux;
			}
	
	for (int i=0; i<k; i++)
		printf("%d\t",vet[i]);
	return 0;
}
