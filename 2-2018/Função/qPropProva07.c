#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Uma pequena mercearia deseja informatizar o seu processo de estoque e 
 * vendas. Faça um programa que alimente um vetor com “N” registros de 
 * Produto: Código de Barras (i), Descrição (s), Qtde. em Estoque (i), 
 * Valor Unitário (f). Após cadastrar o estoque, o programa entrará em 
 * modo de venda, neste modo, o programa segue o seguinte fluxo:
 * Usuário informa o Código de Barra do produto a ser vendido;
 * Programa imprime as informações do produto (ou se ele não existe);
 * Usuário informa a Quantidade deste item que será vendido;
 * Programa verifica se possui em estoque a quantidade desejada;
 * Caso seja possível a venda, o programa contabiliza o valor a ser 
 * pago e atualiza a quantidade no estoque;
 * Programa repete vendas, até que Código de Barras informado seja 
 * um valor negativo;
 * Caso código negativo, o programa informa o valor total da venda*/

typedef struct{
	int codBarra;
	char desc [50];
	int qtd;
	float vUni;
}Produto;

int geraCodB(Produto v[], int q){
	int cod;
	int rep;
	do{
		rep=0;
		cod = 100 + rand() % 9999;
		for(int i=0; i<q; i++)
			if(cod == v[i].codBarra)
				rep = 1;
		if(rep)
			continue;
		break;
	}while(1);
	return cod;	
}

Produto setProduto(Produto v[], int q){
	Produto novo;
	novo.codBarra = geraCodB(v,q);
	printf("Cod: %d\n",novo.codBarra);
	printf("Desc:\t");
	scanf(" %[^\n]s",novo.desc);
	printf("Qnt estoque:\t");
	scanf(" %d",&novo.qtd);
	printf("Valor:\t");
	scanf(" %f",&novo.vUni);
	return novo;	
}

int getVenda(Produto v[], int q){

	if (q>0){
		float total = 0;
		int aux;
		do{
			printf("Insira o COD DE BARRAS:\t");
			scanf(" %d",&aux);
			if(aux < 0){
				printf("===================================================\n");
				printf("\tFaturamento total: R$ %.2f\n",total);
				printf("===================================================\n");
				return 0;
			}
			for(int i=0; i<q; i++){			
				if(aux == v[i].codBarra){
					printf("Desc: %s --> Qtd: %d --> Valor Unit: R$ %.2f\n",v[i].desc,v[i].qtd,v[i].vUni);
					int auxQnt;
					do{
						if(v[i].qtd == 0){
							printf("\nNão existem unidades disponíveis...\n");
							break;
						}
						else{
							printf("Qnt a ser comprada:\t");
							scanf(" %d",&auxQnt);
							if(auxQnt > v[i].qtd){
								printf("===================================================\n");
								printf("\tQNT SUPERIOR AO ESTOQUE!\nTENTE NOVAMENTE!\n");
								printf("===================================================\n");
								continue;
							}
							else{
								v[i].qtd -= auxQnt;
								float vVenda;
								vVenda = v[i].vUni * auxQnt;
								printf("Valor da Venda: R$ %.2f\n",vVenda);
								printf("===================================================\n");
								printf("\tVENDA EFETUADA COM SUCESSO!\n");
								printf("===================================================\n");
								total += vVenda;
								break;						
							}
							break;
						}
					}while(1);
				}
				else
					printf("\nCÓDIGO INVÁLIDO!\n");
			}	
		}while(1);
	}
	printf("\nNão exite produtos\n");
	return 0;
}

void getOrdenacao(Produto v[], int q){
	for(int i=0; i<q; i++)
		for(int j=0; j<q-1-i; j++)
			if(v[j].qtd > v[j+1].qtd){
				Produto troca = v[j];
				v[j] = v[j+1];
				v[j+1] = troca;	
			}
}

void getProduto(Produto v[], int q){
	if(q>0){
		for(int i=0; i<q; i++)
			getOrdenacao(v,q);
		for(int i=0; i<q; i++)
			printf("%dº - Cod: %d --> Desc: %s --> Qtd: %d --> R$: %.2f\n",i+1,v[i].codBarra,v[i].desc,v[i].qtd,v[i].vUni);		
	
	}else
		printf("\nNenhum cadastro foi encontrado!\n");
}

int main(int argc, char **argv)
{
	//srand(time(NULL));
	Produto p[100]; 
	int cont = 0;
	int opc;	
	do{
		printf("\n\t\tMENU\n");
		printf("\t1-Cad\n\t2-Lista cad\n\t3-Venda\n\t4- EXIT\n\n");
		scanf(" %d",&opc);
		switch(opc){
			case 1: p[cont] = setProduto(p,cont);
					cont++;
					break;
			case 2: getProduto(p,cont);
					break;
			case 3: getVenda(p,cont);
					break;
			case 4: return 0;
			default: printf("\nINVÁLIDO!\n");
			
		}
	}while(1);
	return 0;
}

