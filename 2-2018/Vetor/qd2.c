#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

/*Programe uma calculadora IMC. Leia as informações e informe ao
usuário se ele está abaixo do peso, com peso normal, acima do
peso ou obeso*/

int main(int argc, char **argv)
{
	float peso, altura, imc;
	printf("Insira seu peso: ");
	scanf(" %f",&peso);
	printf("Insira sua altura: ");
	scanf(" %f",&altura);
	imc = peso / (altura * altura);
	
	if(imc >= 16 && imc < 17)
		printf("Muito abaixo do peso.\n");
	if(imc >= 17 && imc < 18.5)
		printf("Abaixo do peso.\n");
	if(imc >= 18.5 && imc < 25)
		printf("Peso normal.\n");
	if(imc >= 25 && imc < 30)
		printf("Acima do peso.\n");
	if(imc >= 30 && imc < 35)
		printf("Obesidade grau I.\n");
	if(imc >= 35 && imc <= 40)
		printf("Obesidade grau II.\n");
	if(imc > 40)
		printf("Obesidade grau III.\n");	
	return 0;
}

