#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int t,s=1;
	do{
		printf("Digite o valor de n:  ");
		scanf(" %d",&t);
		if ( t >= 2 )
			break;
		else printf("\n\tTENTE NOVAMENTE!\n");
	}while(1);
	printf("\n\n");
	for(int i = t; i > 0; i--){
		for(int e = i + 1; e >= 0; e--)
			printf(" ");
		for(int i= 0; i<s; i++)
			printf("*");
		printf("\n");
		s+=2;
	}
	
	return 0;
}

