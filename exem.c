#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
	int x;
	printf("Digite o valor de teste");
	scanf(" %d",&x);
	int primo=1;
	for (int i=2; i<(x/2); i++;)
		if(x%i==0){
			primo--;
			break;
		}
		if (primo)
		printf("%d é primo",x);
		else 
		printf("%d não é primo",x);
	}
	
	return 0;
}

