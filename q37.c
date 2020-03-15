#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*37. Faça um programa que leia uma string S, e criptografe-a com o seguinte algoritmo: sorteie um vetor de strlen(S)
números, com valores aleatórios e não-repetitivos entre 0 e strlen(s)-1 (inclusive). Após o sorteio, embaralhe
as letras da mensagem original, de acordo com as posições sorteadas no vetor. Atenção, todos os caracteres tem
que ter sua posição inicial alterada!
Exemplo de Execução:
String:
AULA DE PE
Vetor Sorteado: 1369847502
Texto Cifrado: PAEUD LE A*/

int main(int argc, char **argv)
{
	char frase[50];
	char cript[50];
	printf("Digite um nome/frase: ");
	scanf("%[^\n]s",frase);
	int t=strlen(frase);
	int a, rep=0;
	int vet[t];
	
	//fazendo a criptografia
	for(int i=0; i<t; i++){
		do{
			a = rand()%t;
			rep=0;
			for (int j=0; j<i; j++)
				if(vet[j]==a)
					rep=1;
		}while(rep);
		vet[i]=a;
		
	}
	//imprimindo a chave
	printf("\nCHAVE\n");
	for(int i=0; i<t; i++)
		printf("%d",vet[i]);
	printf("\nCRIPTOGRAFADO\n");
	for (int i=0; i<t; i++)
		cript[vet[i]]=frase[i];
	printf("%s",cript);
	
	return 0;
}

