#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	int matricula;
	char nome[50];	
}Aluno;

int main(int argc, char **argv)
{
	Aluno *a = malloc (sizeof(Aluno));
	//a = (Aluno*)malloc (sizeof(Aluno));
	scanf(" %d",&a->matricula);
	scanf(" %[^\n]s",a->nome);
	
	return 0;
}

