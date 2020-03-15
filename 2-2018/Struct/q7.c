#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
	int codBarras;
	char desc[100];
	int qtdeEst;
	float valor;	
}Produto;

int main(int argc, char **argv)
{
	int n;
	do{
		printf("Deseja cadastrar quantos produtos? ");
		scanf(" %d",&n);
		if(n<1){
			printf("\n\t\tValor inválido, TENTE NOVAMENTE!\n");
			continue;
		}
		else
			break;
	}while(1);
	Produto cad[n];
	printf("\n=========================================================");
	printf("\n\t\tCADASTRO DE PRODUTOS\n");
	for(int i=0; i<n; i++){
		printf("\n\t\t%dº PRODUTO",i+1);
		printf("\nInsira o nome: ");
		scanf(" %s",cad[i].desc);
		printf("Insira o códBarras: ");
		scanf(" %d",&cad[i].codBarras);
		printf("Insira a qtd em ESTOQUE: ");
		scanf(" %d",&cad[i].qtdeEst);
		printf("Insira o valor UNITÁRIO: ");
		scanf(" %f",&cad[i].valor);		
	}
	printf("\n\tCADASTRO FINALIZADO COM SUCESSO!");
	printf("\n=========================================================");	
	printf("\n\tVENDAS!\n");
	int aux, qven;
	float total=0;
	do{
		printf("\nValores negativos encerram.\nInsira o código de barras: ");
		scanf(" %d",&aux);
		if ( aux < 0 ){
			printf("\n\tVENDAS FINALIZADAS!\n");
			printf("O valor a pagar é: R$%.2f",total);
			printf("\n=========================================================");
			return 0;		
		}
		
		for(int i=0; i<n; i++){
			if(aux == cad[i].codBarras){
				do{
					printf("Existem %d unidades desse produto.\nDeseja comprar quantas unidades?",cad[i].qtdeEst);
					scanf(" %d",&qven);
					if(cad[i].qtdeEst >= qven){
						total += (float)(qven * cad[i].valor);
						cad[i].qtdeEst -= qven;
						break;
					}
					else
						printf("\n\tERRO!\nQuantidade superior ao estoque.\n");
				}while(1);
			}			
		}
		printf("\nCÓDIGO INVÁLIDO!\n");
	}while(1);
	
	return 0;
}

