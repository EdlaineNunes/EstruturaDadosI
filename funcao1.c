#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	int horas;
	int minutos;
	int segundos;
}Horario;

Horario difHorario( Horario h1, Horario h2){
	int segundos1, segundos2;
	
	segundos1 = h1.horas*3600  + h1.minutos*60 + h1.segundos;
	segundos2 = h2.horas*3600  + h2.minutos*60 + h2.segundos;
	
	int dife;
	
	if (segundos1>segundos2)
		dife = segundos1-segundos2;
	else 
		dife = segundos2-segundos1;
		
	Horario dif;
	dif.horas = dife/3600;
	dif.minutos =(dife%3600)/60;
	dif.segundos = (dife%3600)%60;
	
	return dif;	
}

void printHorario (Horario dif){
	
	printf("Hora(s): %d \nMinuto(s): %d \nSegundo(s): %d\n",dif.horas,dif.minutos,dif.segundos);
	
}

int main(int argc, char **argv)
{
	Horario h[2];
	
	for (int i=0; i<2;i++){
		printf("Insira Hora1: \n");
		scanf(" %d",&h[i].horas);
		printf("Insira Minutos1: \n");
		scanf(" %d",&h[i].minutos);
		printf("Insira Segundos1: \n");
		scanf(" %d",&h[i].segundos);
		
		printf("Horario %d: \n",1+i);
		printHorario(h[i]);
		printf("\n");
	}
	Horario diferenca = difHorario (h[0],h[1]);
	printf("Diferença dos Horarios: \n");
	printHorario(diferenca);
	return 0;
}

