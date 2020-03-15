#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct no{
	int info;
	struct no *prox;	
}no;

no* setNo(no *inicio){
	no* novo = malloc (sizeof(no));
	scanf(" %d",&novo->info);
	novo->prox = inicio;
	return novo;	
}

void getNo(no* inicio){
	printf("Info: %d\n",inicio->info);
}

void pilha(no* inicio){
	while(inicio){
		getNo(inicio);
		inicio = inicio->prox;
	}	
}

int main(int argc, char **argv)
{
	no *lista = NULL;
	for(int i=0; i<3;i++)
		lista = setNo(lista);
	pilha(lista);
	
	return 0;
}

