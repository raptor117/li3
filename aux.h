#pragma once
#define MAXS 100
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
Modulo auxiliar as bibliotecas, com funcoes que todas precisam.
A maioria destas funcoes trabalham com strings 
*/

/*gera uma string aleatoria, é utilizada para testar alguns modulos*/
char *rand_str(char *dst, int size);

/*devolve o maior de dois inteiros*/
int max(int a,int b);


/*devolve o tamanho de uma string*/
int sizeString(char *strig);

/*coloca o /0 no final de uma string recebida por fgets*/
int fixString(char * strig,int    size);

/*remove espacos em branco de uma string*/
void trim (char *s);
