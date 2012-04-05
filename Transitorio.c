#include "Transitorio.h"

int novo_transitorio(Trans *dest){
	unsigned int valor=OK;
	Trans novo;
	novo=(Trans) malloc(sizeof(struct sTrans));

	if(novo==NULL){valor=NO_INI;
					free(novo);}
	else{
		NovaFrota(&novo->cmz,1000);
		novoContCid(&novo->cidz,1000);
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


int realiza_movimento(Trans trs,char *origem,char *dest,char *contrib){
	int valor =OK;
	camiao transporte;
	int source,d[trs->cidz->ids];
	valor =getId(trs->cidz,origem,&source);
	getMindist(source,&trs->cidz->ligacoes,d);
	
	printf("%s-%d",origem,source);
	if(trs ==NULL ||origem ==NULL ||dest ==NULL || contrib==NULL){valor=NO_MEM;}
	else{
		if(getCamiao(trs->cmz,origem,transporte)==NO_HEAD){/*buscar*/}
		else{
			;
		}
		
		
	}
	
	return valor;
}

/*funcao utilizada para atribuir uma cidade aleatoria aos camioesx
int atribCity(Trans dest) {
	char citis[(int)dest->cidz->cidades->tsize][MAXS];
	char *buffer,*b;
	buffer=malloc(200*sizeof(char));
	int i=0,j,valor;
	Nodo_ll aux;
	b=buffer;
	FILE *f,*h;
	char nome[MAXS];

		f=fopen("cities.txt","r");
		h=fopen("trucks2.txt","w");/*
		
		/*abre o ficheiro apenas para ler*/
		/*
		if(f ==NULL || h==NULL) {printf("Entrou\n");
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
				strncpy(citis[i],nome,strlen((nome)));
				i++;
				buffer=b;
				memset(b,0,200*sizeof(char));
				
			}
			
			for (j=0;j<dest->cmz->frota->tsize;j++) {
				aux=dest->cmz->frota->tabela[j];
				while (aux !=NULL) {
					camiao a=((camiao)(aux->data));
					fprintf(h,"%s|%s|%s|\n",a->matricula,a->custokm,citis[rand()%i]);
					aux = aux->next;
				}
			}
			
			

		}	
}*/