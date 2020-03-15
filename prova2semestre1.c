#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/*SVC - sistema de venda e controle de passagem */

// menu okay , cadastro okay
int printMenuVoo(){
	system("clear");
	printf("1- Cadastrar novo voo; \n2- Relatório resumo do voo; \n3- Vender passagens.\n");
	int opc;
	scanf(" %d",&opc);
	getchar();
	return opc;
}

typedef struct {
	int nvoo [50];
	char cidori[100];
	char ciddest[100];
	int assdis[40];
	float preco;
}NovoVoo;

int setSorte (){
	int sorte;
	sorte = 10000 + rand()%( 99999-10000);
	printf("%d\n",sorte);
	return sorte;	
}

void getNovoVoo (NovoVoo v[], int n){
	printf("\n");
	
	if (n>0)
		for (int i=0; i<n; i++){
			
			printf ("\nN voo:");
			setSorte();
			printf("Cid Ori: %s\nCid Dest: %s\nN assent total: 40\nValor: %.2f\n",
				v[i].cidori, v[i].ciddest, v[i].preco);
		}
	else printf ("Nenhum voo cadastrado!\n");
	
	setbuf(stdin,NULL);
	getchar();	
}

NovoVoo setNovoVoo(){
	NovoVoo voo;
	
	//setSorte();
	printf("Numero do Voo: ");	
	setSorte();
	
	printf("Digite a cidade de origem:\n");
	scanf(" %[^\n]s",voo.cidori);
	printf("Digite a cidade de destino:\n");
	scanf(" %[^\n]s",voo.ciddest);	
	printf("40 assentos disponíveis!\n");
	printf("Digite o preço:\n");
	scanf(" %f",&voo.preco);
	getchar();
	
	return voo;
}

int main(int argc, char **argv)
{
	NovoVoo nv[100];
	int cont=0;
	srand(time(NULL));
	do{
		switch (printMenuVoo()){
			case 1: nv[cont++] = setNovoVoo();
					break;
			case 2: getNovoVoo(nv,cont);
					break;
			case 3:
					break;
			default: printf("\nOPÇÃO INVÁLIDA!\n");		
		}
		
	}while (1);
	return 0;
}

