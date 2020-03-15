#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//FECHAMENTO MENSAL NÃO FUNCIONA.

typedef struct{
	int num;
	char nome[100];
	float saldo;	
}Conta;

typedef struct{
	char tipo;
	char desc[50];
	float valor;	
	Conta nconta;
}Mov;

void Linha(){
	printf("\n\n");
	for(int i=0; i<50; i++)
		printf("=");
	printf("\n\n");
	
}

int getDv(int c){
	int dv;
	int dUm, dDois, dTres;
	dUm = (c / 100);
	dDois = (c - (dUm * 100)) /10;
	dTres = (c - ((dUm*100) + (dDois*10)))/1;
	//printf("\n dUM:%d\t dDois %d\tDtres %d",dUm,dDois,dTres);
	dv = ((dUm * 3) + (dDois * 4) + (dTres * 5 )) % 10;
	//printf("\nDV: %d\n",dv);
	return dv;
	
}

int getNumConta(){
	int aux;
	aux = 100 + rand () % 999;
	//printf("Conta sem dv: %d", aux);
	//getDv(aux);
	int conta;
	conta = aux * 10 + getDv(aux);
	return conta;
}

Conta setConta(Conta v[], int q){
	Conta novo;
	Linha();
	printf("\t\tCADASTRO DE CONTA\n");
	int aux;
	int rep;
	do{
		rep = 0;
		aux = getNumConta();
		for(int i=0; i<q; i++)
			if(aux == v[i].num)
				rep = 1;
		if (rep)
			continue;
		novo.num = aux;
		break;		
	}while(1);
	printf("Nº: %d\n",novo.num);
	printf("Insira o nome:\t");
	scanf(" %[^\n]s",novo.nome);
	novo.saldo = 0;
	return novo;	
}

int validaTipo(char *v){
	if((*v == 'd') || (*v == 'D') || (*v == 'c') || (*v == 'C'))
	return 1;
return 0;	
}

int atualizaSaldo(char v[], float valor, Conta c[], int cont, int indice){
	for(int i=0; i<cont;i++)
		if((v[indice] == 'd') || (v[indice] == 'D')){
			c[indice].saldo -=valor;
			return c[indice].saldo;
		}
	for(int i=0; i<cont;i++)
		if ((v[i] == 'c') || (v[i] == 'C')){
			c[indice].saldo +=valor;
			return c[indice].saldo;
		}
	return 0;
}

int validaConta(Conta v[], int q, int aux){
	for(int i=0; i<q; i++)
		if (v[i].num == aux)
			return i;
	return -1;
}

Mov setMov(Conta v[], int q,Mov m[], int mov){
	Mov novo;
	int aux;
	char auxtipo[2];
	int ver;
	float auxvalor;
	Linha();
	if(q>0){
		printf("\t\tCADASTRO DE MOVIMENTAÇÕES\n\n");
		do{
			printf("Insira o Nº da conta:\t");
			scanf(" %d",&aux);
			int verConta = validaConta(v,q,aux);
			if (verConta != -1){
				do{
					printf("Insira o tipo de movimentação[C/D]:\t");
					scanf(" %c",auxtipo);
					ver = validaTipo(auxtipo);
					if (ver == 1){
						novo.tipo = *auxtipo;
						printf("Insira a descrição:\t");
						scanf(" %[^\n]s",novo.desc);
						printf("Insira o valor: R$\t");
						scanf(" %f",&auxvalor);
						novo.valor = auxvalor;
						novo.nconta.saldo = atualizaSaldo(auxtipo,auxvalor,v,q,verConta);
						novo.nconta = v[ver];
						return novo;
					}
					else
						printf("\nTipo de movimentação inválida!");
					}while(1);
			}
			else
				printf("\n\t\tCONTA INVÁLIDA!\n\tTENTE NOVAMENTE.\n");
			
		}while(1);		
	}
	else
		printf("É impossível ter movimentações sem contas cadastradas!");
	return novo;
}


