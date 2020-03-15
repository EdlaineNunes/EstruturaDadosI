#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(){
	
	srand(time(NULL));
	int n;
	printf("Digite o valor de N: ");
	scanf(" %d",&n);
	char nomes[n][100], vaux[100],nomesfinal[n][100];
	int tempo[n], tempofinal[n];
	for (int i=0; i<n; i++){
		printf("Digite o nome do %dº corredor: ",i+1);
		scanf(" %[^\n]s",nomes[i]);
		tempo[i] = 10 + rand () % ( 91 );
	}
	printf("\n=======================================");
	printf("\nGrid de Largada \t Tempo gasto:");
	for (int i=0; i<n; i++)
		printf("\n%dº: %s \t\t\t %d",i+1,nomes[i],tempo[i]);
		
	//cópia dos dados
	for (int i=0; i<n; i++){
		tempofinal[i] = tempo[i];
		strcpy(nomesfinal[i], nomes[i]);		
	}
	
	//ordenação
	for (int i=0; i<n; i++)
		for (int j=0; j<n-i-1; j++)
			if (tempofinal[j] > tempofinal[j+1]){
				int aux = tempofinal[j];
				strcpy(vaux,nomesfinal[j]);
				
				tempofinal[j] = tempofinal[j+1];
				strcpy(nomesfinal[j],nomesfinal[j+1]);
				
				tempofinal[j+1] = aux;
				strcpy(nomesfinal[j+1],vaux);
			}
	printf("\n\n");
	printf("\n=======================================");
	printf("\nGrid de Chegada \tTempo gasto:");
	for (int i=0; i<n; i++)
		printf("\n%dº: %s \t\t\t %d",i+1,nomesfinal[i],tempofinal[i]);
	
	//pesq inalterado
	printf("\n");
	printf("\n=======================================");
	printf("\nPosição Inalterada");
	for (int i=0; i<n; i++)
		if(strcmp(nomes[i], nomesfinal[i]) == 0)
			printf("\n%s",nomes[i]);
		
	//pesq > e < reação
	printf("\n");
	printf("\n=======================================");
	int sub = 0, maiorReacao = 0, menorReacao = 0;
	char nomeMaior[100], nomeMenor[100];
	for(int i=0; i<n; i++)
		if(strcmp(nomes[i], nomesfinal[i]) != 0)
			for(int j=0; j<n; j++)
				if(tempo[i] == tempofinal[j]){
					sub = i-j;
					if(sub > maiorReacao){
						maiorReacao = sub;
						strcpy(nomeMaior,nomesfinal[j]);
					}
					if(sub < menorReacao){
						menorReacao = sub;
						strcpy(nomeMenor, nomesfinal[j]);					
					}
				}
	printf("\nMaior reação");
	if(maiorReacao > 0)
		printf("\n\n%s : +%d",nomeMaior, maiorReacao);
	else
		printf("\n\nNão houve maior reação");
	printf("\n");
	printf("\n=======================================");
	printf("\nMenor reação");
	if(menorReacao < 0)
		printf("\n\n%s : %d",nomeMenor, menorReacao);
	else
		printf("\n\nNão houve menor reação");
	return 0;
}

