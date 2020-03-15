#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// ------------ CODIGO DE ADRIANO -----------------//

typedef struct Carro{
	char modelo[50];
	int ano;
}Carro;

void setCarro(FILE* arq){
	
	Carro aux;
	
	printf("Digite o modelo:");
	scanf(" %[^\n]s",aux.modelo);
	printf("Digite o ano:");
	scanf(" %d",&aux.ano);
	
	fseek(arq,sizeof(Carro),SEEK_END);
	
	if(fwrite(&aux,sizeof(Carro),1,arq))
		printf("Carro Salvo com Sucesso!\n");
	else{
		printf("Carro não salvo!!");
	}
	

}

void getCarro(FILE* arq){
	
	Carro aux;
	
	fseek(arq,sizeof(Carro),SEEK_SET);
	
	while(fread(&aux,sizeof(Carro),1,arq)){
		printf("Modelo: %s \nAno: %d\n",aux.modelo,aux.ano);
		
	}
	
}

int main(int argc, char **argv)
{
	FILE *arq = NULL;
	
	arq= fopen("testeBSI.txt","r+");
	if(!arq)
		arq = fopen("testeBSI.txt","w+");
	if(!arq){
		printf("Programa não conseguiu abrir o arquivo!!\n");
		return 0;
	}
	
	setCarro(arq);
	getCarro(arq);
	
	int i=fclose(arq);
	if (!i)
		printf("Arquivo Fechado!");
		
	return 0;
}
