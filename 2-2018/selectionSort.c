#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 7

int main(int argc, char **argv)
{
	int vet[N] = {7,3,5,1,4,6,9};
	int aux,min;
	//SELECTION SORT
	for(int i = 0; i < N; i++){
		min = i;
		for(int j = i+1; j < N; j++){
			if(vet[j] < vet[min])
				min = j;
		}
		aux = vet[i];
		vet[i] = vet[min];
		vet[min]= aux;	
	}
	for(int k = 0; k < N; k++){
		printf(" %d  ", vet[k]);
	}
	
	return 0;
}

