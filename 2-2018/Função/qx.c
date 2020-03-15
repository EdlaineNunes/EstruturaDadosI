#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef struct {
	int gb;
	int clock;
	char fab[100];
	float valor;	
}Ram;

typedef struct {
	int gb;
	char tipo[50];
	char fab[100];
	float valor;
}Hd;

typedef struct {
	int clock;
	char fab[100];
	float valor;
	int socket;
}Processador;

typedef struct {
	int socket;
	char fab[100];
	int mclock;
	float valor;
}PlacaMae;

typedef struct {
	Ram cadRam;
	Hd cadHd;
	Processador cadProc;
	PlacaMae cadPMae;
	char nome[100];	
}MontaPC;

void Linha(){
	printf("\n");
	for (int i=0; i<50; i++)
		printf("=");
	printf("\n\n");
}

Ram setRam(){
	Ram novo;
	Linha();
	printf("\t\tCADASTRO RAM:\n\n");
	printf("Insira gb:\t");
	scanf(" %d",&novo.gb);
	printf("Insira clock:\t");
	scanf(" %d",&novo.clock);
	printf("Insira fabricante:\t");
	scanf(" %[^\n]s",novo.fab);
	printf("Insira valor:\t");
	scanf(" %f",&novo.valor);
	Linha();	
	return novo;
}

Hd setHd(){
	Hd novo;
	Linha();
	printf("\t\tCADASTRO HD :\n\n");
	printf("Insira gb:\t");
	scanf(" %d",&novo.gb);
	printf("Insira tipo:\t");
	scanf(" %[^\n]s",novo.tipo);
	printf("Insira fabricante:\t");
	scanf(" %[^\n]s",novo.fab);
	printf("Insira valor:\t");
	scanf(" %f",&novo.valor);
	Linha();
	return novo;	
}

Processador setProc(){
	Processador novo;
	Linha();
	printf("\t\tCADASTRO PROCESSADOR:\n\n");
	printf("Insira clock:\t");
	scanf(" %d",&novo.clock);
	printf("Insira fabricante:\t");
	scanf(" %[^\n]s",novo.fab);
	printf("Insira valor:\t");
	scanf(" %f",&novo.valor);
	printf("Insira socket:\t");
	scanf(" %d",&novo.socket);
	Linha();	
	return novo;
}

PlacaMae setPlaca(){
	PlacaMae novo;
	Linha();
	printf("\t\tCADASTRO PLACA MÃE:\n\n");
	printf("Insira socket:\t");
	scanf(" %d",&novo.socket);
	printf("Insira fabricante:\t");
	scanf(" %[^\n]s",novo.fab);
	printf("Insira a capacidade do clock de memória:\t");
	scanf(" %d",&novo.mclock);
	printf("Insira o valor:\t");
	scanf(" %f",&novo.valor);
	Linha();
	return novo;	
}

void getRam(Ram v[], int q){
	Linha();
	if(q>0){
		printf("RAM's CADASTRADAS:\n\n");
		for (int i=0; i<q; i++)
			printf("%dº - GB: %d --> Clock: %d --> Fab: %s --> Valor: R$%.2f\n",i+1,v[i].gb,v[i].clock,v[i].fab,v[i].valor);
		Linha();	
	}
	else
		printf("NENHUMA RAM CADASTRADA!");
}

void getHd(Hd v[], int q){
	Linha();
	if(q>0){
		printf("HD's CADASTRADOS:\n\n");
		for (int i=0; i<q; i++)
			printf("%dº - Gb: %d --> Tipo: %s --> Fab: %s --> Valor: R$%.2f\n",i+1,v[i].gb,v[i].tipo,v[i].fab,v[i].valor);
		Linha();
	}
	else
		printf("NENHUM HD CADASTRADO!");
}

void getProc(Processador v[], int q){
	Linha();
	if(q>0){
		printf("PROCESSADORES CADASTRADOS:\n\n");
		for (int i=0; i<q; i++)
			printf("%dº - Clock: %d --> Fab: %s --> Valor: R$%.2f --> Socket: %d\n",i+1, v[i].clock,v[i].fab,v[i].valor,v[i].socket);
		Linha();	
	}
	else
		printf("NENHUM PROCESSADOR CADASTRADO!");
}

