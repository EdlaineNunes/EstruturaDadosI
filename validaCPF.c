#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

#define QUANT 11
//Você consegue cara!!


void printLinha(){ //printa linha
	int t = 10;
	char tipo = '-';
	for (int i = 0; i < t; i++)
	{
		printf("%c ",tipo);
	}
	printf("\n");
}

void setTransforCpf( char cpf[],int cpfInt[]){ //transforma os valores de CHAR para INT
	
	for (int i = 0; i < 11 ; i++){
		cpfInt[i] =  cpf[i] - '0';
	}
	

}

void setCpf(char cpf[]){ //Pega o cpf do usuario
	printf(" Digite 11 dígitos do seu CPF sem espaços:");
	do{
		scanf(" %[^\n]s",cpf);
	}while(strlen(cpf)!=11);// repete enquanto o usuario digite um valor maior ou menor que 11 digitos
}

int setDV1(int v[]){ // verifica o digito verificador 1
	int somatorio1=0;	   			
	for (int i = 0; i < 9; i++){ 
 		somatorio1 +=v[i]*(i+1);
	}
	somatorio1 =somatorio1%11;
	if (somatorio1 == 10){
		somatorio1 = 0;
	}
	return somatorio1; // retorna o valor do digito 1
}

int setDV2(int cpfInt[]){ //refica o digito verificador 2
		int somatorio2=0;	   			
		for (int i = 0; i < 10; i++){    
			somatorio2 +=cpfInt[i]*(i);
		}
		somatorio2 =somatorio2%11;
		if (somatorio2 == 10){
			somatorio2 = 0;		
		}
			return somatorio2;// retorna o valor do digito 2
}

void geraCpf(int cpfInt[]){ // gera o cpf 
	for (int i = 0; i < 10; i++)
		cpfInt[i] = rand()%10;
		
	cpfInt[9] = setDV1(cpfInt) ;
	cpfInt[10] = setDV2(cpfInt) ;
	
	for (int i = 0; i < 11; i++)// pode printar aqui ou nao 
		printf("%d",cpfInt[i] );
}

int getMenu(){ // menu
	int op;
	printf("_____MENU______\n");
	printf("1-Verificar\n2-Gerar\n3-\nOpção:");
	scanf(" %d",&op);
	setbuf (stdin, NULL);
	system("clear");
	return op;
	
}

int verifica(int cpfInt[]){ // verifica se o  cpf digitado é valido,  se retornar 1 == valido,  0 == nao válido 
	int dv1,dv2 = -1;
  	dv1=setDV1(cpfInt) ;
	if (dv1== cpfInt[9]){
		dv2 = setDV2(cpfInt);
	}else{
		return 0;
		}
	if( dv2 == cpfInt[10] ){
		return 1;
	}else {
		return 0;
	}  
}

int main(){
	srand(time(NULL));
	char cpf[11];
	int cpfInt[11];
	do{
		switch (getMenu())
		{
			case 1: setCpf(cpf);//chama a função verificar cpf e exibe msg 
					setTransforCpf(cpf,cpfInt);
					switch (verifica(cpfInt)) 
					{
						case 1: printLinha();
								printf(" CPF VÁLIDO!\n");	
								printLinha();					
							break;
						case 0: printLinha();
								printf(" CPF INVÁLIDO!\n");	
								printLinha(); 
							break;
						default:printf(" ERRO!");			
					}
					break;
			case 2: geraCpf(cpfInt); //gera o cpf aleatório
				    break;
			default:printf(" ERRO!");	
				
		}
	}while (1);
	return 0;
}
