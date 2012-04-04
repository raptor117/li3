#include "cidades.h"

int getCustotrans(void *a){
	int valor=OK;
	if(a ==NULL ){valor=NO_INI;}
	else{
    	Custos aa;
    	aa= (Custos) a;
		/*sendo aa o nodo ja existente apenas altera o custo desse pelo que existe em b*/
		valor=aa->custo;
	}
	return valor;
	
}

int switx(void *a,void *b){
	int valor=OK;
	if(a ==NULL || b==NULL){valor=NO_INI;}
	else{
    	Custos aa,bb;
    	aa= (Custos) a;
    	bb= (Custos) b;
	
		/*sendo aa o nodo ja existente apenas altera o custo desse pelo que existe em b*/
		aa->custo=bb->custo;
	}
	return valor;
}




int compareCid(void *a,void *b) {
    int valor =OK;
    Cidade aa,bb;
    aa= (Cidade) a;
    bb= (Cidade) b;

    if((strncmp(aa->nome,bb->nome,max(sizeString(aa->nome),sizeString(bb->nome)))==0))
 	{
        valor=IGUAL;
    }
    return valor;
}

/*liberta as cidades da hash*/
int freeCid(void *a) {
	int valor=OK;
	if(a==NULL) {
		valor = NO_INI;
	} else {
		Cidade aa;
		aa= (Cidade) a;
		//destroy_ll((aa->camioes));
		free(aa);
	}
    return valor;
}


int  freeLig(void *a){
	Custos aa;
	int valor =OK;
	if(a==NULL) {
		valor =NO_INI;
	} else {  /*falta libertar a lista,prox*/
		aa=(Custos) a;
		free(aa);
	}
	return valor;
}
int imprimeTransp(void *a){
	int valor =OK;
	Custos aa; 
	aa=(Custos) a;
	
	if(a==NULL){
		valor=NO_INI;
	}else{
		//printf("|Nome do transp:%s |Custo: %d|\n\n",aa->tipo_transp,aa->custo);
		printf("|Km:%d||Custo:%d|\n\n",aa->km,aa->custo);
		
	}
	
	return valor;
}
int imprimeCid (void *a) {
    int valor=OK;
    Cidade aa;
    aa= (Cidade) a;
    if(aa==NULL) {
        valor=NO_INI;
    } else {
        printf("|Cidade nº%d|\n|Nome:%s|\n\n",aa->ide,aa->nome);
    }
    return valor;
}

char * keyCidade(void *elem) {
    Cidade aa;
    aa = (Cidade) elem;
    return (aa)->nome;
}


 int novoContCid(ControlCid *cntcid,int nCidades) {
    int valor;
    ControlCid novo=(ControlCid) malloc(sizeof(struct cidadeControl));
    if(novo==NULL) {
        valor =NO_INI;
    } else {
       
 		valor=NovaHash(nCidades,&novo->cidades,&compareCid,&freeCid,&imprimeCid,&keyCidade);
        valor=inicializa(nCidades,&novo->ligacoes,&freeLig,&imprimeTransp, sizeof(struct sCustos),&switx,&getCustotrans);
        
		if(novo->cidades==NULL || novo->ligacoes==NULL) {
            free(novo->cidades);
            free(novo->ligacoes);
            free(novo);
            valor=NO_MEM;
        } else {
            novo->ids=0;
            *cntcid=novo;
        }
    }
    return valor;
}


int novaCidade(Cidade *dest, char *nome) {
    int valor =OK;
    Cidade nova =(Cidade) malloc(sizeof(struct scidade));
    if(nova ==NULL) {
        valor =NO_MEM;
    } else {
        nova->nome=(char*) malloc(sizeString(nome)*sizeof(char));
        if(nova->nome ==NULL) {
            free(nova);
            valor=NO_MEM;
        } else {
			nova->ide=0;
            strncpy(nova->nome,nome,sizeString(nome));
	//	valor=	init_ll(&nova->camioes,&compareCam,&freeCamiao,&imprimeCam);
            *dest=nova;
        }
    }
    return valor;
}


int loadCidade(Cidade *dest,int id, char *nome) {
    int valor =OK;
    Cidade nova =(Cidade) malloc(sizeof(struct scidade));
    if(nova ==NULL) {
        valor =NO_MEM;
    } else {
        nova->nome=(char*) malloc(MAXS*sizeof(char));

        if(nova->nome ==NULL) {
            free(nova);
            valor=NO_MEM;
        } else {
			nova->ide=id;
            strncpy(nova->nome,nome,sizeString(nome));
	//	valor=	init_ll(&nova->camioes,&compareCam,&freeCamiao,&imprimeCam);
            *dest=nova;
        }
    }
    return valor;
}



int insereCidade(Cidade cid,ControlCid *cids) {
    int valor =OK;
    if(cid ==NULL || *cids==NULL ) {
        valor =NO_INI;
    } else {
		if(cid->ide==0){
        cid->ide=(*cids)->ids;}

        Insere_Hash(&(*cids)->cidades,cid);
        (*cids)->ids++;
		//printf("%d\n",(*cids)->ids);
    }
    return valor;
}


