#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Uma grande empresa de transportes de mercadorias deseja que você 
 * desenvolva um programa para gerenciar a logística de entregade 
 * produtos. O programa deverá ser capaz de armazenar ROTAS entre 
 * cidades do país. Cada ROTA possui as seguintes informações: 
 * cidade de ORIGEM, cidade de DESTINO, DISTÂNCIA (em km.) e TEMPO 
 * de viagem (em horas). Mas atenção! Nenhuma cidad epode ser ORIGEM
 *  para duas rotas distintas, ou seja, cada rota deve possuir uma 
 * origem exclusiva,e seu programa deve garantir essa restrição. 
 * Seu aplicativo deve oferecer as seguintes funcionalidades:
 * Cadastrar rotas (Sendo um único cadastro por vez).
 * Consultar a distância, o tempode entrega total, e a quantidade de
 * viagens que um produto deve sofrer para ser entregue,considerando
 * uma cidade de ORIGEM e uma cidade de DESTINO informada pelo usuário.
 * OBS.: Lembre que a rota também pode não ser possível..*/

typedef struct{
	char origem[50];
	char destino[50];
	float km;
	float hr;	
}Rota;

Rota setCadastro(Rota v[], int r){
	Rota novo;
	char auxO[50], auxD[50];
	int rep;
	do{
		rep=0;
		printf("Insira a cidade de origem: ");
		scanf(" %[^\n]s",auxO);
		for(int i=0; i<r; i++)
			if (strcmp(v[i].origem,auxO)==0){
				rep=1;
				break;
			}
		if (rep){
			printf("\n\t\tCid já cadastrada!\n");
			continue;
		}
		strcpy(novo.origem,auxO);
		break;		
	}while(1);
	
	do{
		printf("Insira a cidade de destino: ");
		scanf(" %[^\n]s",auxD);
		if(strcmp(novo.origem,auxD)==0)
			printf("\tA cidade de dest precisa ser diferente da cid de origem");
		else{
			strcpy(novo.destino, auxD);
			break;
		}		
	}while(1);
	printf("Hora: ");
	scanf(" %f",&novo.hr);
	printf("Km: ");
	scanf(" %f",&novo.km);	
	
	return novo;
}

void getCadastro(Rota v[], int r){
	
	for(int i=0; i<r; i++)
		printf("%s ---> %s\tHr: %.2f\tKm: %.2f\n",v[i].origem, v[i].destino, v[i].hr, v[i].km);
}

int Busca(Rota v[], int r){
	char borig[50], bdest[50];
	float thr=0, tkm=0;
	int viagem=0;
	printf("Cid origem a ser buscada: ");
	scanf(" %[^\n]s",borig);
	printf("Cid destino a ser buscado: ");
	scanf(" %[^\n]s",bdest);
	
	for (int i=0; i<r;i++)
		if(strcmp(v[i].origem,borig)==0){
			viagem ++;
			thr += v[i].hr;
			tkm += v[i].km;
			if(strcmp(v[i].destino,bdest)==0){
				printf("Total viagens: %d\n",viagem);
				printf("Total hr: %.2f\n",thr);
				printf("Total km: %.2f\n",tkm);
				return 0;
			}
			else
				strcpy(borig,v[i].destino);
			
		}
	printf("rota impossível");
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

int main(){
	Rota cad[100];
	int cont = 0;
	do{
		switch(Menu()){
			case 1: cad[cont] = setCadastro(cad, cont);
					cont++;
					break;
			case 2: getCadastro(cad,cont);
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
