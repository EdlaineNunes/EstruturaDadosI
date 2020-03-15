#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*37. Faça um programa que leia uma string S, e criptografe-a com o seguinte algoritmo: sorteie um vetor de strlen(S)
números, com valores aleatórios e não-repetitivos entre 0 e strlen(s)-1 (inclusive). Após o sorteio, embaralhe
as letras da mensagem original, de acordo com as posições sorteadas no vetor. Atenção, todos os caracteres tem
que ter sua posição inicial alterada!
Exemplo de Execução:
String:
AULA DE PE
Vetor Sorteado: 1369847502
Texto Cifrado: PAEUD LE */


int main(){
	
	int repetido,aux;
	char palavra[100];
	char palavraaux[100];
	
	printf("Digite uma frase: \n");
	scanf(" %[^\n]s",palavra);
	int tam=strlen(palavra);
	
	int vet[tam];
	
	for(int i=0;i<tam;i++){
		do{
			aux=rand()%tam;
			repetido=0;
			for(int j=0;j<i;j++){
				if(vet[j]==aux){
					repetido=1;
				}
			}
		}while(repetido==1);
		vet[i]=aux;
	}
	//impressão da chave da criptografia 
	for (int i = 0; i < tam; i++)
		printf("%d",vet[i]);
	//impressão criptografada
	for (int i = 0; i < tam; i++)
		palavraaux[vet[i]]=palavra[i];
	
	printf("\n%s",palavraaux);
	
	return 0;
}
a

