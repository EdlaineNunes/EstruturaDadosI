#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	char nome[50];
	char email[50];
	int telefone;
	char afinidade[30];
}Cadastro;

int printMenu(){
	printf("===========MEUNU===========\n");
	printf("1- Cadastro\n");
	
	
	
	int opc;
	scanf(" %d",&opc);


	return opc;
}

Cadastro setCadastro(){
	Cadastro novo;
	char teste[50];
	int len = 0;
	printf("\n=====CADASTRO=====\n");
	printf("Digite o nome:");
	scanf(" %[^\n]s", novo.nome);
	do{
		
		printf("Digite o e-mail:");
		scanf(" %[^\n]s", teste);
		len = (strlen(teste));
		validaEmail(teste,len);
		
		
	}while(1);
	
	
	printf("Digite o telefone:");
	scanf(" %d", &novo.telefone);
	printf("Digite qual a afinidade:");
	scanf(" %[^\n]s", novo.afinidade);	
	return novo;
}

int validaEmail (char teste, int len){
	int conta=0;
	int conte=0;
	int contp=0;
	for (int i=0; i<len; i++){
		if (strcmp (teste,'@')==0)
			conta++;
			for (int j=i; j<len; j++)
				if (strcmp(teste,'.')==0)
					contp++;
					if (strcmp(teste, ' ')==0)
						conte++;
	}
	if ((conta==1)&&(conte==0)&&(contp>=1))
		return 0;
	else 
		return 1;
	
}


int main(int argc, char **argv)
{
	//int p[100];
//	int cont=0;
	do{	
		switch (printMenu()){
			case 1:setCadastro();
					
					break;
			
			
		}
	
	}while(1);
	return 0;
}