Mov setMovAut(Conta v, char tip, float jur){
	
	Mov novo;
	novo.tipo=tip;
	novo.nconta = v;
	char fab[20] = {"Faturamento Mensal"};
	strcpy(novo.desc,fab);
	if(novo.tipo == 'd')
		novo.nconta.saldo -= jur;
	if(novo.tipo == 'c')
		novo.nconta.saldo += jur;
	return novo;
}

int setFechamentoMensal(Conta c[], int contC,Mov m[], int *mov){
	float juros=0;
	char tip;
	for(int i=0; i<contC; i++){
		if(c[i].saldo < 0){
			juros = (c[i].saldo * 0.02 * 1);
			tip = 'd';
		//	(*mov)++;
			m[*mov++] = setMovAut(c[i],tip,juros);
			//m[*mov+1] = setMovAut(c,contC,i,tip,juros);
			//m[mov+1].nconta.saldo = atualizaSaldo(tip,juros,c,contC,mov+1);
			//m[mov+1].desc = 'FechamentoMensal';
		}
		else{
			tip = 'c';
			juros = (c[i].saldo * 0.01 * 1);
		//	(*mov)++;
			m[*mov++] = setMovAut(c[i],tip,juros);
			//m[mov+1].nconta.saldo = atualizaSaldo(tip,juros,c,contC,mov+1);
			
		}
	}
	
	return 0;
}

void getConta(Conta v[], int q){
	Linha();
	if(q>0){
		printf("\n\t\tContas Cadastradas:\n");
		for(int i=0; i<q; i++)
			printf("%dº - NºConta: %d --> Nome: %s       saldo:%.2f\n",i+1,v[i].num, v[i].nome,v[i].saldo);
		Linha();		
	}
	else{
		printf("\t\tNenhuma conta registrada!\n");
		Linha();
	}
}

void getMovExtrato(Conta c[], int conta, Mov v[], int *q){
	Linha();
	if(q>0){
		printf("\n\t\tMovimentações:\n");
		printf("\n\tInsira o numero da conta:\n");
		int aux;
		scanf(" %d",&aux);
		int ver = validaConta(c,conta,aux);
		if(ver != 1){
			printf("\nMOVIMENTAÇÕES DA CONTA %d\n",aux);
			for (int a=0; a<conta; a++)
				printf("Nome do Cliente: %s\n",c[ver].nome);
			printf("Nº Mov\tTipo\tDescrição\t\tValor\n");
			for(int i=0; i<*q; i++)
				printf("%dº\t%c\t%s\tR$ %.2f\n",i+1,v[i].tipo, v[i].desc, v[i].valor);
				
			printf("\nSaldo final: R$ %.2f",c[ver].saldo);
		}
		else{
			printf("Conta inexistente!");
			Linha();
		}		
	}
	else{
		printf("\t\tNenhuma conta registrada!\n");
		Linha();
	}
}

int Opc(){
	int opc;
	Linha();
	printf("\t\tMENU PRINCIPAL\n\n");
	printf("\t1 - Cad Conta\n");
	printf("\t2 - Movimentar Conta\n");
	printf("\t3 - Fechamento Mensal\n");
	printf("\t4 - Ver Movimentações da Conta\n");
	printf("\t5 - GetConta\n");
	
	scanf(" %d",&opc);
	return opc;	
}

int main(int argc, char **argv)
{
	srand(time(NULL));
	Conta c[100];
	int cont=0;
	Mov m[100];
	int contMov=0;
	
	do{
		switch(Opc()){
			case 1: c[cont] = setConta(c, cont);
					cont++;
					break;
			case 2: m[contMov] = setMov(c, cont, m, contMov);
					contMov++;
					break;
			case 3: setFechamentoMensal(c,cont,m,&contMov);
					break;
			case 4: getMovExtrato(c,cont,m,&contMov);
					break;
			case 5: getConta(c, cont);
					break;
			default: printf("\nINVÁLIDO!\n");		
		}	
	}while(1);
	
	return 0;
}

