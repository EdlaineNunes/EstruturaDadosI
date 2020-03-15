#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	char nome[50];
	int numHrAce;
	char hospedagem;
	float valorB,valorF;
}Clientes;

int menu(){
	int opc;
		printf("___MENU__\n\n");
		printf("1 - Cadastrar cliente\n");
		printf("2 - Extrato cliente\n");
		scanf(" %d", &opc);
	return opc;
}

Clientes setCliente(){
	Clientes novo;
		printf("Digite o nome: ");
		scanf(" %[^\n]s", novo.nome);
		printf("Digite o número de horas de acesso: ");
		scanf(" %d", &novo.numHrAce);
		printf("POSSUI HOSPEDAGEM? S-SIM / N-NÃO: ");
		scanf(" %c", &novo.hospedagem);
	return novo;
}

void getOrdena(Clientes novo[], int tam){
	for(int i=0; i<tam; i++){
		for(int j=0; j<tam-1-i; j++){
			if(novo[j].numHrAce<novo[j+1].numHrAce){
				Clientes troca = novo[j];
						 novo[j] = novo[j+1];
						 novo[j+1] = troca;
			}
		}
	}
}

void getCliente(Clientes novo[], int tam){
	for(int i=0; i<tam; i++){
		getOrdena(novo,tam);
	}
	float dsct;
	printf("\nNOME\tHORAS DE ACESSO\t  HOSPEDAGEM\tVALOR BRUTO\tVALOR DESCONTO\tVALOR FINAL\n\n");
	for(int i=0; i<tam; i++){
		if(i==0){
			if(novo[i].numHrAce<=100 && ((novo[i].hospedagem=='S')||(novo[i].hospedagem=='s'))){
				novo[i].valorF = ((novo[i].numHrAce/1.25)+20)-((novo[i].numHrAce/1.25)+20)*0.2;
				novo[i].valorB = ((novo[i].numHrAce/1.25)+20);
				dsct = ((novo[i].numHrAce/1.25)+20)*0.2;
			}
			if(novo[i].numHrAce<=100 && ((novo[i].hospedagem=='N')||(novo[i].hospedagem=='n'))){
				novo[i].valorF = (novo[i].numHrAce/1.25)-(novo[i].numHrAce/1.25)*0.2;
				novo[i].valorB = ((novo[i].numHrAce/1.25));
				dsct=((novo[i].numHrAce/1.25))*0.2;
			}
			if(novo[i].numHrAce>100 && ((novo[i].hospedagem=='S')||(novo[i].hospedagem=='s'))){
				novo[i].valorF = (((novo[i].numHrAce-100)*1.85)+100)-(((novo[i].numHrAce-100)*1.85)+100)*0.2;
				novo[i].valorB = (((novo[i].numHrAce-100)*1.85)+100);
				dsct = (((novo[i].numHrAce-100)*1.85)+100)*0.2;
			}
			if(novo[i].numHrAce>100 && ((novo[i].hospedagem=='N')||(novo[i].hospedagem=='n'))){
				novo[i].valorF = ((novo[i].numHrAce-100)*1.85)-((novo[i].numHrAce-100)*1.85)*0.2;
				novo[i].valorB = (((novo[i].numHrAce-100)*1.85)+80);
				dsct = (((novo[i].numHrAce-100)*1.85)+80)*0.2;
			}
			printf("%s\t%d\t\t  %c\t\t%.2f\t\t%.2f\t\t%.2f\n\n",novo[i].nome,novo[i].numHrAce,novo[i].hospedagem,novo[i].valorB,dsct,novo[i].valorF);
		}
		else{
			if(novo[i].numHrAce<=100 && ((novo[i].hospedagem=='S')||(novo[i].hospedagem=='s'))){
				novo[i].valorF = ((novo[i].numHrAce/1.25)+20);
			}
			if(novo[i].numHrAce<=100 && ((novo[i].hospedagem=='N')||(novo[i].hospedagem=='n'))){
				novo[i].valorF = (novo[i].numHrAce/1.25);
			}
			if(novo[i].numHrAce>100 && ((novo[i].hospedagem=='S')||(novo[i].hospedagem=='s'))){
				novo[i].valorF = (((novo[i].numHrAce-100)*1.85)+100);
			}
			if(novo[i].numHrAce>100 && ((novo[i].hospedagem=='N')||(novo[i].hospedagem=='n'))){
				novo[i].valorF = ((novo[i].numHrAce-100)*1.85)+80;
			}
		printf("%s\t%d\t\t  %c\t\t%.2f\t\t0\t\t%.2f\n\n",novo[i].nome,novo[i].numHrAce,novo[i].hospedagem,novo[i].valorF,novo[i].valorF);
		}
	}
	float faturamento=0;
	for(int i=0; i<tam; i++){
		faturamento+=novo[i].valorF;
	}
	printf("O faturamento da empresa foi de R$ %.2f\n\n", faturamento);
}



int main()
{
	Clientes novo[100];
	int cont=0;
	
	do{
		switch(menu()){
			case 1: novo[cont++] = setCliente();
				break;
			case 2: getCliente(novo,cont);
				break;
		}
	}while(1);
	
	return 0;
}
