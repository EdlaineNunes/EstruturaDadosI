#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
	char cidO[50];
	char cidD[50];
	float dis;
	float horas;
}Rota;

void printLinha(){
	for (int i=0; i<50; i++)
		printf("=");
	printf("\n");
}

int printMenu(){
	printLinha();
	printf("\t\t\tMENU\n\n");
	int opc;
	printf("\t1 - Cadastrar rotas:\n");
	printf("\t2 - Listar rotas:\n");
	printf("\t3 - Buscar rotas:\n");
	printf("\t4 - EXIT\n");
	scanf(" %d",&opc);
	printLinha();
	return opc;
}

Rota setCad(Rota cad[], int cont){
	Rota novo;
	char aux [50];
	char auxdest[50];
	int rep;
	printLinha();
	printf("\n\t\tCADASTRO!!!\n\n");
	do{
		rep=0;
		printf("Insira a cidade de origem:\t");
		scanf(" %[^\n]s",aux);
		for(int i=0; i<cont; i++)
			if(strcmp(cad[i].cidO,aux) == 0){
				rep = 1;
				break;
			}
		if (rep){
			printf("\n\t\tCIDADE ORIGEM JÁ CADASTRADA!\n\n");
			continue;
		}
		strcpy(novo.cidO,aux);
		break;
	}while(1);
	do{
		printf("Insira a cidade de destino:\t");	
		scanf(" %[^\n]s",auxdest);
		if(strcmp(auxdest,aux)==0)
			printf("\n\tA CIDADE DESTINO NÃO PODE SER IDÊNTICA À ORIGEM!\n\t\t\tTENTE NOVAMENTE!\n\n");
		else{
			strcpy(novo.cidD,auxdest);
			break;
		}
	}while(1);
	printf("Insira a qtde de horas de viagem:\t");
	scanf(" %f",&novo.horas);
	printf("Insira a quilometragem:\t\t");
	scanf(" %f",&novo.dis);
	return novo;
}

void getCad(Rota cad[], int qnt){
	printLinha();
	if (qnt == 0)
		printf("\n\t\tNENHUMA ROTA CADASTRADA!\n\n");
	else{
		printf("\nROTAS CADASTRADAS:\n\n");
		for (int i=0; i<qnt; i++){
			printf("%dº CADASTRO:\n",i+1);
			printf("%s ----> %s\t Hrs: %.2f\tKM: %.2f\n\n",cad[i].cidO,cad[i].cidD,cad[i].horas, cad[i].dis);
		}
	}
	printLinha();
}

int setBusca(Rota cad[], int qnt){
	printLinha();
	if(qnt==0){
		printf("\n\t\tNENHUMA ROTA CADASTRADA!\n\n");
		printLinha();
	}
	else{
		char buscaOri[50];
		char buscaDest[50];
		float nhrs = 0 , nkm = 0;
		int qntvia=0;
			printf("\n\t\tBUSCA:\n");
		printf("Insira a cidade de Origem:\t");
		scanf(" %[^\n]s",buscaOri);
		printf("Insira a cidade de Destino:\t");
		scanf(" %[^\n]s",buscaDest);
	
		for(int i=0; i<qnt; i++)			
			if (strcmp(cad[i].cidO,buscaOri) == 0){
				qntvia++;
				nhrs += cad[i].horas;
				nkm += cad[i].dis;
				if (strcmp(cad[i].cidD,buscaDest) == 0){
					printf("Nº de viagens: %d\n",qntvia);
					printf("Qnt de horas: %.2f\n",nhrs);
					printf("Km: %.2f\n\n",nkm);
					printLinha();
					return 0;
				}
				else
					strcpy(buscaOri,cad[i].cidD);
				
			}
		printf("\n\t\tRota impossível!\n\n");
		printLinha();		
	}
	return 0;		
}

int main(int argc, char **argv)
{
	Rota cad[100];
	
	int cont=0;
	do{
		switch (printMenu()){
			case 1: cad[cont] = setCad(cad, cont); 
					cont++;
					break;
			case 2: getCad(cad,cont);
					break;
			case 3: setBusca(cad,cont);
					break;
			case 4: printf("\n\t\tPROGRAMA FINALIZADO!\n\n");
					printLinha();
					return 0;
			default: printf("\n\t\tOPÇÃO INVÁLIDA!!!!!!\n\n");
							
		}
	}while(1);
	return 0;
}

                                       
