#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	char nome[50];
	int ano;
	char genero[50];
}Filme;

typedef struct{
	char nome[50];
	int ano;
	int n_episodios;
}Desenho;

void setFilme(FILE *arq){
	Filme novo;
	printf("Digite o nome do filme:");
	scanf(" %[^\n]s",novo.nome);
	printf("Digite o ano do filme:");
	scanf(" %d",&novo.ano);
	printf("Digite o gênero do filme:");
	scanf(" %[^\n]s",novo.genero);

	fseek(arq,sizeof(Filme),SEEK_END);
	if(fwrite(&novo,sizeof(Filme),1,arq))
		printf("Carro Salvo com Sucesso!\n");
	else{
		printf("Carro não salvo!!");
	}
	int i=fclose(arq);
	if (!i)
		printf("Arquivo Fechado!");
}

void getFilme(FILE * arq){
	Filme novo;
	fseek(arq,sizeof(Filme),SEEK_SET);
	
	while(fread(&novo,sizeof(Filme),1,arq)){
		printf("Nome: %s \nAno: %d\nGênero: %s\n",novo.nome,novo.ano,novo.genero);
	}
	
}

void printLinha(){
	printf("\n\n\t");
	for (int i=0; i<30; i++)
		printf("=");
	printf("\n\n");
}

int printMenu(){
	int opc;
	printLinha();
	printf(" \t\tMENU PRINCIPAL\n");
	printf("1- Cad FILME\n");
	printf("2 - Exibir FILME\n");
	printf("3 - Cad ANIME\n");
	printf("4 - Exibir ANIME\n");
	printf(" ");
	scanf(" %d",&opc);
	return opc;
}

int main(int argc, char **argv)
{
	FILE *arqFilme = NULL;
	
	do{
		switch(printMenu()){
			case 1: arqFilme= fopen("Filmes.txt","r+");
					if(!arqFilme)
						arqFilme = fopen("Filmes.txt","w+");
					if(!arqFilme)
						printf("Programa não conseguiu abrir o arquivo!!\n");
					setFilme(arqFilme);
					break;
			case 2: getFilme(arqFilme);
					break;
			case 0: return 0;
					
					
	
	
			
			
		}
	}while(1);
	
	
	
	int i=fclose(arqFilme);
	if (!i)
		printf("Arquivo Fechado!");
		
	return 0;
}

