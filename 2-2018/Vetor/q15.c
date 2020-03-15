#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Diz-se que um número inteiro N é um quadrado perfeito se existirem M
números ímpares consecutivos a partir do valor 1 cuja soma é igual a N. 
Neste caso N=M^2. Exemplo: 16=1+3+5+7(16 é igual à soma dos quatro primeiros 
ímpares a partir de 1) e 16=4^2. Logo 16 representa um quadrado perfeito. 
Escreva um programa que verifique se um valor inteiro positivo fornecido 
pelo usuário é um quadrado perfeito ou não.*/

int main(int argc, char **argv)
{
	int n;
	printf("Digite o valor de N: ");
	scanf(" %d",&n);
	int soma=0;
	for(int i=1; i<=n; i+=2){
		if (soma < n)
			soma += i;
		if (soma == n)
			printf("quad perf");
		if (soma > n)
			printf("imperfeito");
		
		
		
	}
	
	
	return 0;
}