int insereCaminho(ControlCid cids,char *orig,char *dest) {
	int valor=OK;
	if(cids ==NULL || cids->cidades==NULL || cids->ligacoes==NULL) {
		valor=NO_INI;
	} else {
	//	printf("%d %d\n",orig,dest);
		
			valor=insere_lig(&(cids->ligacoes),orig,dest,NULL);
		}
	
	return valor;
}
/*
int existeCidade(ControlCid cids, char *nome){
	int valor=OK;
    if(cids ==NULL || cids->cidades ==NULL || nome ==NULL) {
        valor =NO_INI;
    } else {
		Cidade cid;
		novaCidade(&cid,nome);
		valor=getElem(cids->cidades,(void *)&cid,&compareCid);

		}
    
    return valor;
	
}

int getIDcid(ControlCid cids,char *nome,int *id){
	
	int valor=OK;
    if(cids ==NULL || cids->cidades ==NULL || nome ==NULL) {
        valor =NO_INI;
    } else {
		Cidade cid;
		novaCidade(&cid,nome);
		valor=getElem(cids->cidades,(void *)&cid,&compareCid);
		
			if(valor==ENCONTROU){*id=cid->ide;}
		
		}
		

    return valor;
	
	
}
int searchCidade(ControlCid cids,char *nome) {
    int valor=OK;
    if(cids ==NULL || cids->cidades ==NULL || nome ==NULL) {
        valor =NO_INI;
    } else {
		Cidade cid;
		novaCidade(&cid,nome);
		valor=getElem(cids->cidades,(void*)&cid,&compareCid);
	
		if(valor==ENCONTROU){
			valor =imprimeCid(cid);
			}
		}
    
    return valor;
}




int removerCaminho(ControlCid cids,int ido,int idd) {
    int valor=OK;
    if(cids ==NULL || cids->cidades==NULL || cids->ligacoes==NULL) {
        valor=NO_INI;
    } else {
        valor =removeAresta(&(cids->ligacoes),ido,idd);
    }
    return valor;
}


int mudarCustoCid(ControlCid cids,int ido,int idd, int distancia,char * tipoTrans) {
	int valor=OK;
	if(cids ==NULL || cids->cidades==NULL || cids->ligacoes==NULL) {
		valor=NO_INI;
	} else {
		if(ido>cids->ids ) {
			valor=NO_CID;
		} else {
			Custos cus =(Custos) malloc(sizeof(struct sCustos));
			cus->tipo_transp =(char *) malloc(sizeString(tipoTrans)*sizeof(char));
			cus->custo=distancia;
			strncpy(cus->tipo_transp,tipoTrans, sizeString(tipoTrans));
			valor =mudarCusto(&(cids->ligacoes),ido,idd,cus);
		}
	}
	return valor;
}


int removerCidade(ControlCid cids, Cidade cid) {
	int valor=OK;
	if(cids ==NULL || cids->cidades==NULL || cids->ligacoes==NULL ||cid ==NULL ) {
		valor=NO_INI;
	} else {
		if(cid->ide>cids->ids) {
			valor=NO_CID;
		} else {
			int pos =(int) cid->ide;
			removElemHash(cids->cidades,cid,&compareCid);
			cids->ligacoes->adj_list[pos]==NULL;
		}
	}
	return valor;
}*/


int novoCusto(Custos *c,int km,int custo){
	int valor =OK;
	Custos novo;
	novo=(Custos) malloc(sizeof(struct sCustos));
		if(novo ==NULL){valor =NO_MEM;}
		else{
			novo->km=km;
			novo->custo=custo;
			*c=novo;
		}
		return valor;	
}

int loadCusto(ControlCid cids,int orig,int dest,Custos c){
	
	int valor=OK;
	if(cids ==NULL || cids->cidades==NULL || cids->ligacoes==NULL || c==NULL) {
		valor=NO_INI;
	} else {
			valor =insere_lig(&(cids->ligacoes),orig,dest,c);
		}
	
	
		return valor;
}

int loadCaminho(ControlCid cids,int orig,int dest) {
	int valor=OK;
	if(cids ==NULL || cids->cidades==NULL || cids->ligacoes==NULL) {
		valor=NO_INI;
	} else {
	//	printf("%d %d\n",orig,dest);
		
			valor=insere_lig(&(cids->ligacoes),orig,dest,NULL);
		}
	
	return valor;
}


