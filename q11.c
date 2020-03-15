#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	char descricao[100];
	int qtde;
}Ingredientes;

typedef struct{
	char nome[100];
	int tempo;
	char dificuldade;
	Ingredientes ing[30];
	int contIng;
}Receita;

int subString(char *a, char *b){
	// 0 -> Nao é Substring
	// 1 -> É substring
	int ca = strlen(a);
	int cb = strlen(b);
	if(ca > cb)
		return 0;
	for(int i=0; i<cb; i++)
		if(b[i] == a[0]){
			printf("%c foi encontrado na posicao %d",a[0],i);
			for(int j=1; j<ca; j++)
				if(a[j] != b[i+j]){
					return 0;
				}
			return 1;
		}
	return 0;
}

int getOption(){
	printf("1 - Cadastrar Receita\n");
	printf("2 - Consultar Receita\n");
	printf("3 - Cadastrar Ingrediente\n");
	printf("4 - FECHAR\n");
	int opt;
	scanf(" %d",&opt);
	return opt;
}

void setIngrediente(Ingredientes *v, int *c){
	do{
		printf("Informe o Nome do Ingrediente: ");
		scanf(" %[^\n]s",v[*c].descricao);
		if(strcmp(v[*c].descricao,"exit")==0)
			return;
		printf("Informe a Qtde: ");
		scanf(" %d",&v[*c].qtde);
		(*c) += 1;
	}while(1);
}

Receita setReceita(){
	Receita nova;
	printf("Informe o Nome: ");
	scanf(" %[^\n]s",nova.nome);
	printf("Informe o Tempo: ");
	scanf(" %d",&nova.tempo);
	printf("Informe a Dificuldade [F/M/D]: ");
	scanf(" %c",&nova.dificuldade);
	nova.contIng = 0;
	printf("Cadastre Ingredientes [Para sair digite 'exit']\n");
	setIngrediente(nova.ing,&nova.contIng);
	//nova.ing[nova.contIng++] = setIngrediente();
	printf("\n\nRECEITA CADASTRADA COM SUCESSO!");
	setbuf(stdin,NULL);
	getchar();
	return nova;
}

void getReceitas(Receita v[], int cont){
	printf("Deseja Buscar por: ");
	char t[100];
	scanf(" %s",t);
	
	for(int i=0; i<cont; i++){
		if(subString(t,v[i].nome)){
			printf("Receita: %s\n",v[i].nome);
			for(int j=0; j < v[i].contIng; j++)
				printf("Ing: %s\n",v[i].ing[j].descricao);
		}
	}
}

int main(){
	Receita receitas[100];
	int cont = 0;
	do{
		switch(getOption()){
			case 1: receitas[cont++] = setReceita();
					break;
			case 2: getReceitas(receitas,cont);
					break;
		}
	}while(1);
}
