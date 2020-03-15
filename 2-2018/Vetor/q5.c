#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int aleatorio;
	srand(time(NULL));
	aleatorio = rand () % 1000;
	printf("O número sorteado foi: %d",aleatorio);
	if ( aleatorio < 10 ) 
		printf("\nO número aleatório tem 1 dígito.");
	if (( aleatorio >= 10 ) && ( aleatorio <= 99 ))
		printf("\nO número aleatório tem 2 dígitos.");
	if (( aleatorio >= 100 ) && ( aleatorio <= 999 ))
		printf("\nO número aleatório tem 3 dígitos.");
	if (( aleatorio >= 1000 ) && ( aleatorio <= 9999 ))
		printf("\nO número aleatório tem 4 dígitos.");

	return 0;
}

