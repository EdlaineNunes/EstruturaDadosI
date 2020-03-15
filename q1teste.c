#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct Cad{
	char filme[50];
	char link[50];
	struct Cad *prox;	
}Cad;

int MenuOpt(){
	printf("\t========MENU========");
	printf("\n1 - CADASTRAR;");
	printf("\n2 - LISTAR;");
	printf("\n3 - BUSCAR;");
	printf("\n4 - SAIR.\n");
	int opt;
	scanf(" %d",&opt);	
	return opt;
}
	
	
Cad* getCadastro(Cad* lista){
	Cad* novo = malloc(sizeof(Cad));
	printf("\nDigite o nome do filme: ");
	scanf(" %[^\n]s",novo->filme);
	printf("\nDigite o link: ");
	scanf(" %[^\n]s",novo->link);
	novo->prox = lista;
	
	return novo;

}

void setCad(Cad* lista){
	printf("FILME: %s\tLINK: %s\n",lista->filme, lista->link);	
}

void Lista (Cad* l){
	while(l){
		setCad(l);
		l = l->prox;
	}
	
}


int main(int argc, char **argv)
{
	Cad* lista = NULL;
	
	do{
		switch(MenuOpt()){
			case 1: getCadastro(lista);
					break;
			case 2: Lista(lista);
					break;
			case 3:
					break;
			default: return 0;
			
			}
	}while(1);
		
	return 0;
}

