#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct No{
	int info;
	struct No *prox;
	struct No *ant;
}No;

void getNo(No* i){
	printf("Info: %d\n",i->info);
}

void getImprime(No *i){
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
	No* novo = malloc(sizeof(No));
	printf("Digite a info: ");
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

No* exclui(No *i){
	No * aux = i;
	No *prox, *ant;
	int alvo;
	printf("Alvo: ");
	scanf(" %d",&alvo);
	while(alvo){
		if(alvo == aux->info){
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
	if(aux == i)
		return prox;
	return i;
}

int opc(){
	int opc;
	printf("\n1-Cad\n2-Lista\n3-Exclui\n4-sair\n");
	scanf(" %d",&opc);
	return opc;
}


int main(int argc, char **argv)
{
	No * inicio = NULL;
	do{
		switch(opc()){
			case 1:if (!inicio)
						inicio = setNo(inicio);
					else
						setNo(inicio);
					break;
			case 2: getImprime(inicio);
					break;
			case 3: inicio = exclui(inicio);
					break;
			case 4: return 0;
		}		
	}while(1);
	return 0;
}

