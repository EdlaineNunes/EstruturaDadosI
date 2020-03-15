#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
	int info;
	struct No* prox;
	struct No* ant;
}No;

int opt(){
	for (int i = 0; i <30; i++){
		printf("*");		
	}
	printf("\n");
	printf("1-Enfileirar\n");
	printf("2-Listar Fila\n");
	printf("3-Listar Pilha\n");
	printf("4-Excluir\n");
	int opt;
	for (int i = 0; i <30; i++){
		printf("*");
	}
	printf("\nOpção: ");
	scanf(" %d",&opt);
	return opt;
}

void getFila(No* f){
	while(f){
		printf("%d\n",f->info);
		f = f->prox;
	}
}

void getPilha(No* fim){
	while(fim){
		printf("%d\n",fim->info);
		fim = fim->ant;
	}
}


No* getFim(No* i){
	while(i->prox)
		i = i->prox;
	return i;
}

No* setNo(No* inicio){
	No* novo = malloc(sizeof(No));
	printf("Digite a Informação: ");
	scanf(" %d",&novo->info);
	novo->ant = NULL;
	novo->prox = NULL;
	if(inicio){
		No* fim = getFim(inicio);
		novo->ant = fim;
		fim->prox = novo;
		return inicio;
	}
	return novo;
}

No* getAnterior(No* l, int alvo){
	while(l->prox){
		if(l->prox->info == alvo)
			return l;
		l = l->prox;	
	}
	return NULL;
}

No* excluiNo(No* inicio){
	int alvo;
	No* aux = inicio;
	No *prox, *ant;
	printf("Escolha o Alvo: ");
	scanf(" %d",&alvo);
	while(aux){
		if(alvo == aux->info){
			prox = aux->prox;
			ant = aux->ant;
			if(ant)
				ant->prox = prox;
			if(prox)
				prox->ant = ant;
			free(aux);
			break;
		} else
		aux = aux->prox; 
	}
	if(aux == inicio)
		return prox;
	return inicio;
}

int main(){
	No* fila = NULL;
	do{
		switch(opt()){
			case 1: setNo(fila);				
					break;
			case 2: getFila(fila);
					break;
			case 3: getPilha(getFim(fila));
					break;
			case 4: fila = excluiNo(fila);
					break;
			default: return 0;
					break;
		}
	}while(1);
	return 0;
}
