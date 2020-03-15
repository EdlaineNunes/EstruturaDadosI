#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int a=1, b=1, c=0,cont=0,n,maior = 0, menor = 999999999;
	float div;
	printf("\nDigite um número: ");
	scanf(" %d",&n);
	printf("Dois primeiros termos seguintes: ");
	do{
		a = b; 
		b = c;
		c = a + b;
		if (c > n){
			printf("%d\t",c);
			if( c > maior)
				maior = c;
			if ( c < menor)
				menor = c;
			cont++;
		}
	}while (cont < 2);
	div = (float) maior / menor;
	printf("\nA divisão de %d por %d é %.2f ",maior,menor,div);
	
	return 0;
}

