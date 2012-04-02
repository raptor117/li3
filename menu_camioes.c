#include "menu_camioes.h"


void scan_matricula(char *matricula){
	    fflushstdin();
		printf("Introduza a matricula do camiao: ");
		fgets(matricula,9,stdin);
	   // fixString(matricula,MAXS);
}

void scan_localidade(char *localidade){
	   fflushstdin();
		printf("Introduza a localidade original do camiao: ");
		fgets(localidade,MAXS,stdin);
	    fixString(localidade,MAXS);
		
}

void scan_custoKM(int *cKM){
	printf("Introduza o custo por KM do camiao: ");
	scanf("%d",cKM);
	
	
}