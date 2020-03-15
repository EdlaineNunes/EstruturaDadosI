#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	/*
	int vet[8], n, cont;
	for(int i=1; i<=8; i++){
		printf("Digite o %dº valor:\t",i);
		scanf(" %d",&vet[i]);
	}
	printf("\n\nDigite o valor de N:");
	scanf(" %d",&n);
	for(int i=0; i<8; i++)
		if ( n == vet[i] )
			cont++;
	printf("\nO número %d se repetiu %d vezes.",n,cont);
	return 0;
*/
	srand(time(NULL));
	int n, lim, pesq, cont=0;
	printf("Digite o tamanho do vetor: ");
	scanf(" %d",&n);
	printf("Digite o limite de intervalo do sorteio: ");
	scanf(" %d",&lim);
	int vet[n];
	for(int i=0; i<n; i++)
		vet[i] = rand () % ( lim+1 );
	printf("\n\n\t\t\tVetor: \n");
	for(int i=0; i<n; i++)
		printf("%d -\t",vet[i]);
		
	printf("\n\nDigite o valor a ser pesquisado: ");
	scanf(" %d",&pesq);
	for (int i =0; i<n; i++)
		if ( pesq == vet[i])
			cont++;
	printf("\n\t\tO número %d foi sorteado %d vezes.",pesq,cont);
	
	
	
}

