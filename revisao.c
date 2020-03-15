#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct Info{
	int inf;
	struct Info* viz;
	struct Info* prox;
	struct Info* ant;
}Info;

int MenuOpc(){
	int opc;
	printf("=================MENU================\n");
	printf("1- Cadastro l1\n2- Cadastro l2\n3- Imprimir lista 1\n4- Imprimir lista 2\n5- Excluir alvo l1\n6- Excluir alvo l2\n7 - EXIT\n\n\t");
	scanf(" %d",&opc);
	return opc;	
}

void getImpressao(Info* i){
	if (!i)
		printf("\nNão existe lista!\n");
	if (i)
		printf("\n\t\tA lista é: \n");
	while (i){
		printf("%d\n",i->inf);
		i = i->prox;
	}
}

Info* getFim(Info* i){
	while(i->prox)
		i = i->prox;
	return i;
}

Info* setCadastro(Info* i){
	Info* novo = malloc(sizeof(Info));
	printf("\nDigite a informação: \n");
	scanf(" %d",&novo->inf);
	novo->prox = NULL;
	novo->ant = NULL;
	novo->viz = NULL;
	if (i){
		Info* fim = getFim(i);
		novo->ant = fim;
		fim->prox = novo;	
	}
	return novo;
}
/*
void Vizinho(Info* l1, Info* l2){
	printf("\n===================VIZINHOS================\n");
	Info* aux1 = l1;
	Info* aux2 = l2;
	int cont1, cont2;
	cont1 = (strlen(aux1));
	cont2 = (strlen(aux2));
	for (int i=0; i<cont1; i++){
		for (int j=0; j<cont2; j++){
			if (aux1[i]->inf == aux2[j]->inf){
				aux1[i]->viz = aux2[j]->inf;
				aux2[j]->viz = aux1[i]->inf;
				printf("%d\t%d", aux1[i]->inf, aux2[j]->inf);
			}
		}
	}
	
}

*/

Info* Excluir(Info* i){
	Info* prox;
	Info* ant;
	Info* aux = i;
	int alvo;
	printf("\nDigite o alvo:\n");
	scanf(" %d",&alvo);
	while(alvo){
		if (alvo == aux->inf){
				ant = aux->ant;
				prox = aux->prox;
				if (ant)
					ant->prox = prox;
				if (prox)
					prox->ant= ant;
				free(aux);
				printf("\n\tEXLUIDO COM SUCESSO!\n");
				break;
			}
			else
				aux = aux->prox;		
	}
	if (aux == i)
		return prox;
	return i;
}
	
int main(int argc, char **argv)
{
	Info* l1 = NULL;
	Info* l2 = NULL;
	do{
		switch(MenuOpc()){
			case 1: if(!l1)
						l1 = setCadastro(l1);
					else
						setCadastro(l1);
					break;
			
			case 2: if (!l2)
						l2 = setCadastro(l2);
					else
						setCadastro(l2);
					break;
			
			case 3: getImpressao(l1);
					break;
			
			case 4: getImpressao(l2);
					break;
			case 5: l1 = Excluir(l1);
					break;
			case 6: l2 = Excluir(l2);
					break;
		
		}
	
	}while(1);
	
	return 0;
}
		
