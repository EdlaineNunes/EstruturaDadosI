#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//para cada struct, um arquivo
typedef struct {
	float resp;
}Resp;

typedef struct {
	float resposta;
}Questao;

int MenuOpc(){

	int opc;

	printf("\n1 - Questão 1\n2 - Questão 2\n3 - Questão 3\n4 - Questão 4\n5 - Questão 5");
	printf("\n6 - Questão 6\n7 - Questão 7\n8 - Questão 8\n9 - Questão 9\n10 - Questão 10\n0 - EXIT\n");
	scanf(" %d",&opc);
	return opc;
	
}
int perguntas(int opc;){
	int pont=0;
	int aux;
	if (opc == 1){
		printf("\nQuanto é 5+5?");
		printf("\n1 - 10\n2 - 5\n");
		scanf(" %d",&aux);
		if (aux == 1)
			pont+=1;
		return pont;
	} 
	if (opc == 2){
		printf("\nQuanto é 5*5?");
		printf("\n1 - 5\n2 - 25\n");
		scanf(" %d",&aux);
		if (aux == 2)
			pont+=1;
		return pont;
	}
	if (opc == 2){
		printf("\nQunanto é a raiz quadrada de 121?");
		printf("1 - 12\n2 - 11\n");
		scanf(" %d",&aux);
		if (aux == 2)
			pont+=1;
		return pont;
	}
	
}
void setResposta(FILE* b){
	Resp novo;
	perguntas();
	printf("\n\n\tDigite suas respostas em ordem:\n\t");
	for (int i = 0; i<3; i++){
		scanf(" %f",&novo.resp);
		fseek(b,0,SEEK_END);
		fwrite(&novo, sizeof(Resp), 1, b);	
	}
}

void getReposta(FILE* a){
	Resp questao;
	fseek(a,0,SEEK_SET);
	while(fread(&questao, sizeof(Resp), 1, a)){
		printf("\nResposta: %.2f",questao.resp);
	}

}

void getRepostaarq(FILE* a){
	Questao questaoUm;
	fseek(a,0,SEEK_SET);
	while(fread(&questaoUm, sizeof(Questao), 1, a)){
		printf("\nResposta: %.2f",questaoUm.resposta);
	}

}

void verificaPalavra (FILE* a, FILE* b){
	Resp nova;
	Questao cad;
	fseek(b,0,SEEK_SET);
	fseek(a,0,SEEK_SET);
	while (fread(&cad,sizeof(cad),1,b)&&fread(&nova,sizeof(nova),1,a)){
		if (strcmp (cad.respostas,nova.resp)!=0){
			printf("\nERRO!");
			break;
		}
		else {
			printf("\nAcerto!");
			break;
		}
	}	
		
}
	

int main(int argc, char **argv)
{
	//Resp esc;
	FILE* arq = NULL;
	arq = fopen ("tUM.txt", "rb");
	FILE* arqaux = NULL;
	arqaux = fopen ("tDois.txt","wb");
	if (!arq)
		arq = fopen("tUM.txt", "rb");
	if (!arq){
		printf("\nPrograma não conseguiu abrir o arquivo!\n");
		return 0;		
	}
	
	setResposta(arqaux);
	getReposta(arqaux);
//	getRespostaarq(arq);

	int i = fclose(arq);
	int o = fclose(arqaux);
	if ((!i) && (!o))
		printf("\nArquivo fechado!");
	getchar();
	
	return 0;
}

