#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	char nome[30];
	char sobren[50];
	int rg;
	float salario;
	int nMat;
}Empregado;

Empregado * setEmpregado(){
	//cria o espaço necessário
	Empregado *e = malloc (sizeof(Empregado));
	printf("Nome: \t");
	scanf(" %[^\n]s",e->nome);	
	printf("Sobrenome: \t");
	scanf(" %[^\n]s",e->sobren);	
	printf("Rg: \t");
	scanf(" %d",&e->rg);	
	printf("Salário: \t");
	scanf(" %f",&e->salario);
	printf("Numero Matricula: \t");
	scanf(" %d",&e->nMat);	
	//retorna a informação e NÃO O PONTEIRO
	return e;
}

void getEmpregado(Empregado *e){
	//imprime recebendo o ponteiro
	// e - endereço , e* - conteudo
	printf("Nome: %s --> Sobrenome: %s --> RG: %d --> Salario: %.2f --> Numero Matricula: %d\n",e->nome,e->sobren,e->rg,e->salario,e->nMat);		
}

int menuOpc(){
	int opc;
	printf("1-cad,2-lista\n");
	scanf(" %d",&opc);
	return opc;
}


int main(int argc, char **argv)
{
	Empregado *e;
	/*
	do{
		switch(menuOpc()){
			case 1: e = setEmpregado();
					break;
			case 2: getEmpregado(e);
					break;		
			
			}
		}while(1);
	*/
	
	e = setEmpregado();
	getEmpregado(e);	
	
	return 0;
}

