#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// INICIO STRING

/*Escreva um programa em C para ler uma frase. A seguir, imprima a frase com: (a) todas as letras maiúsculas, (b)
todas as letras minúsculas, (c) início de cada palavra em maiúsculo.*/

int main(int argc, char **argv)
{
	char vet[100];
	printf("Digite uma frase: ");
	scanf(" %[^\n]s",vet);
	printf("\nA frase digitada foi: %s\n",vet);

	// verificando e contando com a função strlen
	int t = strlen(vet);
	
	//letras maiusculas
	for (int i=0; i<t; i++)
		if ((vet[i]>='a') && (vet[i]<='z'))
			vet[i] -= 'a' - 'A';
	printf("Maiuscula: %s ",vet);
	
	//letras minusculas
	for (int i=0; i<t; i++)
		if ((vet[i]>='A')&&(vet[i]<='Z'))
			vet [i] -='A' - 'a';
	printf("\nMinuscula: %s",vet);
		
	//primeira letra maiuscula
	for (int i=0; i<t; i++)
		if (
			vet[i] = ;
	printf("\nPrimeira maiuscula: %s",vet);
	
	
		return 0;
}

