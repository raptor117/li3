#include "aux.h"


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


void gera_matric(char *dst) {
	
	static const char text[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//printf("%d",rand()%27);
	dst[0]=text[rand()%26];
	dst[1]=text[rand()%26];
	dst[2]='-';
	dst[3]= (char)(((int)'0')+rand()%9);
	dst[4]=(char)(((int)'0')+rand()%9);
	dst[5]='-';
	dst[6]=(char)(((int)'0')+rand()%9);
	dst[7]=(char)(((int)'0')+rand()%9);	
	dst[8]='\0';
	
		
}

void gera_custo(char *dst) {
	
	static const char text[] ="1234567890";
	//printf("%d",rand()%27);
	dst[0]=text[rand()%9];
	dst[1]=text[rand()%9];
	dst[2]='\0';
	

	
		
}





void clear_string(char *dst,int n){
	int i;
	for(i=0;i<n;i++){
		dst[i]=' ';
	}
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



/*
void trim (char *s) {
	int i;
	while (isspace (*s)) s++;
	// skip left side white spaces
	for (i = strlen (s) - 1; (isspace (s[i])); i--) ;
	// skip right side white spaces
	s[i + 1] = '\0';
}*/

