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

Rota setCad(Rota v[], int q){
	Rota novo;
	char auxO[50], auxD[50];
	int rep;
	printf("Menu");
	
	do{
		printf("Insira origem: ");
		scanf(" %[^\n]s",auxO);
		rep=0;
		for(int i=0; i<q; i++){
			if (strcmp(v[i].origem,auxO)==0){
				rep = 1;
				break;
			}
			if (rep){
				printf("\nCid já cadastrada!\n");
				continue;
			}
		}
		strcpy(novo.origem,auxO);
		break;	
	}while(1);
	
	do{
		printf("Cid destino: ");
		scanf(" %[^\n]s",auxD);
		if(strcmp(novo.origem,auxD)==0)
			printf("\no Destino necessita ser diferente\n");
		else{
			strcpy(novo.destino,auxD);
			break;
		}		
	}while(1);
	printf("Hora: ");
	scanf(" %f",&novo.hr);
	printf("KM: ");
	scanf(" %f",&novo.km);
	return novo;
}

void getcad(Rota v[], int q){
	for(int i=0; i<q; i++)
		printf("%s ---> %s\tHr: %.2f\tKm: %.2f\n",v[i].origem, v[i].destino,v[i].hr,v[i].km);
}

int Busca(Rota v[], int q){
	char borigem[50], bdest[50];
	int via=0;
	float thr=0, tkm=0;
	printf("origem: ");
	scanf(" %[^\n]s",borigem);
	printf("destino: ");
	scanf(" %[^\n]s",bdest);	
	
	for(int i=0; i<q; i++)
		if (strcmp(v[i].origem,borigem) == 0){
			via++;
			thr += v[i].hr;
			tkm += v[i].km;
			if(strcmp(v[i].destino,bdest)==0){
				printf("T viagens: %d\n",via);
				printf("T horas: %.2f\n",thr);
				printf("T km: %.2f\n\n",tkm);	
				return 0;			
			}
			else
				strcpy(borigem,v[i].destino);
		}
	printf("Inválido");
	
	return 0;
}

int Menu(){
	int opc;
	printf("\t1 - Cad\n");
	printf("\t2 - Listar\n");
	printf("\t3 - Buscar\n");
	printf("\t4 - Sair\n");
	scanf(" %d",&opc);
	
	return opc;
}

int main(int argc, char **argv)
{
	Rota cad[100];
	int cont = 0;
	do{
		switch(Menu()){
			case 1: cad[cont] = setCad(cad, cont);
					cont++;
					break;
			case 2: getcad(cad,cont);
					break;
			case 3: Busca(cad,cont);
					break;
			case 4: printf("\n\nt\tFINALIZADO COM SUCESSO!");
					return 0;
			default: printf ("\nOpção Inválida\n");			
		}		
	}while(1);
	
	
	return 0;
}

