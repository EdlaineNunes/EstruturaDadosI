#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
	int a;
	srand(time(NULL));
	
	do{
		int aleatorio = rand()%21;
		printf ("Chute qual é o numero de 0 a 20 \n");
		scanf(" %d",&a);
			if ((aleatorio == a)){
				printf("Você ACERTOU. O número aleatório é %d. \n",a);
				break;}
			else if (aleatorio != a){
				printf("Você ERROU! O número aleatório é %d \n",aleatorio); }
			getchar();
		} 
				
		while(1);
		
		//i++;
		//printf("O número de tentativas foi: %d \n",i); 
		// tem que colocar o numero de tentativas
	
		
	return 0;
}

