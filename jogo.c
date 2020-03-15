#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>



//Definições

#define PAL 2

FILE *teste;
int criou =0;

struct palsec{
char magica[30];
}nova;



//FILE *doc;

//int criou = 0, leu = 0;
//char palavras[PAL][25];

//Prototipo da Função
void menuPrincipal();
void lepalavra();
void cadPalavra();
void jogo();
void ajuda();

void lepalavra(){

int i,tamanho;

if((teste = fopen("forca.txt","r")) == NULL){

printf("Erro ao Abrir o Arquivo \"FORCA.txt\".");
exit(0);
};

for(i=0;i<PAL;i++){

fflush(stdin);
gets(nova.magica);

if(strcmp(nova.magica,"") == 0)
break;

fwrite(&nova,sizeof(struct palsec),1,teste);

}
fclose(teste);

criou = 1;

/*
printf("Digite a Palavra secreta\n");
fgets(nova.magica,30,stdin);
getchar();

*/
}


void ajuda(){

printf("Ajuda\n");
printf("+--------------------------------------------------+\n");
printf("| 1 Para Começar o Jogo Antes Cadastre Uma Palavra |\n");
printf("+--------------------------------------------------+\n");

// A Implementar

}

void cadPalavra(){
fflush(stdin);
printf("Digite uma palavra\n");
fgets(nova.magica,30,stdin);

if((teste=fopen("teste.txt","w"))==NULL){
printf("Impossivel Abrir o Arquivo:\n ");
system("pause");
return 0;
}
fwrite(&nova,sizeof(struct palsec),1,teste);
printf("Gravação Efetuada com Sucesso\n");








}



