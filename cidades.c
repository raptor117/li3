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
    if((strncmp(aa->nome,bb->nome,max(sizeString(aa->nome),sizeString(bb->nome)))>0)
            ) {
        valor=MAIOR;
    }
    if((strncmp(aa->nome,bb->nome,max(sizeString(aa->nome),sizeString(bb->nome)))<0)
            ) {
        valor=MENOR;
    }
    if((strncmp(aa->nome,bb->nome,max(sizeString(aa->nome),sizeString(bb->nome)))==0)
            ) {
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
		destroy_ll((aa->camioes));
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
		printf("|Nome do transp:%s |Custo: %d|\n\n",aa->tipo_transp,aa->custo);
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
        printf("Cidade nº%4d\nNome:%8s \n\n",aa->ide,aa->nome);
    }
    return valor;
}


int keyCidade(void *elem) {
    Cidade aa;
    aa = (Cidade) elem;
    return sizeString((aa)->nome);
}


unsigned  int novoContCid(ControlCid *cntcid,int nCidades) {
    int valor;
    ControlCid novo=(ControlCid) malloc(sizeof(struct cidadeControl));
    if(novo==NULL) {
        valor =NO_INI;
    } else {
       
 		valor=NovaHash(nCidades,&novo->cidades,(int) sizeof(Cidade),&compareCid,&freeCid,&imprimeCid,&keyCidade);
        valor=inicializa(nCidades,&(novo->ligacoes),&freeLig,&imprimeTransp, sizeof(struct sCustos),&switx,&getCustotrans);
        
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
            strncpy(nova->nome,nome,sizeString(nome));
		valor=	init_ll(&nova->camioes,&compareCam,&freeCamiao,&imprimeCam);
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
        cid->ide=(*cids)->ids;
        Insere(&(*cids)->cidades,cid);
        (*cids)->ids++;
    }
    return valor;
}

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

int insereCaminho(ControlCid cids,char *orig,char *dest,int distancia,char *tipoTrans) {
	int valor=OK,ido,idd;
	if(cids ==NULL || cids->cidades==NULL || cids->ligacoes==NULL) {
		valor=NO_INI;
	} else {

			valor=getIDcid(cids,orig,&ido);
			valor=getIDcid(cids,dest,&idd);
			if(valor !=ENCONTROU ||	cids->ids<ido || cids->ids<idd) {
				valor = NO_CID;
			} else {
				
				Custos cus =(Custos) malloc(sizeof(struct sCustos));
				cus->tipo_transp =(char *) malloc(sizeString(tipoTrans)*
															sizeof(char));
				cus->custo=distancia;
				strncpy(cus->tipo_transp,tipoTrans, sizeString(tipoTrans));
				valor =insere_lig(&(cids->ligacoes),ido,idd,cus);
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
}