#include "menu_camioes.h"


void scan_matricula(char *matricula){
	   fflushstdin();
		printf("Introduza a matricula do camiao: ");
		fgets(matricula,9,stdin);
		fixString(matricula,strlen(matricula));
		
}

void scan_localidade(char *localidade){
	   	fflushstdin();
		printf("Introduza a localidade original do camiao: ");
		fgets(localidade,MAXS,stdin);
		fixString(localidade,strlen(localidade));
		
}

void scan_custoKM(char *km){
 
	fflushstdin();


	printf("Introduza o custo por KM do camiao: ");
	fgets(km,MAXS,stdin);
	
	
}