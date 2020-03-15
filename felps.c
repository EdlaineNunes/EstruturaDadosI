#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	int codBarra;
	char prod[100];
	float valor;
	int quant;
}Produto;

void getProduto (Produto v[], int n){
	printf("\n");
	for (int i=0; i<n; i++)
		printf ("\nCod: %d\nDesc: %s\nValor: %.2f\nQuant: %d\n",v[i].codBarra,
			v[i].prod, v[i].valor, v[i].quant);
	setbuf(stdin,NULL);
	getchar();	
}

int Busca(Produto v[],int n){
	char aux[100];
	printf("\nDigite o nome do produto a ser buscado:");
	scanf(" %[^\n]s",aux);
	for (int i=0; i<n; i++){
		if (strcmp(aux,v[i].prod)==0){
			printf("\nPRODUTO ENCONTRADO!");
			printf ("\nCod: %d\nDesc: %s\nValor: %.2f\nQuant: %d\n",v[i].codBarra,v[i].prod, v[i].valor, v[i].quant);
			setbuf(stdin,NULL);
			getchar();
			return 0;
		}				
	}
	printf("Produto não cadastrado!");
	return 0;
}


Produto setProduto(){
	Produto novo;
	printf("Digite o Cód de Barras: \n");
	scanf(" %d",&novo.codBarra);
	printf("Digite a Descrição: \n");
	scanf(" %s",novo.prod);
	printf("Digite o Valor: \n");
	scanf(" %f",&novo.valor);
	printf("Digite a Quantid: \n");
	scanf(" %d",&novo.quant);
	return novo;	
}

int printMenu(){
	system("clear");
	printf("\n\tMENU\n1- Cadastrar Produtos: \n");
	printf("2- Listar Produtos: \n");
	printf("3- Busca por nome: \n");
	printf("4- SAIR!");
	printf("\n");
	int opc;
	scanf(" %d",&opc);
	return opc;
}

int main(int argc, char **argv)
{ 
	Produto p[100];
	int cont = 0;
	
	do{
		switch (printMenu()){
			case 1: p[cont++] = setProduto();
					break;
			case 2: getProduto(p,cont);
					break;
			case 3: Busca(p,cont);
					break;
			case 4: printf("\nFIM DE EXECUÇÃO!");
					return 0;
			
			default : printf("Opção Inválida!");
			}
	}while (1);
	//return 0;
}
