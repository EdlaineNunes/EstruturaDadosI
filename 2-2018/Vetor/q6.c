#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(int argc, char **argv)
{
	char a,b;
	int c;
	printf("Insira um caractere: ");
	scanf(" %c",&a);
	printf("Insira outro caractere: ");
	scanf(" %c",&b);
	c = ( int ) a * b;
	printf("O caractere '%c' equivale a %d, e o caractere '%c' equivale a %d\n",a,a,b,b);
	printf("Resultado do produto desses caracteres: %d",c);
	
	return 0;
}

