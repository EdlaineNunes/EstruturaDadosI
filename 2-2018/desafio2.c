#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	srand(time(NULL));
	int menor = -1, maior = 101, aux, x;
	printf("\t\tPense num numero de 0 a 100...\n\n");
	aux = rand () % 101;
	printf("O número sorteado foi: %d\n\n",aux);
	do{
		printf("\tDigite de acordo com a opção:\n\t1- Maior\n\t2- Menor\n\t0- Igual\n");
		printf("Opc:\t");
		scanf(" %d",&x);
		if ( x == 0 ){
			printf("\n\t\tPROGRAMA ENCERRADO!");
			break;
		}
		//maior
		if ( x == 1 ){
			menor = aux;
			aux = menor + 1 + rand () % ( maior - menor );
			printf("\nO número sorteado foi: %d\n\n",aux);		
		}
		//menor
		if ( x == 2 ){
			maior = aux;
			aux = maior - 1 - rand () % ( maior - menor ) ;
			printf("\nO número sorteado foi: %d\n\n",aux);		
		}
		if ( maior - menor == 2){
			printf("\nVocê pensou no num %d",maior - 1);
			break;
		}
		if (( x != 0) && ( x != 1) && ( x != 2))
			printf("\n\t\tERRO! OPÇÃO INVÁLIDA!\n\n");
				
	}while(1);
	return 0;
}

