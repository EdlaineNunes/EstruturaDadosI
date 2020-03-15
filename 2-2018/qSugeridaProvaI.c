#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define TAM 10

int main()
{
	int x[TAM], y[TAM], z[TAM];
	srand(time(NULL));
	
	for(int i=0; i<10; i++){
		x[i] = rand()%100;
		y[i] = rand()%100;
		z[i] = rand()%100;
	}
	
	for(int i=0; i<TAM; i++)
		printf("x: %d\t",x[i]);
	printf("\n\n\n");
	for(int i=0; i<TAM; i++)
		printf("y: %d\t",y[i]);
	printf("\n\n\n");
	for(int i=0; i<TAM; i++)
		printf("z: %d\t",z[i]);
	//ordenação de x	
	for(int i=0; i<TAM; i++)
		for(int j=0; j<TAM - i - 1; j++)
			if(x[j] > x[j+1]){
				int aux = x[j];
				x[j] = x[j+1];
				x[j+1] = aux;				
			}
	printf("\n\n\nX ORDENADO\n");
	for(int i=0; i<TAM; i++)
		printf("x: %d\t",x[i]);
	//ordenação de y
	for(int i=0; i<TAM; i++)
		for(int j=0; j<TAM - i - 1; j++)
			if(y[j] > y[j+1]){
				int aux = y[j];
				y[j] = y[j+1];
				y[j+1] = aux;				
			}
	printf("\n\n\nY ORDENADO\n");
	for(int i=0; i<TAM; i++)
		printf("Y: %d\t",y[i]);
	//ordenação de z
	for(int i=0; i<TAM; i++)
		for(int j=0; j<TAM - i - 1; j++)
			if(z[j] > z[j+1]){
				int aux = z[j];
				z[j] = z[j+1];
				z[j+1] = aux;				
			}
	printf("\n\n\nZ ORDENADO\n");
	for(int i=0; i<TAM; i++)
		printf("Z: %d\t",z[i]);
		
	
	
	
	
	
	return 0;
}

