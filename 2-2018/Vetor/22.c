#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


int main(int argc, char **argv)
{
	srand(time(NULL));
	int k;
	do{
		printf("Digite o tamanho de K: ");
		scanf(" %d",&k);
		if ((k<=0) || (k>=1000))
			printf("\n\t\tNUMERO INVÁLIDO!\n\n");
		else 
			break;
	}while(1);
	
	int vet[k],rep=0,cont=0,maior = 0, menor = 999999,contim=0, contpar=0,soma=0;
	int acmedia=0, abmedia=0, igmedia=0;
	
	do{
		int aux = rand () % (1000+1);
		rep = 0;
		for (int i=0; i<cont; i++)
			if(aux == vet[i]){
				rep = 1;
				break;
			}
		if(rep) 
			continue;
		vet[cont] = aux;
		printf("%d\t",vet[cont]);
		if( vet[cont] >= maior )
			maior = vet[cont];
		if ( vet[cont] <= menor )
			menor = vet[cont];
		if ( vet[cont] % 2 )
			contim++;
		else
			contpar++;
		soma += vet[cont];
		cont++;
	}while(cont<k);
	
	printf("\n\n\nMaior: %d",maior);
	printf("\nMenor: %d",menor);
	printf("\nQnt de ímpares: %d",contim);
	printf("\nQnt de pares: %d",contpar);
	float media = (float) soma / cont;
	printf("\nMédia: %.2f",media);
	
	for (int i=0; i<cont; i++){
		if (vet[i] > media)
			acmedia++;
		if (vet[i] < media)
			abmedia++;
		if (vet[i] == media)
			igmedia++;
	}
	
	printf("\nAcima da média: %d",acmedia);
	printf("\nAbaixo da média: %d",abmedia);
	printf("\nIguais a média: %d",igmedia);
	return 0;
}