void getPlaca(PlacaMae v[], int q){
	Linha();
	if(q>0){
		printf("PLACAS MÃE CADASTRADAS:\n\n");
		for (int i=0; i<q; i++)
			printf("%dº - Socket: %d --> Fab: %s -->Memória clock: %d --> Valor: %.2f\n",i+1, v[i].socket,v[i].fab,v[i].mclock,v[i].valor);
		Linha();
	}
	else
		printf("NENHUMA PLACA MÃE CADASTRADA!");
}

int verificaCompatPlacaProcessador(PlacaMae pm[], int contpm, Processador proc[], int contproc){
	for(int i=0; i<contpm; i++)
		for (int j=0; j<contproc; j++)
			if(pm[i].socket == proc[j].socket){
				printf("\n processador existe!\n");
				return 1;
			}
	printf("\nO processador NÃO existe!\n");
	return 0;	
}

int verificaCompatPlacaMemoria(PlacaMae pm[], int contpm, Hd hd[], int conthd){
	for(int i=0; i<contpm; i++)
		for (int j=0; j<conthd; j++)
			if(strcmp(pm[i].fab,hd[j].fab)==0){
				printf("\n hd existe!\n");
				return 1;
			}
	printf("\nO hd NÃO existe!\n");
	return 0;	
}

int verificaCompatPlacaRam(PlacaMae pm[], int contpm, Ram ram[], int contram){
	for(int i=0; i<contpm; i++)
		for (int j=0; j<contram; j++){
			if(pm[i].mclock == ram[j].clock){
				printf("\n ram existe!\n");
				return 1;
			}				
		}
	printf("\nA ram NÃO existe\n");
	return 0;
}

MontaPC setMontar(PlacaMae pm[], int contpm, Processador proc[], int contproc, Hd hd[], int conthd, Ram ram[], int contram){
	MontaPC novo;
	Linha();
	if((contpm > 0) && (contproc > 0) && (conthd > 0) && (contram > 0)){
		printf("\t\tMONTAR PC:\n\n");
		printf("\tOBS: EM TODAS AS OPÇÕES digite o numero da tupla a ser escolhida!!!\n\n");
		printf("Escolha uma das PLACAS MÃE listadas:\n");
		int placa;
		do{
			getPlaca(pm,contpm);
			printf("OPC:\t");
			scanf(" %d",&placa);
			int v1 = verificaCompatPlacaProcessador(pm, contpm, proc, contproc);
			int v2 = verificaCompatPlacaMemoria(pm, contpm, hd, conthd);
			int v3 = verificaCompatPlacaRam(pm, contpm, ram, contram);
			if((!v1)||(!v2)||(!v3)){
				printf("FALTAM PEÇAS COMPATIVEIS");
				return novo;
			}					
			if ((placa >= 1) && (placa <= contpm)){
				printf("\n\t\tPlaca Mãe escolhida com sucesso!!\n\n");
				novo.cadPMae = pm[placa-1];
				printf("Valor: %f",novo.cadPMae.valor);
				printf("Escolha um dos PROCESSADORES (socket) listados:\n");
				int proces;
				do{
					getProc(proc,contproc);
					printf("OPC:\t");
					scanf(" %d",&proces);
					if((proces >= 1) && (proces <= contproc)){
						if(pm[(placa-1)].socket == proc[(proces-1)].socket){
							printf("\n\t\tProcessador escolhido com sucesso!!\n\n");
							novo.cadProc = proc[proces-1];
							printf("Valor: %f",novo.cadProc.valor);

							printf("Escolha um dos HD (fabricante) listados:\n");
							int ehd;
							do{
								getHd(hd,conthd);
								printf("OPC:\t");
								scanf(" %d",&ehd);
								if ((ehd >= 1) && (ehd <=conthd )){
									if(strcmp(pm[(placa-1)].fab,hd[(ehd-1)].fab)==0){
										printf("\n\t\tHD escolhido com sucesso!!\n\n");
										novo.cadHd=hd[ehd-1];
										printf("Escolha uma das RAM's (clock) listados:\n");
										int eram;
										do{
											getRam(ram,contram);
											printf("OPC:\t");
											scanf(" %d",&eram);
											if ((eram >= 1) && (eram <= contram )){
												if(pm[(placa-1)].mclock == ram[(eram-1)].clock){
													printf("\n\t\tRAM escolhida com sucesso!!\n\n");
													novo.cadRam = ram[eram-1];
													printf("Insira o nome do Computador:");
													scanf(" %[^\n]s",novo.nome);
													printf("\n\t\tMONTAGEM FINALIZADA COM SUCESSO!");
													Linha();
													return novo;
												}
												else
													printf("\n\t\tRAM INCOMPATÍVEL!!\n\n\t\tTENTE NOVAMENTE\n");
											}										
										}while(1);
										break;
									}
									else 
										printf("\n\t\tHD INCOMPATÍVEL!!\n\n\t\tTENTE NOVAMENTE\n");
								}							
							}while(1);							
							break;
						}
						else
							printf("\n\t\tProcessador INCOMPATÍVEL!!\n\n\t\tTENTE NOVAMENTE\n");
					}else
						printf("\n\tOPÇÃO INVÁLIDA!\n\tTENTE NOVAMENTE\n\n");					
				}while(1);
				break;
			}
			else 
				printf("\n\tOPÇÃO INVÁLIDA!\n\tTENTE NOVAMENTE\n\n");		
		}while(1);
	}
	else
		printf("\t\tMONTAGEM IMPOSSÍVEL...\n\tInexistência de cadastros suficientes para a montagem.");
	Linha();
	return novo;
}

