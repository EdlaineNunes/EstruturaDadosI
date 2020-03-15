#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct{
	int hora;
	int min;
	int seg;
	int conversao;
	
}Horario;


int main(int argc, char **argv)
{
	Horario hatual,hfutura,diferenca;
	char ho[8];
	printf(__TIME__);
	strcpy(ho,__TIME__);
	hatual.hora = (ho[0] - '0') * 10 + ho[1] - '0';
	hatual.min = (ho[3] - '0') * 10 + ho[4] - '0';
	hatual.seg = (ho[6] - '0') * 10 + ho[7] - '0';
	printf("\nHora atual: %d : %d : %d",hatual.hora,hatual.min,hatual.seg);
	hatual.conversao = hatual.seg + hatual.min * 60 + hatual.hora * 3600;
	
	printf("Insira hora: ");
	scanf(" %d",&hfutura.hora);
	printf("Insira min: ");
	scanf(" %d",&hfutura.min);	
	printf("Insira seg: ");
	scanf(" %d",&hfutura.seg);
	hfutura.conversao = hfutura.seg + hfutura.min * 60 + hfutura.hora * 3600;
	
	diferenca.hora = (hfutura.conversao - hatual.conversao) / 3600;
	diferenca.min = ((hfutura.conversao - hatual.conversao) / 3600) % 60;
	diferenca.seg = (hfutura.conversao - hatual.conversao) / 60;
	
	printf("Hora atual: %d : %d : %d",hatual.hora, hatual.min, hatual.seg);
	printf("Horas de diferença: %d : %d : %d",diferenca.hora, diferenca.min, diferenca.seg);
	
	
	
	return 0;
}
