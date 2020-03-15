#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// 3 strings em ordem alfabetica
// a com b, a com c, b com c.

int main(int argc, char **argv)
{
	char nome[3][100];// copia[100];
	
	for ( int i = 1; i <= 3; i ++){
	   printf ( "Informe o %dº nome: ",i );
	   scanf (" %[^\n]s", nome[i] );
	}
	
	// troca alfabetica

	for ( int i = 0; i < (3-2) ; i ++ ) {
		printf("OK");
		for( int j = i + 1; j < 3; j ++ ){
			if ( strcmp( nome[i], nome[j] ) > 0 )
				printf("Maior 0");
			if ( strcmp( nome[i], nome[j] ) < 0 )
				printf("Menor 0");
			if ( strcmp( nome[i], nome[j] ) == 0 )
				printf("Iguais");
				/*
				strcpy ( copia, nome[i] );
				printf ( "%s %s\n",copia,nome[i] );
	
				strcpy( nome[i], nome[j] );
				printf ( "%s %s\n",nome[i],nome[j] );
				
				strcpy( nome[j], copia) ;
				printf ( "%s %s\n",nome[j],copia );
				*/
			
		}
	}
			
	for ( int i = 1; i <= 3; i ++)
	   printf ( "%dº Nome: %s\n",i,nome[i] );
	
	return 0;
}

