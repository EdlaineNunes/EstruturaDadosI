#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Faça um programa que leia 3 valores (inteiros e positivos) de retas
e verifique se eles conseguem formar ou não um triângulo.*/

/*Para construir um triângulo é necessário que a medida de qualquer um 
 * dos lados seja menor que a soma das medidas dos outros dois e maior 
 * que o valor absoluto da diferença entre essas medidas.*/


//nao funcional

int main(int argc, char **argv)
{
	int ld1, ld2, ld3;
	printf("Insira o lado I: ");
	scanf(" %d",&ld1);
	printf("Insira o lado II: ");
	scanf(" %d",&ld2);
	printf("Insira o lado III: ");
	scanf(" %d",&ld3);
	
	if (ld1 < (ld2 + ld3) && ld1 > (ld2 - ld3))
		printf("Triângulo existente!\n");
	else if (ld2 < (ld1 + ld3) && ld2 > (ld1 - ld3))
		printf("Triângulo existente!\n");
	else if (ld3 < (ld2 + ld1) && ld3 > (ld2 - ld1))
		printf("Triângulo existente!\n");
	else 		
		printf("Triângulo não existente!\n");
	return 0;
}

