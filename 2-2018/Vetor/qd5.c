#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Faça um programa leia as 5 notas de um quesito da Escola de Samba,
descarte a maior e a menor nota, e apure a média das notas restantes.*/

int main()
{
	int va,vb,vc,x1,x2;
	printf("Digite o valor de A: ");
	scanf(" %d",&va);
	printf("Digite o valor de B: ");
	scanf(" %d",&vb);
	printf("Digite o valor de C: ");
	scanf(" %d",&vc);
	int del=((vb*vb)- (4*va*vc));
	int a = sqrt(del);
	printf("O valor de Delta é: %d\n",del);
	x1=(-1 * vb + a)/(2 * va);
	x2=((vb) - a)/(2*(va));
	printf("x1= %d\n", x1);
	printf("x2= %d\n", x2);
	
	
	/*float n1,n2,n3,n4,n5;
	printf("Insira a nota 1: ");
	scanf(" %f",&n1);
	printf("Insira a nota 2: ");
	scanf(" %f",&n2);
	printf("Insira a nota 3: ");
	scanf(" %f",&n3);
	printf("Insira a nota 4: ");
	scanf(" %f",&n4);
	printf("Insira a nota 5: ");
	scanf(" %f",&n5);
	printf("Insira a nota 6: ");
	scanf(" %f",&n6);
	*/
	return 0;
}

