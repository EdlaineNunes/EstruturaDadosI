#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct No{
	int info;
	struct No *prox,*ant;
}No;

void getNo(No* i){
	printf("Info: %d\n",i->info);
}

void getPilha(No* fim){
	printf("\n======================== PILHA =========================\n");
	while(fim){
		getNo(fim);
		fim = fim->ant;		
	}
}

void getFila(No* i){
	printf("\n======================== FILA =========================\n");
	while(i){
		getNo(i);
		i = i->prox;
	}	
}

No* getFim(No *i){
	while (i->prox)
		i = i->prox;
	return i;	
}

No* setCad(No *i){
	No* novo = malloc(sizeof(No));
	printf("\n========================CADASTRO=========================\n");
	printf("Insira a informação: ");
	scanf(" %d",&novo->info);
	novo->prox = novo->ant = NULL;
	if(i){
		No* fim = getFim(i);
		novo->ant = fim;
		fim->prox = novo;
		return i;
	}
	return novo;
}

No* deletaNo(No* i){
	int alvo;
	printf("\n======================== EXCLUSÃO =========================\n");
	printf("Insira alvo:\t");
	scanf(" %d",&alvo);
	No *prox, *ant;
	No *aux = i;
	while(aux){
		if (aux->info == alvo){
			prox = aux->prox;
			ant = aux->ant;
			if(ant)
				ant->prox = prox;
			if(prox)
				prox->ant = ant;
			free(aux);
			break;
		}
		else
			aux = aux->prox;
	}
	if(i == aux)
		return prox;
	return i;
}


int menuOpc(){
	int opc;
	printf("\n========================MENU OPÇÕES=========================\n ");
	printf("1 - Cadastro\n ");
	printf("2 - Listar PILHA\n ");
	printf("3 - Listar FILA\n ");
	printf("4 - Escolher alvo (EXCLUSÃO)\n ");
	printf("5 - EXIT\n ");
	printf("\tOpc:\t ");
	scanf(" %d",&opc);
	return opc;
}

int main(int argc, char **argv)
{
	No *inicio = NULL;
	do{
		switch(menuOpc()){
			case 1: inicio = setCad(inicio);
					break;
			case 2: getPilha(getFim(inicio));
					break;
			case 3: getFila(inicio);
					break;
			case 4: inicio = deletaNo(inicio);
					break;
			case 5: return 0;
			default: printf("\n\t\tInválido!\n");
		}
	}while(1);	
	return 0;
}

