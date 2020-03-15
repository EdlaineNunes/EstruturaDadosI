#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n, ver = 0, aux = 0 ;
	printf("Quantos termos perfeitos deseja ver? ");
	scanf(" %d",&n);
	
	do{
		for (int i = 1; i < n; i++){
			if ( i % 2)
				continue;
			else {
				aux+=i;
				i++;
			}
		}
		if (aux == n){
			printf("%d é um número perfeito!\n",n);
			ver++;
		}
		if (ver == n)
			return 0;
				
	}while(1);
	
	return 0;
}