void getMontagem(MontaPC v[], int q){
	Linha();
	if(q>0){
		printf("COMPUTADORES MONTADOS:\n\n");
		for (int i=0; i<q; i++)
			printf("%dº - Nome: %s --> Placa Mãe: %d --> Processador: %d --> HD: %s --> RAM: %d\n",i+1, v[i].nome,v[i].cadPMae.socket,v[i].cadProc.socket,v[i].cadHd.fab,v[i].cadRam.clock);
		Linha();
	}
	else
		printf("NENHUM COMPUTADOR MONTADO!");	
}

void getCalculo(MontaPC v[], int q){
	Linha();
	float valor;
	if(q>0){
		printf("PREÇO DOS COMPUTADORES MONTADOS:\n\n");
		for (int i=0; i<q; i++){
			valor=0;
			valor= v[i].cadProc.valor + v[i].cadHd.valor + v[i].cadRam.valor + v[i].cadPMae.valor;
			printf("%dº - Nome: %s --> R$ %.2f\n",i+1, v[i].nome,valor);
		}
		Linha();
	}
	else
		printf("NENHUM COMPUTADOR MONTADO!");	

}

int MenuOpc(){
	Linha();
	printf("\t\tMENU PRINCIPAL\n\n");
	printf("\t1 - Cad RAM:\n");
	printf("\t2 - Listar RAM:\n");
	printf("\t3 - Cad HD:\n");
	printf("\t4 - Listar HD:\n");
	printf("\t5 - Cad PROCESSADOR:\n");
	printf("\t6 - Listar PROCESSADOR:\n");
	printf("\t7 - Cad PLACA MÃE:\n");
	printf("\t8 - Listar PLACA MÃE:\n");
	printf("\t9 - Montar PC:\n");
	printf("\t10 - Mostrar PC's montados:\n");
	printf("\t11 - Calcular preço.\n");
	
	printf("\t0 - EXIT\n");
	int opc;
	scanf(" %d",&opc);
	return opc;
}

int main(int argc, char **argv)
{
	Ram cRam[100];
	int contR=0;
	Hd cHd[100];
	int contH=0;
	Processador cProc[100];
	int contP=0;
	PlacaMae cPMae[100];
	int contPM=0;
	MontaPC cMonta[100];
	int contMonta=0;	
	
	do{
		switch(MenuOpc()){
			case 0: Linha();
					printf("\t\tFINALIZADO COM SUCESSO!!\n");
					Linha();
					return 0;
			case 1: cRam[contR] = setRam();
					contR++;
					break;
			case 2: getRam(cRam, contR);
					break;
			case 3: cHd[contH] = setHd();
					contH++;
					break;
			case 4: getHd(cHd,contH);
					break;
			case 5: cProc[contP] = setProc();
					contP++;
					break;
			case 6: getProc(cProc,contP);
					break;
			case 7: cPMae[contPM] = setPlaca();
					contPM++;
					break;
			case 8: getPlaca(cPMae,contPM);
					break;
			case 9: cMonta[contMonta]= setMontar(cPMae,contPM,cProc,contP,cHd, contH,cRam, contR);
					contMonta++;
					break;
			case 10:getMontagem(cMonta,contMonta);
					break;
			case 11:getCalculo(cMonta, contMonta);
					break;			
			default:Linha(); 
					printf("\tOPÇÃO INVÁLIDA!\n\tTENTE NOVAMENTE!\n");
		}
	}while(1);
	
	return 0;
}

