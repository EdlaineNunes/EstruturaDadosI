#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	int id;
	char nome[100];
	int pont;
}Cadastro;

void getCadastro(FILE* a){
	Cadastro aluno;
	fseek(a,0,SEEK_SET);
	printf("\nJogadores Anteriores:");
	while(fread(&aluno, sizeof(Cadastro), 1, a)){
		printf("\nNome: %s\t ID: %d\tPont: %d\n",aluno.nome,aluno.id,aluno.pont);
	}

}

void setCadastro(FILE* a){
	Cadastro novo;
	int nv=0;
	int aux[10];
	printf("Informe o nome: \n");
	scanf(" %[^\n]s",novo.nome);
	printf("Informe a ID: \n");
	scanf(" %d",&novo.id);
	printf("\n\t\tQUESTÕES:\n\n");	
	do{ 
		printf("\nQuanto é 5+5?");
		printf("\n1 - 10\n2 - 5\n");
		scanf(" %d",&aux[0]);
		if (aux[0] == 1){
			nv+=1;	
			break;
		}
		if (aux[0] == 2)
			break;
		else 
			printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQuanto é 5*5?");
		printf("\n1 - 5\n2 - 25\n");
		scanf(" %d",&aux[1]);
		if (aux[1] == 2){
			nv++;	
			break;
		}
		if (aux[1] == 1)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQunanto é a raiz quadrada de 121?");
		printf("\n1 - 12\n2 - 11\n");
		scanf(" %d",&aux[2]);
		if (aux[2] == 2){
			nv++;	
			break;
		}
		if (aux[2] == 1)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQuanto é a raiz cúbica de 125?");
		printf("\n1 - 5\n2 - 15\n");
		scanf(" %d",&aux[3]);
		if (aux[3] == 1){
			nv++;	
			break;
		}
		if (aux[3] == 2)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQual é a capital de MG?");
		printf("\n1 - Belo Horizonte\n2 - Contagem\n");
		scanf(" %d",&aux[4]);
		if (aux[4] == 1){
			nv++;	
			break;
		}
		if (aux[4] == 2)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQual a capital de SP?");
		printf("\n1- São Paulo\n2 - Florianopolis");
		scanf(" %d",&aux[5]);
		if (aux[5] == 1){
			nv++;	
			break;
		}
		if (aux[5] == 2)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQuanto vale 1hora?");
		printf("\n1 - 120min\n2 - 60min");
		scanf(" %d",&aux[6]);
		if(aux[6] == 2){
			nv++;	
			break;
		}
		if (aux[6] == 1)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQual é o antônimo de MAU?");
		printf("\n1 - BEM\n2 - BOM\n");
		scanf(" %d",&aux[7]);
		if (aux[7] == 2){
			nv++;	
			break;
		}
		if (aux[7] == 1)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("\nQual é o antônimo de BEM?");
		printf("\n1 - MAL\n2 - MAU\n");
		scanf(" %d",&aux[8]);
		if (aux[8] == 1){
			nv++;
			break;
		}
		if (aux[8] == 2)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	do{
		printf("O que tem depois do dia?");
		printf("\n1- Manhã\n2 - Noite");
		scanf(" %d",&aux[9]);
		if (aux[9] == 2){
			nv++;	
			break;
		}
		if (aux[9] == 1)
			break;
		else printf("\nINVÁLIDO!\n");
	}while (1);
	novo.pont = nv;
	//fwrite();
	printf("Sua pontuação foi: %d.",nv);
	fseek(a,0,SEEK_END);
	fwrite(&novo, sizeof(Cadastro), 1, a);	
}


int MenuOpc(){
	printf("\n\n\t\tMENU PRINCIPAL\n\n");
	int opc;
	printf("1- Cadastro\n2- Listar todos os jogadores já cadastrados\n0 - EXIT\n");
	scanf(" %d",&opc);
	return opc;
}
	

int main(){

	FILE* arq = NULL;
	arq = fopen ("cadastro.txt", "rb+");
	if (!arq)
		arq = fopen("cadastro.txt", "wb+");
	if (!arq){
		printf("\nPrograma não conseguiu abrir o arquivo!\n");
		return 0;		
	}
	printf("\n\t\t==============QUIZ=============");
	printf("\n\tCadastro de id\n");
	//setCadastro(arq);
	
	do{
		switch (MenuOpc()){
			case 0 :fclose(arq);
					printf("\n\n\t\t\t\tArquivo fechado!");
					printf("\n========================================\n");
					return 0;
			case 1 :setCadastro(arq);
					break;
			case 2 :getCadastro(arq);
					break;
			default:printf("ERRO!");
		}
	}while (1);
	return 0;
}

