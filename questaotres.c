#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

	// FUNCIONAL 
	
/*Faça um programa que receba do usuário o comprimento de três gravetos. 
O programa deve informar ao usuário se é possível ou não formar um 
triângulo com aqueles gravetos.*/

int main(int argc, char **argv)
{
	do{
		int a,b,c;
		printf("VALORES NEGATIVOS ENCERRA\n");
		printf("Digite um valor:\n");
		scanf(" %d",&a);
		if (a<0) break;
		printf("Digite outro valor:\n");
		scanf(" %d",&b);
		if (b<0) break;
		printf("Digite um outro valor:\n");
		scanf(" %d",&c);
		if (c<0) break;
		if (((a+b)>c) && ((a+c)>b) && ((b+c)>a))
				printf("\n\n\nÉ possível criar um triângulo\n");
		else {
			printf("Não é possível criar um triângulo\n");
		}
	}while(1);
		
	return 0;
}

