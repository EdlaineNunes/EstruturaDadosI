#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n;
	srand (time(NULL));
	printf("Digite um número: \n");
	scanf(" %d",&n);	
	do{
		int aleatorio =rand()%n;
		printf("O número aleatorio sorteado foi: %d",aleatorio)}
	
	
	return 0;
}

