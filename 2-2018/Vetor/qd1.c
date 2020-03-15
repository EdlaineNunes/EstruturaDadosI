#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Faça um programa que leia dois números inteiros e imprima se
eles são múltiplos ou não.*/

int main(int argc, char **argv)
{
	int n1,n2;
	printf("Digite um número: ");
	scanf(" %d",&n1);
	printf("Digite outro número: ");
	scanf(" %d",&n2);
	if (n1%n2 && n2%n1)
		printf("Não são múltiplos");
	else 
		printf("São múltiplos");
	
	return 0;
}

