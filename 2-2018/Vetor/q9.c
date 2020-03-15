#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n,primo = 1;
	printf("Digite um número: ");
	scanf(" %d",&n);
	if (n%2)
		primo = 0;
	if (primo)
		printf("NÃO é primo!");
	else
		printf("Primo!");
	return 0;
}

