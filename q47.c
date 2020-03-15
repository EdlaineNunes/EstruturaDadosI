#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//FUNCIONAL

/*47. Faça um programa que leia o Nome e a Idade de N pessoas. Imprima a relação de nomes ordenada pelas idades de
forma decrescente.*/

int main(int argc, char **argv)
{
	int n,cont=1;;
	printf("Digite o numero de pessoas q deseja cadastrar: ");
	scanf("%d",&n);
	
	char nome [n][100];
	int idade[n];
	char vaux[50];
	
	for (int i = 0; i < n; i++){
		
		printf("Digite %d° nome: ",cont);
		scanf(" %[^\n]s",nome[i]);
		printf("Digite a idade: ");
		scanf(" %d",&idade[i]);
		cont++;
	}
	//bubble sort
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n-1-i; j++)
			if (idade[j]<idade[j+1]){
				int aux = idade[j];
				strcpy(vaux,nome[j]);
				
				idade[j]= idade[j+1];
				strcpy(nome[j],nome[j+1]);
				
				idade[j+1]=aux;
				strcpy(nome[j+1], vaux);				
				
			}
	//impressão ordenanda das idades
	printf("\n\t\t\tIdades em ordem decrescente:\n");
	for (int i = 0; i < n; i++)
		printf("%d é a idade de: %s\n",idade[i],nome[i]);
		
	
	return 0;
}

