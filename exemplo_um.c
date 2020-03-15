#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>


int main() 
{
	int a,b;
	printf("Informe o valor de A:");
	scanf(" %d",&a);
	printf("Informe o valor de B:");
	scanf(" %d",&b);
		if (a<b){
			int aux = a;
			a = b;
			b = aux;
		}
	printf("Calculando o mmc\n");
	int teste = a;
		while ((teste%a!=0)||(teste%b!=0)){
			teste++;
		}
	printf("O MMC (%d, %d)==%d\n",a,b,teste);

	
	
	return 0;
}

