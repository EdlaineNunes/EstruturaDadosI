#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	int k, menor = 999999999, maior = 0, soma = 0,sorte, n, cont = 0;
	float media;

	printf("Digite o valor de K: ");
	scanf(" %d",&k);
	printf("Digite o valor de N: ");
	scanf(" %d",&n);
	for (int i = 1; i <= n; i++){
			sorte = rand () % (k + 1);
			printf("%d\t",sorte);
			if (menor >= sorte)
				menor = sorte;
			if (maior <= sorte)
				maior = sorte;
			soma += sorte;
			cont++;
		}

	media = (float) soma / cont;
	printf("\nO maior é: %d",maior);
	printf("\nO menor é: %d",menor);
	printf("\nA média deles é: %.2f",media);
	
	return 0;
}

