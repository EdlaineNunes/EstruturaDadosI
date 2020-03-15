#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//void é PROCEDIMENTO, int é FUNÇÃO
//get da return (int), set nao(void)

int getPrimo(){
	
	int auxp,primo=0;
	do{
		auxp = 2 + rand () % 200;
		primo=0;
		for (int i=2; i<auxp; i++)
			if (auxp%i==0)
				primo = 1;
		if (primo == 0)	
			return auxp;
	}while (1);
}


void setVetorPrimo (int vet[], int n) {
	for (int i=0; i<n; i++)
		vet[i] = getPrimo();
}

void setImpressao (int vet[], int n){
	for (int i=0; i<n; i++)
		printf("%d ",vet[i]);	
}

int getMaior(int vet[], int t){
	int maior = 0;
	for (int i=0; i<t;i++)
		if (vet[i] >= maior)
			maior = vet[i];
	return maior;
}

int getMenor(int vet[], int t){
	int menor = 201;
	for (int i=0; i<t; i++)
		if (vet[i]<=menor)
			menor = vet[i];
	return menor;	
}

int main(int argc, char **argv)
{
	srand(time (NULL));
	int n;
	printf("Determine o tamanho do vetor: \n");
	scanf(" %d",&n);
	int vet[n];
	setVetorPrimo (vet,n);
	setImpressao (vet, n);
	getMaior (vet,n);
	printf("\nO maior número é: %d\n",getMaior(vet,n));
	getMenor (vet,n);
	printf("\nO menor número é: %d\n",getMenor(vet,n));
	return 0;
}

