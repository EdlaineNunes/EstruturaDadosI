#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n,soma = 0, cont = 0, par = 0,impar = 0,maior = 0, menor = 9999999;
	float media,percpar, percimp;
	printf("Digite os números: ");
	do{
		scanf(" %d",&n);
		if (n<0)
			break;
		if (n%2)
			impar++;
		else 
			par++;
		if (maior <= n)
			maior = n;
		if (menor >= n)
			menor = n;
		soma += n;
		cont++;
		
	}while(1);
	
	media = (float)soma / cont;
	percpar = ( par * 100 ) / cont;
	percimp = ( impar * 100 ) / cont;
	printf("Soma: %d\n",soma);
	printf("Números digitados: %d\n",cont);
	printf("Média: %.2f\n",media);
	printf("Maior valor: %d\n",maior);
	printf("Menor valor: %d\n",menor);
	printf("Qnt numeros Pares: %d, percentual de %.2f%%\n",par,percpar);
	printf("Qnt numeros Impar: %d, percentual de %.2f%%\n",impar,percimp);
	
	return 0;
}

