#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	int codBarra;
	char prod[100];			
	float valor;
	int qnt;
	int aux;
}Produto;

Produto setProduto(){
	Produto novo;
	printf("Digite o Cód de Barras: \n");
	scanf(" %d",&novo.codBarra);
	printf("Digite a Descrição: \n");
	scanf(" %s",novo.prod);
	printf("Digite o Valor Unitário: \n");
	scanf(" %f",&novo.valor);
	printf("Digite a quantidade disponível: \n");
	scanf(" %d",&novo.qnt);
	return novo;	
}

void getProduto (Produto v[], int n){
	printf("\n");
	for (int i=0; i<n; i++){
		printf ("Cod: %d\tDesc: %s\tValor: %.2f\tQtd disponível: %d",v[i].codBarra,
			v[i].prod, v[i].valor, v[i].qnt);
		printf("\n");
	}
	setbuf(stdin,NULL);
	getchar();	
}

Produto CodBarras(Produto p[], int n){
	srand(time(NULL));
	int aux, rep;
	do{
		aux = rand() % 9999999999;
		rep = 0;
		for(int i=0; i<n; i++)
			if(aux == p[i]){
				rep = 1;
				break;
			}
		if (rep)
			continue;		
		//printf("CodBarras: %d", aux);
		return aux;
	}while(1);
}

int printMenu(){
	system("clear");
	printf("\n\tMENU\n1- Cadastrar Produtos: \n");
	printf("2- Listar Produtos: \n");
	printf("3- Vender: \n");
	printf("4- SAIR!\n5- cod");
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
			//case 3: setVenda(p,cont);
					//break;
			case 4: printf("\nFIM DE EXECUÇÃO!");
					return 0;
			case 5: CodBarras(p,cont);
					break;
			
			default : printf("Opção Inválida!");
			}
	}while (1);
	return 0;
}

