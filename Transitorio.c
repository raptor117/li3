#include "Transitorio.h"


unsigned int novo_transitorio(Trans *dest){
	unsigned int valor=OK;
	Trans novo;
	novo=(Trans) malloc(sizeof(struct sTrans));

	if(novo==NULL){valor=NO_INI;
					free(novo);}
	else{
		*dest=novo;
		
	}
	return valor;

}