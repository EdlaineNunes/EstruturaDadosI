#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	char nome[100];
	printf("Digite seu nome: ");
	scanf(" %[^\n]s",nome);
	if ((nome[0] >= 'a') && (nome[0] <= 'z'))
		nome[0] -= ('a' - 'A');
	for (int i=1; i<strlen(nome); i++){
		if ((nome[1] >= 'a') && (nome[1] <= 'z') && (nome[i-1]== ' '))
			nome[i] -= ('a' - 'A');
	}
	printf("\n\nNome completo:\t%s",nome);
	return 0;
}

