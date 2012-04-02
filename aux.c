#include "aux.h"


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fflushstdin( void )
{
    int c;
    while( (c = fgetc( stdin )) != EOF && c != '\n' );
}

char * rand_str(char * dst,int    size) {
	
	static const char text[] = "abcdefghijklmnopqrstuvwxyz" "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i,len;
	len= rand();
	len=len%(size-1);
	for (i = 0; i < len; ++i) {
		dst[i] = text[rand() % (sizeof text - 1)];
	}
	dst[i] = '\0';
	return dst;
}

int max(int a,
                 int b) {
	int valor;
	if (a < b) {
		valor = b;
	} else {
		valor = a;
	}
	return valor;
}

int sizeString(char * strig) {
	int tamanho = 0;
	while ((strig[tamanho] != '\0') && (tamanho < MAXS)) {
		tamanho++;
	}
	return tamanho;
}

int fixString(char * strig,int    size) {
	int i,
	        fim = 0;
	for (i=0; (i < size) && (fim == 0); i++) {
		if (strig[i] == '\n') {
			strig[i] = '\0';
			fim      = 1;
		}
	}
	return 1;
}
void trim (char *s) {
	int i;
	while (isspace (*s)) s++;
	// skip left side white spaces
	for (i = strlen (s) - 1; (isspace (s[i])); i--) ;
	// skip right side white spaces
	s[i + 1] = '\0';
}

