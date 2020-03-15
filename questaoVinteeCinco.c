	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <time.h>
	#include <math.h>
	
	//FUNCIONAL
	
	/*25. Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre X e Y. O
	programa deve informar a posição (índice) onde se encontra o menor número sorteado, seguido da posição onde se
	encontra o segundo menor número sorteado, e assim sucessivamente...*/
	
	int main(int argc, char **argv){
	srand(time(NULL));
	int n,x,y;
	printf("Digite o valor de N: ");
	scanf(" %d",&n);
	printf("DEFININDO O INTERVALO\n");
	printf("Digite o valor de X: ");
	scanf(" %d",&x);
	printf("Digite o valor de Y: ");
	scanf(" %d",&y);
	int vet[n];
	int vaux[n];
	//preenchendo os dois simultaneamente
	for (int i=0; i<n; i++){
		int a = x + rand() %(y-x-1);
		vet[i]=a;
		vaux[i]=a;
	}
	//ordenação do vetor copia "vaux"
	//bubble sort
	for (int i=0; i<n; i++){
		for (int j=0; j<n-1-i; j++){
			if (vaux[j] > vaux[j+1]){
				int aux = vaux[j]; 
				vaux[j] = vaux[j+1];	
				vaux[j+1] = aux;				
			}
		}
	}
	
	printf("\n\n\n\t\t\t VETOR Original\n");
	for (int i=0; i<n; i++) 
			printf("%d \t",vet[i]);
	
	//nao precisa exibir esse vetor, mas okay
	printf("\n\n\n\t\t\t VETOR ORDENADO\n");
	for (int i=0; i<n; i++) 
		printf("%d \t",vaux[i]);
	int cont=0;
	
	//procurando por meio do vetor auxiliar o menor numero no vetor original
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (vaux[i] == vet[j]){
				vet[j]--;
				cont++;			
				printf("\nO %dº menor nº (%d), está no índice %d",cont,vaux[i],j);
			}
	
	return 0;
	}
	
	
