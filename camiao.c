#include "camiao.h"

int imprimeCam (void *a) {
	int valor=OK;
	camiao aa;
	aa= (camiao) a;
	if(aa==NULL) {
		valor=NO_INI;
	} else {
		printf("Camiao nº%8d\nMatricula:%8s |Custo/Km:%8s |Local:%8s\n\n",aa->ide,
		               aa->matricula,aa->custokm,aa->local);
	}
	return valor;
}


int compareCam(void *a,void *b) {
	int valor =OK;
	camiao aa,bb;
	aa= (camiao) a;
	bb= (camiao) b;
	if(aa ==NULL || bb ==NULL) {
		valor =NO_INI;
	} else {
		if(strncmp(aa->matricula,bb->matricula,max(strlen
				(aa->matricula),strlen(bb->matricula)))==0){
					valor=IGUAL;
			
		}
	
	}
	return valor;
}


int freeCamiao(void *a) {
	int valor=1;
	camiao aa;
	aa= (camiao) a;
	free(aa);
	return valor;
}

char *keyCam(void *a) {
	int valor=OK;
	camiao aa;
	aa= (camiao) a;
	if(aa==NULL) {
		valor=NO_INI;
	} else {
	
	return aa->matricula;}
}

int NovaFrota(camioes *frota,double ncam) {
	int valor =OK;
	camioes nova= (camioes) malloc(sizeof(struct contCamioes));
	/*aloca o espaco para a estutura*/
	if(nova ==NULL) {
		valor == NO_MEM;
	} else {
		valor=NovaHash(ncam,&nova->frota,&compareCam,&freeCamiao,
		                       &imprimeCam,&keyCam);
		/* cria a tabela*/
		if(valor==OK) {
			nova->ids=0;
			*frota=nova;
		} else {
			free(nova);
		}
	}
	return valor;
}

int NovoCamiao(camiao *dest,char *matricula,char *custo,char *local) {
	int valor=OK;
	camiao novo=(camiao) malloc(sizeof(struct scamiao));
	if(novo ==NULL) {
		valor =NO_MEM;
	} else {
		
		novo->matricula=(char*) malloc(MAXS*sizeof(char));
		novo->local=(char*) malloc(MAXS*sizeof(char));
		novo->custokm=(char*) malloc(MAXS*sizeof(char));
	
		if(novo->matricula != NULL && novo->local != NULL) {
			strncpy(novo->matricula,matricula,strlen(matricula));
			strncpy(novo->local,local,strlen(local));
			strncpy(novo->custokm,custo,strlen(custo));
			
			*dest=novo;
	
		} else {
			free(novo);
			valor=NO_MEM;
		}
	}
	return valor;
}


int InsereCamiao(camiao cam,camioes *frta) {
	int valor=OK;
	if(cam==NULL || *frta==NULL) {
		valor=NO_INI;
	} else {
		cam->ide=(*frta)->ids;
		Insere_Hash(&(*frta)->frota,cam);
		(*frta)->ids++;
	}
	return valor;
}


int mudarLocalidade(camioes frota,char *matricula,char *local) {
	int valor=OK;
	if(frota ==NULL || frota->frota ==NULL || matricula ==NULL || local ==NULL) {
		valor=NO_INI;
	} else {
		void **elems;
		int n;
		camiao aux2;
		NovoCamiao(&aux2,matricula,"","");
		
		getElems(frota->frota,aux2,&elems,&n,&compareCam);
		if(n==1){
	    strncpy(((camiao)elems[0])->local,local,
		          	max(strlen(aux2->local),strlen(local)));
		}
	}
	return valor;
}


int removeCamiao(camioes frota,char *matricula){
	int valor =OK;
	if(frota ==NULL || matricula ==NULL || frota->frota ==NULL){
		valor =NO_INI;
	}else{
		camiao novo;
		valor=NovoCamiao(&novo,matricula,"","");
		if(valor==OK){
			remove_hash(&frota->frota,novo);}
		free (novo);
	}
	
	
}
int  searchCamiao (camioes frota,char *matricula,void ***elems,int *n) {
	int valor=OK;
	if(frota==NULL || matricula == NULL || frota->frota ==NULL) {
		valor =NO_INI;
	} else {
	
		camiao aux2;
		NovoCamiao(&aux2,matricula,"","");
		valor=getElems(frota->frota,aux2,elems,n,&compareCam);
		free(aux2);
	}
	return valor;
}


int main(){
	
	camiao novo;
	camioes frota;
	char matricula[10];
	char custo[2];
	int i;
	
	
	NovaFrota(&frota,10000);
	
	for(i=0;i<20000;i++){
		gera_matric(matricula);
		gera_custo(custo);
		NovoCamiao(&novo,matricula,custo,"");
		InsereCamiao(novo,&frota);
		
		
	}
	
	imprimetab(frota->frota);
	
}