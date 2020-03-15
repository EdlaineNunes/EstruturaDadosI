#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//------------------------------ PILHA -------------------------------

typedef struct Carro{
	int ano;
	char modelo[20];
	float valor;
	char placa[20];
	char proprietario[50];
	struct Carro *prox;
}Carro;

int printMenu(){
	system("clear");
	printf("\t\t======== MENU OPÇÕES ======\n\n");
	printf("\t1 - Cadastrar veículo;\n\t2 - Busca por placa;\n\t3 - Listar todos;\n\t4 - Média de preço;\n\t5 - Encerrar.\n\n\t\tOpc:");
	int opc;
	scanf(" %d",&opc);	
	setbuf(stdin, NULL);
	//getchar();
	return opc;
}

int getValida(Carro*c, char aux[20]){
	while(c){
		if(strcmp(c->placa,aux)==0)
			return 1;
		else
			return 0;		
	}
	return 0;
}

Carro* setCadastro(Carro* c){
	Carro* novo = malloc(sizeof(Carro));
	printf("\n========= CADASTRO =========\n");
	printf("Digite o ano do veículo: ");
	scanf(" %d",&novo->ano);
	printf("\nDigite o modelo do veículo: ");
	scanf(" %[^\n]s",novo->modelo);
	printf("\nDigite o valor do veículo: ");
	scanf(" %f",&novo->valor);
	char auxPlaca[20];
	do{
		printf("\nDigite a placa do veículo: ");
		scanf(" %[^\n]s",auxPlaca);
		//buscar se JÁ existe essa placa cadastrada.
		int val = getValida(c,auxPlaca);
		if (!val){
			strcpy(novo->placa,auxPlaca);
			break;
		}
		else {
			printf("\n\t\tPLACA JÁ CADASTRADA! TENTE NOVAMENTE!\n");
			continue;
		}
	}while(1);
	printf("\nDigite o nome do proprietário do veículo: ");
	scanf(" %[^\n]s",novo->proprietario);
	novo->prox = c;
	printf("\n\n\t\t\tCADASTRANDO...");
	setbuf(stdin, NULL);
	getchar();
	
	return novo;
}

void getCadastro(Carro* c){
	printf("Proprietário: %s\nPlaca: %s\nModelo: %s\nAno: %d\nValor: R$%.2f\n",c->proprietario,c->placa, c->modelo,c->ano,c->valor);
}

void Lista(Carro* c){
	printf("\n========= LISTA DE CADASTRADOS ==========\n");
	//verificar se existe fila para exibir.
	while (c){
		getCadastro(c);
		printf("\n");
		c = c->prox;
	}
	setbuf(stdin, NULL);
	getchar();
}

Carro* Busca(Carro* c){
	char aux[20];
	printf("\n========= BUSCA DE VEÍCULO ==========\n");
	printf("Digite a placa a ser buscada: ");
	scanf(" %[^\n]s",aux);
	
	do{
		if(strcmp(aux,c->placa)==0){
			getCadastro(c);
			setbuf(stdin, NULL);
			getchar();
			return 0;
		}
		else{
			c = c->prox;
		}
	}while(1);
	printf("\nVeículo não encontrado!");
	setbuf(stdin, NULL);
	getchar();
	return 0;
}

void Media(Carro* c){
	float soma=0;
	int cont=0;
	while (c){
		soma += c->valor;
		cont++;
		c = c->prox;
	}
	printf(" São %d carros ao total, com uma média de: R$%.2f.\n",cont, (soma/cont));
	setbuf(stdin, NULL);
	getchar();
}

int main(int argc, char **argv)
{
	Carro* c= NULL;
	do{
		switch(printMenu()){
			case 1: c = setCadastro(c);
					break;
			case 2: Busca(c);
					break;
			case 3: Lista(c);
					break;
			case 4: Media(c);
					break;
			case 5: printf("\n\n\t\tFINALIZADO COM SUCESSO!");
					getchar();
					return 0;
			default: printf("\n\tOpção Inválida!\n");
		}
	}while(1);	
	return 0;
}

