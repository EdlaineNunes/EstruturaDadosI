#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
/*problem 2*/

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

Hora difhora(Hora h1, Hora a){

	int seg1 = a.horas*3600 + a.minutos*60 + a.segundos;
	int seg2 = h1.horas*3600 + h1.minutos*60 + h1.segundos;
	
	int dife;
	if (seg1 > seg2)
		dife = seg1 - seg2;
	if (seg1 < seg2)
		dife = seg2 - seg1;
	
	Hora dif;
	
	dif.horas = dife/3600;
	dif.minutos = (dife/3600)/60;
	dif.segundos = (dife/3600)%60;
	
	return dif;
}

void getHora( Hora a){
	printf("Horário atual: \n");
	printf("%d : ",a.horas);
	printf("%d : ",a.minutos);
	printf("%d.\n",a.segundos);
}

void printHora (Hora dif){
	
	printf("Hora(s): %d \nMinuto(s): %d \nSegundo(s): %d\n",dif.horas,dif.minutos,dif.segundos);
	
}
int main(int argc, char **argv)
{
//	printf("\n\n %s\n\n", __TIME__);
	Hora atual;
	atual=setHora(atual);
	getHora(atual);
	
	Hora h1[2];
	for (int i=0; i<1; i++){
		printf("Digite a(s) Hora(s):\n");
		scanf(" %d",&h1[i].horas);
		printf("Digite o(s) Minuto(s):\n");
		scanf(" %d",&h1[i].minutos);
		printf("Digite o(s) Segundo(s):\n");
		scanf(" %d",&h1[i].segundos);
	}
	Hora dif;
	printf("Diferença dos Horarios: \n");
	printHora(dif);
	return 0;
}

