#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct No{
	int info;
	struct No *prox, *ant;
}No;

void getNo(No * i){
	printf("Info: %d\n",i->info);
}

void getFila(No * i){
	while(i){
		getNo(i);
		i = i->prox;
	}
}

void getPilha(No * fim){
	while(fim){
		getNo(fim);
		fim = fim->ant;
	}	
}

No* getFim(No * i){
	while(i->prox)
		i = i->prox;
	return i;
}

No * setNo(No * i){
	No * novo = malloc(sizeof(No));
	printf("Escreva a info: ");
	scanf(" %d",&novo->info);
	novo->ant = novo->prox = NULL;
	if (i){
		No* fim = getFim(i);
		novo->ant = fim;
		fim->prox = novo;
		return i;
	}
	return novo;
}

No * apagaAlvo(No * i){
	No * aux = i;
	No * prox, * ant;
	int alvo;
	printf("Qual é o alvo? ");
	scanf(" %d",&alvo);
	while (aux){
		if (aux->info == alvo){
			prox = aux->prox;
			ant = aux->ant;
			if(ant)
				ant->prox = prox;
			if(prox)
				prox->ant = ant;
			free (aux);
			break;
		}
		else
			aux = aux->prox;		
	}
	if (i == aux)
		return prox;
	return i;
}

int opc(){
	int opc;
	printf("1 - CADASTRO \n");
	printf("2 - FILA\n");
	printf("3 - PILHA\n");
	printf("4 - EXCLUSÃO\n");
	printf("5 - EXIT\n");
	scanf(" %d",&opc);
	return opc;
}

int main(int argc, char **argv)
{
	No *inicio = NULL;
	
	do{
		switch(opc()){
			case 1: inicio = setNo(inicio);
					break;
			case 2: getFila(inicio);
					break;
			case 3: getPilha(getFim(inicio));
					break;
			case 4: inicio = apagaAlvo(inicio);
					break;
			case 5: return 0;
		}
	}while(1);
	
	return 0;
}

