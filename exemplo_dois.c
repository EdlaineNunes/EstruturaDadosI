#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//é mais fácil provar que o número não é primo
int main()
{
	int a;
	printf("Digite um número: \n");
	scanf(" %d",&a);
	int p=1;
		for(int b=2;b<a;b++){
			if (a%b==0) {
				p=0;
				break;
			}
		}
			if(!p)
				printf("O número não é primo");
			else 
				printf("O número é primo");
		
	
	
	return 0;
}