void jogo(){
system("cls");

     int i, gera_rand, erros = 8, tamanho, termina = 0, z = 0;
int joga = 1, errou;
     char selecionada[25], verifica[1] = {""}, correta[25], digitadas[25] = {""};
     char letras[57] = {" a b c d e f g h i j k l m n o p q r s t u v w x y z 0"};

     srand(time(NULL));

     typedef struct Membros{     // Exemplo de Uso de estrutura para formaçao do boneco

             char cabeca[1];
             char tronco[1];
             char b_p[1];
             char p_b[1];
     }P;


     for(i=0;i<PAL;i++){

              if(strcmp(nova.magica,"") == 0 && i == 0){

                                        printf("Erro voce nao cadastrou nenhuma palavra!\n");
                                        printf("E seu teste.txt nao consta nenhuma palavra!\n");
                                        joga = 0;
                                        break;

              }

              else if(strcmp(nova.magica,"") == 0){

                                        gera_rand = i;
                                        break;
              }

     }

     if(joga){ // Onde o jogo começa meu parceroooo!!!

             gera_rand = rand() % gera_rand;

             strcpy(selecionada,nova.magica[gera_rand]);

             for(i=0;i<25;i++)
                            selecionada[ i ] = tolower(selecionada[ i ]);

           //  printf("A palavra seleciona e %s\n",selecionada);

             tamanho = strlen(selecionada);

             P ERROS;

             ERROS.cabeca[1] = 'O';
             ERROS.tronco[1] = '|';
             ERROS.b_p[1] = '/';
             ERROS.p_b[1] = '\\';

             for(i = 0;i < tamanho;i++){
                         if(selecionada[ i ] == ' ')
                                           correta[ i ] = ' ';
                         else
                             correta[ i ] = '_';
             }
             for(i = 0;i < tamanho;i++)
                         if(selecionada[ i ] == ' '){
                                                  tamanho++;
                                                  termina++;
                         }
             while(erros){

                 system("cls");

                 printf("\n");
                 printf("+--------------------+\n");
                 printf("|                    |\n");
                 printf("|                    %c\n",erros < 8 ? ERROS.cabeca[1] : ' ');
                 printf("|                   %c%c%c\n",erros < 6 ? ERROS.b_p[1] : ' ',erros < 7 ? ERROS.tronco[1] : ' ',erros < 5 ? ERROS.p_b[1] : ' ');
                 printf("|                    %c\n",erros < 4 ? ERROS.tronco[1] : ' ');
                 printf("|                   %c %c\n",erros < 3 ? ERROS.b_p[1] : ' ',erros < 2 ? ERROS.p_b[1] : ' ');
                 printf("|\n");
                 printf("|\n");
                 printf("| ");

                 for(i = 0;i < tamanho;i++){
                       if(selecionada[ i ] == verifica[0]){
                               correta[ i ] = verifica[0];
                               termina++;          //Faz o controle ' se termina for igual a tamanho então a palavras esta correta e acaba o jogo...
                       }
                 }

                 for(i = 0;i < tamanho;i++){                                  // Imprime a palavra na tela
                       printf("%c ",correta[ i ]);
                 }

                 printf("\n\n");

                 for(i = 1;letras[ i ] != '0';i++){                             // Coloca       -      nas letras digitadas
                                     if(letras[ i ] == verifica[0])
                                                                         letras[ i ] = '-';
                                     printf("%c",letras[ i ]);

                 }

                 if(termina == tamanho){

                            printf("voce Ganhou!!!\n");
                 break;
                 }

                 if(erros == 1){

                            printf("A palavra selecionada era %s\n",selecionada);
                            printf("voce perdeu!\n");
                            printf("ALOCOOOOOOO\n\n");
                 break;
                 }

                 printf("\n\nDigite uma Letra: ");

                 verifica[0] = getch();

                 for(i=0;digitadas[ i ] != '{FONTE}';i++){           // Verifica se a letra ja foi digitada
                   if(digitadas[ i ] == verifica[0]){

                    printf("\nEssa letra ja foi digitada meu parcero!\n");
                    printf("Por Gentileza digite outra e tente nao cometer o mesmo erro 2 vezes.\n");
                     verifica[0] = getch();

                 if(verifica[0] == digitadas[ i ]){  // Se caso o cara volte a digitar a mesma letra que a anterior ele diminui 1 em i e manda continuar o FOR
                     verifica[0] = getch();
                 i--;
                continue;
                 }
                break;
                             }
                 }

                 digitadas[z] = verifica[0];
                 z++;
                 errou = 1;
                 for(i = 0;i < tamanho;i++){                            // Verifica se o cara digito uma letra que nao tem na palavra
                       if(selecionada[ i ] == verifica[0]){               // Se nao tiver letra na palavra incrementa um erro
                               correta[ i ] = verifica[0];
                               errou = 0;
                       }
                 }

                 if(errou)
                           erros--;
         }
     }

getch();
}



void menuPrincipal(){
int x,aceita;

do{
system("cls");

printf("Escolha uma das opções para execucao do programa.\n");
printf("+------------------------------------------------------------------------------+");
printf("| Bem Vindo ao Jogo Da Forca |\n");
printf("| |");
printf("| 1 Cadastrar Palavra Secreta |\n");
printf("| 2 >>>>>>>>>>>>>Jogar.<<<<<<<<<<<<<<<< |\n");
printf("| 3 Help |\n");
printf("| 4 Mostrar Creditos e Encerrar o Programa. |\n");
printf("+------------------------------------------------------------------------------+\n");
scanf("%d",&x);
system("cls");
 switch(x){
       case 1:{
       cadPalavra();
       }break;
       case 2:{
       jogo();
       }break;
       case 3:{
       ajuda();
       }break;

}
}

while (x != 4  );
printf(" +-------------------------------------------------+\n");
printf(" | Jogo desenvolvido Por |\n");
printf(" | |\n");
printf(" | |\n ");
printf("| |\n");
printf(" |Versao Beta 1.1 |\n");
printf(" +-------------------------------------------------|\n");



}



int main(){



menuPrincipal();

}

