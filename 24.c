#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Faça um programa C para ler do usuário dois valores inteiros X e Y. Alimente dois vetores de tamanhos X e Y com
números inteiros aleatórios, não repetitivos, sorteados no intervalo entre 0 e X+Y (inclusive). Faça a impressão das
seguintes informações:
a) Vetores X e Y;
b) Todos os números exclusivos do vetor X;
c) Todos os números exclusivos do vetor Y;
d) Os números existentes nos dois vetores;*/

int main(){
	int x,y,repetidox,auxx,auxy,repetidoy;
	printf("Digite o valor de X:");
	scanf(" %d", &x);
	printf("Digite o valor de Y");
	scanf(" %d", &y);
	srand(time(NULL));
	
	int vetx[x];
	int vety[y];
	//vetor x
	for(int i=0;i<x;i++){
		do{
			auxx=rand()%(x+y);
			repetidox=0;
			for(int f=0;f<i;f++){
				if(auxx==vetx[f]){
					repetidox=1;
				}
			}
		}while(repetidox==1);
		vetx[i]=auxx;
		printf("%d-",vetx[i]);
		
	}
	printf("\n");
	//vetor y
	for(int n=0;n<y;n++){
		do{
			auxy=rand()%(x+y);
			repetidoy=0;
			for(int m=0;m<n;m++){
				if(auxy==vety[m]){
					repetidoy=1;
				}
			}
		}while(repetidoy==1);
		vety[n]=auxy;
		printf("%d-",vety[n]);
	}
		
	//exclusivo x
	printf("\n");
	for(int i=0;i<x;i++){
		repetidox=0;
		for(int j=0;j<y;j++){
		    if(vetx[i]==vety[j])
				repetidox=1;
		}
			if(repetidox==0)
			printf("exclusivos x %d\n",vetx[i]);
	}
	//exclusivos y
    printf("\n");
	for(int i=0;i<x;i++){
		repetidoy=0;
		for(int j=0;j<y;j++){
		    if(vety[i]==vetx[j])
				repetidoy=1;
			}
			if(repetidoy==0)
				printf("exclusivos y %d\n",vety[i]);
	}	
	//Repetidas
	printf("\n");
	for(int i=0;i<x;i++){
		repetidox=0;
		for(int j=0;j<y;j++){
		    if(vetx[i]==vety[j])
				repetidox=1;
		}
		if(repetidox==1)
			printf("Repetidas x %d\n",vetx[i]);
	}	
			
	return 0;
}

