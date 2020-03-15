#include <stdio.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

#define N 9

int main(int argc, char **argv){
	srand(time(NULL));
	int cont=9;
	int vet[N],vetaux[N],trinca = 0,pos=0;
	for(int i=0; i<	N; i++)
		vet[i] = 1 + rand () % 13;
	printf("\n==============================================\n");
	printf("Cartas sorteadas:\n");
	for(int i=0; i<	N; i++){
		printf("%d ",vet[i]);
		vetaux[i] = vet[i];
	}
	//ordenação
	for(int i=0; i<N; i++)
		for(int j=0; j<N-1-i; j++)
			if(vetaux[j] > vetaux[j+1]){
				int aux = vetaux[j];
				vetaux[j] = vetaux[j+1];
				vetaux[j+1] = aux;				
			}

	
	printf("\n\nTodas as cartas ordenadas:\n");
	for(int i=0; i<cont; i++)
		printf("%d ",vetaux[i]);
		
	printf("\n==============================================\n");
	printf("\n");
	do{
		for(int i=0; i<cont; i++)
			printf("%d ",vetaux[i]);
		//jogo
		for(int i=0; i<cont; i++){
			// 2 3 4 
			if((vetaux[i] == vetaux[i+1]) && (vetaux[i] == vetaux[i+2]) && (i < N)){ 
				trinca++;
				pos = i;
				vetaux[i] = 20;
				vetaux[i + 1] = 20;
				vetaux[i + 2] = 20;
				cont -= 3;
				
			}
			
			if((vetaux[i] < vetaux[i+1]) && (vetaux[i] < vetaux[i+2]) && (i < N)){
				int a = vetaux[i+1];
				int b = vetaux[i+2];
				if(vetaux[i] == (a - 1) && vetaux[i] == (b - 2)){
					trinca++;
					vetaux[i] = 20;
					vetaux[i + 1] = 20;
					vetaux[i + 2] = 20;
					cont-=3;
					
				}
			}
			
		}
		//ordenação
		for(int i=0; i<N; i++)
			for(int j=0; j<N-1-i; j++)
				if(vetaux[j] > vetaux[j+1]){
					int aux = vetaux[j];
					vetaux[j] = vetaux[j+1];
					vetaux[j+1] = aux;				
				}
	
		printf("\nTrincas: %d",trinca);
		printf("\n\n");
		
		printf("Cartas na mão:\n");
		for(int i=0; i<cont; i++)
			printf("%d ",vetaux[i]);
		if(trinca == 3){
			printf("\n\n\t\tPARABÉNS!! Você ganhou.\n");
			return 0;
		}
		int carta=0;
		int valida = 0;
		do{
			printf("\nDeseja trocar que carta?");
			scanf("%d",&carta);
			if((carta > 0) && (carta < 14))
				for(int i=0; i<cont; i++){
					if(carta == vetaux[i]){
						pos = i;
						valida = 1;
						break;
					}
				}
			else
				printf("\nCARTA INVÁLIDA!");
			if(valida == 1)
				break;
			
		}while(1);
		vetaux[pos] = 1 + rand () % 13;
		printf("\n\tSorteada: %d\n",vetaux[pos]);
		
	}while(1);
	return 0;
}

