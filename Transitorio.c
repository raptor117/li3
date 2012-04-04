#include "Transitorio.h"

int novo_transitorio(Trans *dest){
	unsigned int valor=OK;
	Trans novo;
	novo=(Trans) malloc(sizeof(struct sTrans));

	if(novo==NULL){valor=NO_INI;
					free(novo);}
	else{
		NovaFrota(&novo->cmz,10000);
		novoContCid(&novo->cidz,10000);
		novoContClie(&novo->cliez);
		*dest=novo;
		
	}
	return valor;

}

int loadData(Trans *dest){
	
	int valor=OK;
	valor=load_users(&(*dest)->cliez,"users.txt");
	valor=load_cidades(&(*dest)->cidz,"cities.txt");
	valor=load_custos(&(*dest)->cidz,"costs.txt");
	valor=load_camioes(&(*dest)->cmz,"trucks.txt");
	
	return valor;
}

int atribCity(Trans dest) {
	char citis[(int)dest->cidz->cidades->tsize][MAXS];
	char *buffer,*b;
	buffer=malloc(200*sizeof(char));
	int i=0,j,valor;
	b=buffer;
	FILE *f,*h;
	char nome[MAXS];

		f=fopen("cities.txt","r");
		h=fopen("trucks2.txt","r");
		
		/*abre o ficheiro apenas para ler*/
		if(f ==NULL) {printf("Entrou\n");
			valor=NON_ER;
		} else {
			while(fgets(buffer,200,f)!=NULL) {
				int t=strlen(buffer);
				buffer[t-2]='\0';
				buffer[t-1]='\0';
				Cidade cid;
				char *token;
				token=strsep(&buffer,"|");
				token=strsep(&buffer,"|");
				memcpy(nome,token,strlen(token)+1);
			//	printf("%s\n",nome);
				strncpy(citis[i],nome,strlen((nome)));
				i++;
				
				
			}
			buffer=b;
			memset(b,0,200*sizeof(char));
		}
		
		for(j=0;j<i;j++){
			printf("%s\n",citis[j]);
		}
		
		
}