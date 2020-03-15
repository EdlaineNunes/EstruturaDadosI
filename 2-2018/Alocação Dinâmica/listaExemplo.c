#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct no{
	int info;
	struct no *prox;
	struct no *ant;
}no;

no* getFim(no* i){
	while(i->prox)
		i = i->prox;
	return i;
}

no* setNo(no *inicio){
	no * novo = malloc(sizeof(no));
	scanf(" %d",&novo->info);
	novo->prox = NULL;
	novo->ant = NULL;
	if(inicio){
		no * fim = getFim(inicio);
		novo->ant = fim;
		novo->prox = novo;		
	}
	return novo;
}


void getNo(){}

int main(int argc, char **argv)
{
	
	
	
	return 0;
}

