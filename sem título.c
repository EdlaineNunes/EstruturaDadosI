#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Empregado{

	char nome[25];
	char sobrenome[50];
	int nmat;
	int rg;
	float salario;
	struct Empregado *prox;
	struct Empregado *ant;
		
}Empregado;

Empregado* setCadastro(Empregado* i){
	Empregado* novo = malloc (sizeof(Empregado));
	printf("\nDigite o nome do Empregado:");
	scanf(" %[^\n]s",novo->nome);
	printf("\nDigite o sobrenome do Empregado:");
	scanf(" %[^\n]s",novo->sobrenome);
	printf("\nDigite o num de matrícula do Empregado:");
	scanf(" %d",&novo->nmat);
	printf("\nDigite o num do RG:");
	scanf(" %d",&novo->rg);
	printf("\nDigite o salário do Empregado:");
	scanf(" %f",&novo->salario);
	novo->prox = i;
	novo->ant = novo->prox;
	//printf("\nANTERIOR: ",novo->ant);
	
	return novo;
}

void getCadastro(Empregado* i){
	printf ("\nNome: %s\nSobrenome: %s\nN matricula: %d\nN RG: %d\nSalario: %.2f",i->nome,i->sobrenome,i->nmat,i->rg,i->salario);
}

void Lista(Empregado* l){
	
	while (l){
		getCadastro(l);
		l = l -> prox;	
		
	}
}

int printMenu(){
	printf("\n==========MENU==========");
	printf("\n1 - CADASTRAR");
	printf("\n2 - LISTAR\n");
	int opc;
	scanf(" %d",&opc);
	return opc;
}

int main(){
	Empregado* i=NULL;
	do{
		switch(printMenu()){
			case 1: i = setCadastro(i);
					break;
			case 2: Lista(i);
					break;
		default: return 0;
		}
	}while(1);	
	return 0;
}

