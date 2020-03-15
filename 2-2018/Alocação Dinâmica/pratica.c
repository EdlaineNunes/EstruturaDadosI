#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct No{
	int info;
	struct No *prox, *ant;	
}No;

void getNo(No* i){
	printf("Info: %d\n",i->info);
}

void getPilha(No* fim){
	while(fim){
		getNo(fim);
		fim = fim->ant;
	}
}

void getFila(No* i){
	while(i){
		getNo(i);
		i = i->prox;		
	}	
}

No* getFim(No* i){
	while(i->prox)
		i = i -> prox;
	return i;	
}

No* setNo(No * i){
	No * novo = malloc(sizeof(No));
	printf("Info: ");
	scanf(" %d",&novo->info);
	novo->ant = novo->prox = NULL;
	if (i){
		No * fim = getFim(i);
		novo->ant = fim;
		fim->prox = novo;
		return i;
	}
	return novo;	
}

No* getExclui(No* i){
	int alvo;
	printf("Insira o valor do alvo:\t");
	scanf(" %d",&alvo);
	No *prox,*ant;
	No *aux = i;
	while(aux){
		if (aux->info == alvo){
			prox = aux->prox;
			ant = aux->ant;
			if (ant)
				ant->prox = prox;
			if (prox)
				prox->ant = ant;
			free(aux);
			break;			
		}
		else
			aux = aux->prox;		
	}
	if(aux == i)
		return prox;
	return i;
	
}

int Opc(){
	int opc;
	printf("1-Cad, 2-Lista (FILA), 3-Lista (PILHA), 4-Escolher alvo (EXCLUSÃO), 5-EXIT\n");
	scanf(" %d",&opc);
	return opc;
}

int main(int argc, char **argv)
{
	No *inicio = NULL;
	
	do{
		switch (Opc()){
			case 1: inicio = setNo(inicio);
					break;
			case 2: getFila(inicio);
					break;
			case 3: getPilha(getFim(inicio));
					break;
			case 4: inicio = getExclui(inicio);
					break;
			case 5: return 0;
			default: printf("Opc INVÁLIDA!\n");
		}
	}while(1);
	
	return 0;
}

