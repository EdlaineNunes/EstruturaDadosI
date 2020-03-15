#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//#define TAM 25

int main(int argc, char **argv)
{
	
	int cartela[25];
	srand(time(NULL));
	int i=0;
	//se usar o for cai em loop, entao usa o do
	//for (int i=60; i<TAM; i++)
	
	// sempre que usar o getchar() usar o setbuf(stdin, NULL) antes e dps o system ("clear")
	
	do{
		int n = 1 + rand()%60;
		int repetido = 0;
		for (int k=0; k<i;k++)
			if (n == cartela[k]){
				repetido=1;
				break;
			}
		if (!repetido){
			cartela[i]=n;
			i++;
			//printf("%d - ",n);
			//para imprimir em formato de tabela
			printf("%d\t",n);
			if(i%5 == 0)
			printf("\n");
		}
	} while (i<25);
	
	return 0;
}

