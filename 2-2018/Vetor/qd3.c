#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Leia três notas de um aluno e calcule a média ponderada,
considerando que o peso para a maior nota seja 4 e para as duas
restantes, 3. Imprima uma mensagem “APROVADO” se a média for
maior ou igual a 6 ou “REPROVADO” caso contrário.*/

int main(int argc, char **argv)
{
	float n1,n2,n3,soma;
	printf("Insira a nota I: ");
	scanf(" %f",&n1);
	printf("Insira a nota II: ");
	scanf(" %f",&n2);
	printf("Insira a nota III: ");
	scanf(" %f",&n3);
	if (n1 > n2 && n1 > n3){
		soma = (n1 * 4 + n2 * 3 + n3 * 3)/7;
		printf("Sua nota foi: %.2f.\n",soma);
		if (soma >= 6.0)
			printf("APROVADO!");
		else
			printf("REPROVADO!");
	}
	if (n2 > n1 && n2 > n3){
		soma = (n2 * 4 + n1 * 3 + n2 * 3)/7;
		printf("Sua nota foi: %.2f.\n",soma);
		if (soma >= 6.0)
			printf("APROVADO!");
		else
			printf("REPROVADO!");
	}
	if (n3 > n1 && n3 > n2){
		soma = (n3 * 4 + n1 * 3 + n2 * 3)/7;
		printf("Sua nota foi: %.2f.\n",soma);
		if (soma >= 6.0)
			printf("APROVADO!");
		else
			printf("REPROVADO!");
	}	
	return 0;
}

