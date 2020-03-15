#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//para cada struct, um arquivo
typedef struct {
	float resposta;
	//char enunciado[100];
//	struct Aluno *prox;
}Questao;

void getReposta(FILE* a){
	Questao questao;
	fseek(a,0,SEEK_SET);
	while(fread(&questao, sizeof(Questao), 1, a)){
		printf("\nResposta: %.2f",questao.resposta);
	}

}


void setResposta(FILE* a){
	Questao novo;
	printf("Informe o nome do jogador: \n");
	scanf(" %[^\n]",&novo.nome);
	fseek(a,0,SEEK_END);
	fwrite(&novo, sizeof(Questao), 1, a);	
}


int main(int argc, char **argv)
{

	FILE* arq = NULL;
	arq = fopen ("tUM.txt", "rb");
	if (!arq)
		arq = fopen("tUM.txt", "rb");
	if (!arq){
		printf("\nPrograma não conseguiu abrir o arquivo!\n");
		return 0;		
	}
	
	//operações de entrada e saída
		setResposta(arq);
		getReposta(arq);
	//
	
	
	int i = fclose(arq);
	if (!i)
		printf("\nArquivo fechado!");
	getchar();
	
	return 0;
}

