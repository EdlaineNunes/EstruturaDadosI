#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	char origem[50];
	char destino[50];
	float hr;
	float km;	
}Rota;

void printLinha(){
	for(int i=0; i<50; i++)
		printf("=");
}

int printMenu(){
	int opc;
	printLinha();
	printf("\n\t\tMENU\n\n");
	printf("1 - Cad\n");
	printf("2 - Lista\n");
	printf("3 - Busca\n");
	printf("4 - EXIT\n");
	scanf(" %d",&opc);
	printLinha();
	return opc;
}

Rota setRota(Rota r[], int q){
	Rota novo;
	int rep;
	char auxO[50], auxD[50];
	printLinha();
	printf("\n\t\tCADASTRO:\n\n");
	do{
		rep = 0;
		printf("Insira origem:\t");
		scanf(" %[^\n]s",auxO);
		for(int i=0; i<q; i++)
			if(strcmp(r[i].origem,auxO)== 0)
				rep = 1;
		if (rep){
			printf("Cid Origem já cadastrada!");
			continue;
		}
		strcpy(novo.origem,auxO);
		break;
	}while(1);
	
	do{
		printf("Insira destino:\t");
		scanf(" %[^\n]s",auxD);
		if(strcmp(novo.origem,auxD) == 0)
			printf("Cid destino precisa ser diferente da Origem\n");
		else{
			strcpy(novo.destino,auxD);
			break;
		}
	}while(1);
	
	printf("Insira hora:\t");
	scanf(" %f",&novo.hr);
	printf("Insira km:\t");
	scanf(" %f",&novo.km);
	printLinha();
	return novo;
}

void getRota(Rota r[], int q){
	for(int i=0; i<q; i++){
		printf("%dº Cadastro:\n",i+1);
		printf("%s ---> %s\tHr: %.2f\tKm: %.2f",r[i].origem, r[i].destino, r[i].hr, r[i].km);
	}
}

int Busca(Rota r[], int q){
	char borigem[50], bdest[50];
	int via=0;
	float thr=0, tkm=0;
	printf("Insira cidade Origem a ser buscada:\t");
	scanf(" %[^\n]s",borigem);
	printf("Insira cidade Destino a ser buscado:\t");
	scanf(" %[^\n]s",bdest);	
	
	do{
		for(int i=0; i<q; i++)
			if (strcmp(borigem,r[i].origem)==0){
				via++;
				thr += r[i].hr;
				tkm += r[i].km;
				if (strcmp(bdest,r[i].destino)==0){
					printf("Total de viagens: %d\n",via);
					printf("Total de horas: %.2f\n",thr);
					printf("Total em KM: %.2f\n",tkm);
					return 0;					
				}
				else
					strcpy(borigem,r[i].destino);		
			}
		printf("\n\n\t\tRota impossível\n");
		break;
	}while(1);	
	return 0;
}


int main(int argc, char **argv)
{
	Rota cad[100];
	int cont=0;
	
	do{
		switch(printMenu()){
			case 1: cad[cont] = setRota(cad, cont);
					cont++;
					break;					
			case 2: getRota(cad, cont);
					break;
			case 3: Busca (cad, cont);
					break;
			case 4: printf("\n\tFinalizado!");
					return 0;
			default: printf("\tOpção Inválida!\n");
		}
	}while(1);
	
	
	return 0;
}