int load_custos(ControlCid *cls,char *path) {
	int valor=OK;
		char *buffer,*b;
		buffer=malloc(200*sizeof(char));
		b=buffer;
		FILE *f;
		char origem[MAXS],destino[MAXS],km[MAXS],custo[MAXS];
		if(path==NULL) {
			valor =NO_FILE;
		} else {
			f=fopen(path,"r");
			/*abre o ficheiro apenas para ler*/
			if(f ==NULL) {
				valor=NON_ER;
			} else {
				while(fgets(buffer,200,f)!=NULL) {
					int t=strlen(buffer);
					buffer[t-2]='\0';
					buffer[t-1]='\0';

					Custos cid;
					char *token;
					
					token=strsep(&buffer,"|");
					memcpy(origem,token,strlen(token)+1);

					token=strsep(&buffer,"|");
					memcpy(destino,token,strlen(token)+1);
					
					token=strsep(&buffer,"|");
					memcpy(km,token,strlen(token)+1);
					
					token=strsep(&buffer,"|");
					memcpy(custo,token,strlen(token)+1);
					novoCusto(&cid,atoi(km),atoi(custo));
					loadCusto(*cls,atoi(origem),atoi(destino),cid);
					
					buffer=b;
					memset(b,0,200*sizeof(char));
				}
			}
		}
		return valor;
	}
	
	
	
int load_cidades(ControlCid *cls,char *path) {
		int valor=OK,i;
			char *buffer,*b;
			buffer=malloc(200*sizeof(char));
			b=buffer;
			FILE *f;
			char id[MAXS],nome[MAXS],dest[MAXS];
			if(path==NULL) {
				valor =NO_FILE;
			} else {
				f=fopen(path,"r");
				/*abre o ficheiro apenas para ler*/
				if(f ==NULL) {
					valor=NON_ER;
				} else {
					
					while(fgets(buffer,200,f)!=NULL) {
							//	k++;

							//	printf("%d\n",k);
						int t=strlen(buffer);
						buffer[t-2]='\0';
						buffer[t-1]='\0';

						Cidade cid;
						char *token;

						token=strsep(&buffer,"|");
						memcpy(id,token,strlen(token)+1);
						token=strsep(&buffer,"|");
						memcpy(nome,token,strlen(token)+1);
						loadCidade(&cid,atoi(id),nome);
						insereCidade(cid,cls);
					//	printf("%s|%s",id,nome);


						while(token!=NULL){
					
							
							token=strsep(&buffer,"|");
							for(i=0;i<MAXS;i++){dest[i]='\0';}
							if(token==NULL){}
							else{
							memcpy(dest,token,strlen(token)+1);
							//printf("%d %d\n",(int) atoi(id),(int) atoi(dest));
							loadCaminho(*cls,(int)atoi(id),(int)atoi(dest));
							}




						}
					//	printf("\n");
						//printf("%s\t\t",token);printf("%s\n",email);
						//p	printf("%p",usr);
						//printf("\n\n");
						buffer=b;
						memset(b,0,200*sizeof(char));
					}
				}
			}
			return valor;
}


int save_cidades(ControlCid cls) {
	int valor=OK,i;
	Nodo_ll aux;
	Aresta aux2;
	FILE *f;
	f=fopen("cities2.txt","w");
	
	
	if(f==NULL ) {
		perror("fopen");
		valor=NON_ER;
	}else{
	
	for (i=0;i<cls->cidades->tsize;i++) {
		aux=cls->cidades->tabela[i];
		
		while (aux !=NULL) {
		//	printf("%d\n",i);
			
			
			Cidade a=(Cidade)(aux->data);
			//printf("%d\n",a->ide);
					aux2=cls->ligacoes->adj_list[a->ide];
				//	printf("%d %s\n",a->ide,a->nome);
					
					//printf("%d\n",a->ide);
				fprintf(f,"%d|%s|",a->ide,a->nome);
			while(aux2!=NULL){
					fprintf(f,"%d|",aux2->dest);
					aux2=aux2->next;
					
				}
				
				fprintf(f,"\n");
				aux = aux->next;
			}
				
				
			
		}
	}
	return 0;
}	


int save_costs(ControlCid cls) {
	int valor=OK,i;
	Aresta aux;
	FILE *f;
	f=fopen("costs2.txt","w");
	if(f==NULL) {
		perror("fopen");
		valor=NON_ER;
	}
//	printf("%d",cls->ids);
	for(i=0;i<cls->ligacoes->size;i++){
		aux=cls->ligacoes->adj_list[i];			
			while(aux!=NULL){	
				
				Custos novo =(Custos) aux->data;
				if(novo!=NULL){
				fprintf(f,"%d|%d|%d|%d|\n",i,aux->dest,novo->km,novo->custo);}
				aux=aux->next;		
			}
				//printf("%d\n",i);
		}	
	
	return 0;
}	
		
/*	
int main(){
	int i=0;
	ControlCid novas;
	novoContCid(&novas,2000);
	load_cidades(&novas,"cities.txt");
	load_custos(&novas,"costs2.txt");
	save_cidades(novas);
	save_costs(novas);
	
	printf("yy%dyy",novas->ids);
	
	//imprimetab(novas->cidades);
	visualiza(novas->ligacoes);

	int distancias[novas->ids];
	getMindist(1854,&(novas->ligacoes),distancias);
	for(i=0;i<novas->ligacoes->size;i++){
		printf("%d\n",distancias[i]);
	}
	
	
}*/