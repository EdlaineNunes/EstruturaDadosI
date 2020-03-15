#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n, aux = 0;
	printf("Digite o valor de N: ");
	scanf(" %d",&n);
	for (int i = 1; i < n; i++)
		if (n % i)
			continue;
		else
			aux+=i;
	printf("\n\tSoma: %d\n\n",aux);
	if (aux == n)
		printf("%d é um número perfeito!\n",n);
	else
		printf("%d NÃO é um número perfeito!\n",n);
	return 0;
}

