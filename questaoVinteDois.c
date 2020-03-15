#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//FUNCIONAL

/* Gere um vetor de K posições (0 < K < 1000) com valores aleatórios 
 * entre 0 e 1000. Conte e escreva quantos valores pares e ímpares 
 * ele possui. Imprima o maior e o menor valor. Calcule também a 
 * média destes valores, e a quantidade de números acima da média. */

int main(int argc, char **argv)
{
	srand (time (NULL));
	int k,par=0,impar=0,maior=0, menor=1001,soma=0,n=0;
	float media;
	printf("Digite o valor de K>0 e K<1000: ");
	scanf("%d",&k);
	int v[k];
	
	for (int i=0; i<k; i++){
		v[i]= rand()%1001;
		printf("%d\t",v[i]);
		if (v[i]%2==0)
			par++;					
		if (v[i]>maior)
			maior = v[i];
		if (v[i]<menor)
			menor = v[i];
		soma+=v[i];
		
	}
	printf("\n\n");
	printf("%d valores pares",par);
	impar = k - par;
	printf("\n%d valores ímpares",impar);
	printf("\nMaior valor: %d",maior);	
	printf("\nMenor valor: %d",menor);
	media = (float)soma / k;
	printf("\nA média deles é: %2.2f",media);
	
	for (int i=0; i<k; i++){
		if (v[i]>media){
			n++;
		}
	}
	printf("\nTemos %d números acima da média",n);
	
	return 0;
}

