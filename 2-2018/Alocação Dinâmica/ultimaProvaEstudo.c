#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


typedef struct No{
	char nome[50];
	int atd;
	struct No * prox, * ant;
}No;

void getNo(No* i){
	printf("Nome do Paciente: %s --> atendimento: %d\n",i->nome,i->atd);
}

void getFila(No * i){
	while (i){
		getNo(i);
		i = i -> prox;
	}	
}

void getPilha(No * fim){
	while(fim){
		getNo(fim);
		fim = fim->ant;
	}	
}

No* getFim(No* i){
	while(i->prox)
		i = i->prox;
	return i;	
}

No* setNo(No * i){
	No * novo = malloc(sizeof(No));
	printf("\n==============CADASTRO================\n");
	printf("Insira o nome do paciente:\t");
	scanf(" %[^\n]s",novo->nome);
	novo->prox = novo->ant = NULL;
	novo->atd = 0;
	if (i) {
		No * fim = getFim(i);
		novo->ant = fim;
		fim->prox = novo;
		return i;		
	}	
	return novo;
}

void chamaPaciente(No * i){
	printf("==============PROX PACIENTE=============\n");
	while(i){
		if (i -> atd == 0){
			i->atd = 1;
			getNo(i);
			break;
		}
		else 
			i = i->prox;
	}	
}

void listaPacientes(No * i, int n){	
	if ( n == 1){
		printf("==============ATENDIDOS=============\n");
		while(i){
			if (i->atd == 1){
				printf("Nome do Paciente: %s --> atendimento: %d\n",i->nome,i->atd);
				break;
			}
			else
				i = i->prox;
		}
	}
	if ( n == 2){
		printf("==============NÃO ATENDIDOS=============\n");
		while(i){
			if (i->atd == 0){
				getFila(i);
				break;
			}
			else
				i = i->prox;
		}
	}	
	
}

int menuOpc(){
	int opc;
	printf("==============MENU PRINCIPAL=============\n");
	printf("1 - Cadastro de Pacientes \n");
	printf("2 - Lista TODOS os Pacientes (FILA) \n");
	printf("3 - Lista TODOS os Pacientes (PILHA) \n");
	printf("4 - Chamar Paciente\n");
	printf("5 - Listar Pacientes ATENDIDOS \n");
	printf("6 - Listar Pacientes NÃO ATENDIDOS \n");
	printf("7 - EXIT\n");
	scanf(" %d",&opc);
	return opc;
}

int main(int argc, char **argv){
	No* inicio = NULL;
	float v;
	v = 76%7;
	printf(" %f",v);
	
	do{
		switch(menuOpc()){
			case 1: inicio = setNo(inicio);
					break;
			case 2: getFila(inicio);
					break;
			case 3: getPilha(getFim(inicio));
					break;
			case 4: chamaPaciente(inicio);
					break;
			case 5: listaPacientes(inicio, 1);
					break;
			case 6: listaPacientes(inicio, 2);
					break;
			case 7: printf("\n\n==============FINALIZADO COM SUCESSO=============\n");
					return 0;
			default: printf("\n\t\tOPÇÃO INVÁLIDA!\n\n");
			
		}		
	}while(1);
	
	return 0;
}

