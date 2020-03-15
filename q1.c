#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/*Faça  um  programa  em  C  que cria  uma struct Horário, contendo informações  de  Horas,  
Minutos  e Segundos. Utilizando  a  constante  __TIME__  faça  a  alimentação  de uma variável 
do  tipo  Horário. Imprima  na  tela  a hora atual  com  base  na struct preenchida.
 */
 
 //crie um prog que utilizando funções valide ou gere um cpf valido 

typedef struct{
	int horas;
	int minutos;
	int segundos;
}Hora;

int conv (int a, int b){
	char t[10];
	strcpy(t,__TIME__);
	int h=(t[a]-'0')*10+(t[b]-'0');
	
	return h; 
} 
Hora setHora(Hora a){
	a.horas=conv(0,1);
	a.minutos=conv(3,4);
	a.segundos=conv(6,7);
	
	return a;
}

void getHora( Hora a){
	printf("%d horas\n",a.horas);
	printf("%d minutos\n",a.minutos);
	printf("%d segundos\n",a.segundos);
}
 
int main(int argc, char **argv)
{
	printf("\n\n %s\n\n", __TIME__);
	Hora atual;
	atual=setHora(atual);
	getHora(atual);
	
	return 0;
}

