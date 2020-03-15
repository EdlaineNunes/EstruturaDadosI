#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(){
	int a;
	srand(time(NULL));
	do{
		int aleatorio = 5 + rand()%15;
		printf ("Chute qual é o numero de 5 a 15 \n");
		scanf(" %d",&a);
			if ((aleatorio == a)){
				printf("Você ACERTOU. O número aleatório é %d. \n",a);
				break;
			}
			if ((aleatorio > a)){
				printf("Você ERROU. O número sorteado é maior que o digitado\n");
			}
			if ((aleatorio < a)){
				printf("Você ERROU. O número sorteado é menor que o digitado\n");
			}
			//else if (aleatorio != a){
				//printf("Você ERROU! O número aleatório é %d \n",aleatorio); }
			getchar();
		} while(1);	
	return 0;
}
