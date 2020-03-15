#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

struct No{
    int numero;
    struct No *esquerda;
    struct No *direita;
};
typedef struct No No;

//criando a arvore
void criarArvore(No **pRaiz){
    *pRaiz = NULL;
}

//inserindo nó
void inserir(No **pRaiz, int numero){
    if(*pRaiz == NULL){
        *pRaiz = (No *) malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero;
    }else{
        if(numero < (*pRaiz)->numero)
            inserir(&(*pRaiz)->esquerda, numero);
        if(numero > (*pRaiz)->numero)
            inserir(&(*pRaiz)->direita, numero);
    }
}

//remoção
No *MaiorDireita(No **no){
    if((*no)->direita != NULL) 
       return MaiorDireita(&(*no)->direita);
    else{
       No *aux = *no;
       if((*no)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *no = (*no)->esquerda;
       else
          *no = NULL;
       return aux;
       }
}

No *MenorEsquerda(No **no){
    if((*no)->esquerda != NULL) 
       return MenorEsquerda(&(*no)->esquerda);
    else{
       No *aux = *no; 
       if((*no)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *no = (*no)->direita;
       else
          *no = NULL;
       return aux;
       }
}

void remover(No **pRaiz, int numero){
    if(*pRaiz == NULL){   // esta verificacao serve para caso o numero nao exista na arvore.
       printf("Numero nao existe na arvore!");
       getchar();
       return;
    }
    if(numero < (*pRaiz)->numero)
       remover(&(*pRaiz)->esquerda, numero);
    else 
       if(numero > (*pRaiz)->numero)
          remover(&(*pRaiz)->direita, numero);
       else{    // se nao eh menor nem maior, logo, eh o numero que estou procurando! :)
          No *pAux = *pRaiz;     // quem programar no Embarcadero vai ter que declarar o pAux no inicio do void! :[
          if (((*pRaiz)->esquerda == NULL) && ((*pRaiz)->direita == NULL)){         // se nao houver filhos...
                free(pAux);
                (*pRaiz) = NULL; 
               }
          else{     // so tem o filho da direita
             if ((*pRaiz)->esquerda == NULL){
                (*pRaiz) = (*pRaiz)->direita;
                pAux->direita = NULL;
                free(pAux); 
                pAux = NULL;
                }
             else{            //so tem filho da esquerda
                if ((*pRaiz)->direita == NULL){
                    (*pRaiz) = (*pRaiz)->esquerda;
                    pAux->esquerda = NULL;
                    free(pAux); 
                    pAux = NULL;
                    }
                else{       //Escolhi fazer o maior filho direito da subarvore esquerda.
                   pAux = MaiorDireita(&(*pRaiz)->esquerda); //se vc quiser usar o Menor da esquerda, so o que mudaria seria isso:
                   pAux->esquerda = (*pRaiz)->esquerda;          //        pAux = MenorEsquerda(&(*pRaiz)->direita);
                   pAux->direita = (*pRaiz)->direita;
                   (*pRaiz)->esquerda = (*pRaiz)->direita = NULL;
                   free((*pRaiz));  
                   *pRaiz = pAux;  
                   pAux = NULL;   
                   }
                }
          }
      }
  }
  
//imp ordem
void exibirEmOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirEmOrdem(pRaiz->esquerda);
        printf("\n%i", pRaiz->numero);
        exibirEmOrdem(pRaiz->direita);
    }
}

//imp pré
void exibirPreOrdem(No *pRaiz){
    if(pRaiz != NULL){
        printf("\n%i", pRaiz->numero);
        exibirPreOrdem(pRaiz->esquerda);
        exibirPreOrdem(pRaiz->direita);
    }
}

//imp pós
void exibirPosOrdem(No *pRaiz){
    if(pRaiz != NULL){
        exibirPosOrdem(pRaiz->esquerda);
        exibirPosOrdem(pRaiz->direita);
        printf("\n%i", pRaiz->numero);
    }
}

int Menu(){
	int opt;
	printf("1-Inseir,\n2-");
	scanf(" %d",&opt);
	return opt;
}

int main(int argc, char **argv)
{
	int i;
	printf("Digite o numero de nós: ");
	scanf(" %d",&i);

	switch (Menu()){
		case 1: inserir();
				break;
		case 2:
				break;
		case 3: 
				break;
		case 4: 
				break;
		default: return 0;
		
		
		}
*/
	return 0;
}
