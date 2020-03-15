#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	do{
		printf("============== M E N U ==============\n");
		printf("\t1 - Área do Retângulo;\n");
		printf("\t2 - Área do Trapézio;\n");
		printf("\t3 - Área do Triângulo;\n");
		printf("\t4 - Área do Círculo;\n");
		printf("\t5 - EXIT!\n");
		printf("Opc: ");
		int opc;
		scanf(" %d",&opc);
		printf("\n");
		switch ( opc ){
			case 1: printf("\tÁREA DO RETÂNGULO\n\n");
					int baser, alt, res;
					printf("Digite o valor da base: \n");
					scanf(" %d",&baser);
					printf("Digite o valor da altura: \n");
					scanf(" %d",&alt);
					res = baser * alt;
					printf("A área é: %d\n",res);
					printf("=====================================\n\n");
					break;
					
			case 2: printf("\tÁREA DO TRAPÉZIO\n\n");
					int bme, bma, h, r;
					printf("Digite o valor da BASE MENOR: \n");
					scanf(" %d",&bme);
					printf("Digite o valor da BASE MAIOR: \n");
					scanf(" %d",&bma);
					printf("Digite o valor da ALTURA: \n");
					scanf(" %d",&h);
					r = h * ( bme + bma ) / 2;
					printf("A área é: %d\n",r);			
					printf("=====================================\n\n");
					break;
					
			case 3: printf("\tÁREA DO TRIÂNGULO\n\n");
					int base, altura, resp;
					printf("Digite o valor da base: \n");
					scanf(" %d",&base);
					printf("Digite o valor da altura: \n");
					scanf(" %d",&altura);
					resp = ( base * altura ) / 2;
					printf("A área é: %d\n",resp);			
					printf("=====================================\n\n");
					break;
					
			case 4: printf("\tÁREA DO CÍRCULO\n\n");
					int raio, d, aux;
					printf("Digite o valor do raio\n");
					scanf(" %d",&raio);
					d = ( 3.14 * raio );
					aux = d * d;
					printf("O valor da área é: %d\n",aux);
					printf("=====================================\n\n");
					break;
					
			case 5: printf("\tENCERRADO COM SUCESSO!\n");
					printf("=====================================\n\n");
					break;
					
			default:printf("Opção Inválida\n");
					printf("=====================================\n\n");
					break;
			
		}
		if (opc == 5)
			break;
	}while(1);	
	return 0;
}

