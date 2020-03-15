#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//PARCIALMENTE PARCIAL

/*25. Faça um programa que preencha um vetor com N números aleatórios, sorteados no intervalo entre X e Y. O
programa deve informar a posição (índice) onde se encontra o menor número sorteado, seguido da posição onde se
encontra o segundo menor número sorteado, e assim sucessivamente...*/

int main(int argc, char **argv)
{
	srand(time(NULL));
	int n,a,x,y;
	printf("Digite o valor de N: ");
	scanf(" %d",&n);
	printf("Determinando o INTERVALO ");
	
	printf("\nDigite o valor de X: ");
	scanf(" %d",&x);
	printf("Digite o valor de Y: ");
	scanf(" %d",&y);
	int vet[n];
	int vaux[n];
	//montando os dois vetores
	for (int i=0; i<n; i++){
		vet[i]= x+rand()% (y-x-1); //testar -1 fora
		printf("%d\t",vet[i]);
		vaux[i]=0;
		printf("%d\t",vaux[i]);
	}	
	printf("\n");
	//validação do vetor
	int menor = 1000, indice=0,cont=0;
	for (int i=0; i<n; i++){
		//do{
			if(vet[i]<=menor){
				indice = i;
				menor = vet[i];
				cont+=1;
				vaux[i]=1;
			}
			printf("%d\t",vaux[i]);
		
		//}while(i<=n);
		
	}
	
	return 0;
}

