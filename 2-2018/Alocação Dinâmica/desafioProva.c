#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct No{
	int info;
	char tipo;
	struct No* prox;
	struct No* ant;	
}No;

int menu(){
	int opc;
	printf("\n\t\tMENU PRINCIPAL ");
	printf("\n1-Cad");
	printf("\n2-Listar todos");
	printf("\n3-Listar tipo 'A'");
	printf("\n4-Listar tipo 'B'");
	printf("\n5-EXIT");
	printf("\nOpc:\t");
	scanf(" %d",&opc);	
	return opc;
}

void getNo(No* i){
	printf("Info: %d\tTipo: %c\n",i->info, i->tipo);
}

void getFila(No* i){
	printf("\n\t\tCadastros:\n");
	while(i){
		getNo(i);
		i = i->prox;
	}	
}

No* getFim(No* i){
	while(i->prox)
		i = i->prox;
	return i;	
}

No* setNo(No* i){
	No *novo = malloc(sizeof(No));
	printf("\n\t\tCADASTRO");
	printf("\nInsira o número: ");
	scanf(" %d",&novo->info);
	do{
		printf("Insira o tipo [A/B]: ");
		char aux;
		scanf(" %c",&aux);
		//---------validar o tipo-----------
		if((aux == 'a') || (aux == 'b') || (aux == 'A') || (aux == 'B')){
			novo->tipo = aux;
			printf("\n\tCADASTRADO COM SUCESSO!");
			//printf("%c",novo->tipo);
			break;
		}
		printf("\n\n\t\tTIPO INVÁLIDO! TENTE NOVAMENTE!\n\n");
	}while(1);
	novo->prox = novo->ant = NULL;
	if(i){
		No* fim = getFim(i);
		novo->ant = fim;
		fim->prox = novo;
		return i;		
	}		
	return novo;
}

void getDesmembra(No* i, int n){
	if(n == 1){
		printf("\n\t\tTIPO -----A-----\n");
		while(i){
			if((i->tipo == 'a') || (i->tipo == 'A'))
				printf("Info: %d\n",i->info);
			i = i->prox;
		}
	}
	else{
		printf("\n\t\tTIPO -----B-----\n");
		while(i){
			if((i->tipo == 'b') || (i->tipo == 'B'))
				printf("Info: %d\n",i->info);
			i = i->prox;
		}
	}		
}

int main(int argc, char **argv)
{
	No *inicio = NULL;
	do{
		switch(menu()){
			case 1: inicio = setNo(inicio);
					break;
			case 2: getFila(inicio);
					break;
			case 3: getDesmembra(inicio,1);
					break;
			case 4: getDesmembra(inicio,2);
					break;
			case 5: return 0;
			default:printf("Opção Inválida");
		}
	}while(1);
	
	return 0;
}

