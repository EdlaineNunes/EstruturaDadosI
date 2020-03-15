#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	int n,r=1;
	do { 
		printf("Digite o valor de N: ");
		scanf(" %d",&n);
		if ( n >= 0)
			break;
	}while(1);
	int i=n;
	do{
		r*=i;
		i--;
	}while (i>=1);
	printf("%d",r);
	return 0;
}

