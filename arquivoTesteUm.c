#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	//inicializa 
	FILE* arq = NULL;
	
	//abre o arquivo verificando se existe (rb+)
	arq = fopen ("testeBSI.txt", "rb+");
	
	//se não existir, cria (wb+)
	if (!arq)
		arq = fopen("testeBSI.txt", "wb+");
		
	//se continuar não existindo por não haver espaço (por ex) 
	//emite msg dizendo q nao foi possível
	if (!arq){
		printf("Programa não conseguiu abrir o arquivo!\n");
		return 0;		
	}
	
	//fecha o arquivo
	int i = fclose(arq);
	
	//caso consiga fechar sem prob, recebe 0, então verifica se foi realmente fechado
	if (!i)
		printf("Arquivo fechado!");
	getchar();
	
	return 0;
}

