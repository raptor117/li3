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
	valor=load_custos(&(*dest)->cidz,"cost.txt");
	valor=load_camioes(&(*dest)->cmz,"trucks.txt");
	valor=loadcity_trucks((*dest)->cidz,(*dest)->cmz,"trucks.txt");/*este tem que ser chamado depois de
	                                                                a load camioes e load cidades ja foi chamada*/
	return valor;
}


int realiza_movimento(Trans trs,char *origem,char *dest,char *contrib){

	int valor =OK;
	camiao transporte;
	int source,destino,nc,ncc,custo;
	int d[trs->cidz->ids];
	ControlCid aux=trs->cidz;
	valor =getId(trs->cidz,origem,&source);/*id da origem*/
	valor =getId(trs->cidz,dest,&destino);/*id do destino*/
	void **cid;
	void **clie;
    valor=searchCity(trs->cidz,dest,&cid,&nc);
    valor=procuraContrib(trs->cliez,contrib,&clie,&ncc);
	getMindist(source,&trs->cidz->ligacoes,d);
	/*custo da viagem*/ 
	int i=0;


	if(trs ==NULL ||origem ==NULL ||dest ==NULL || contrib==NULL && nc==1 && ncc==1){valor=NO_MEM;}
	else{
		if(getCamiao(trs->cmz,origem,transporte)==NO_HEAD){getCamiaoProx(trs->cmz,transporte,d,destino);}/*pesquisa de camiao*/
		else{
		  //  ((Cidade)cid[0])->nacedidas++;
			//setLocalidade(transporte,dest);/*da uma nova localidade ao camiao,a localidade destino*/
			//InsertCamiaoCid(((Cidade)cid[0]),transporte);/*insere o camiao na cidade*/
		    //InsertClienteCid((Cidade)cid[0],(cliente)clie[0]);/*insere um cliente na cidade*/
		    //actualizaStats(trs->cidz,((Cidade)cid[0]));
		    //custo=atoi((transporte->custokm))*d[destino];
		    //registaMovimento(trs->cliez,contrib,&custo);
		    //printf("%d",custo);   
		}
		
		
	}
	
	return valor;
}

/*Funcao random para atribuir servicos a clientes
int atribServico(Trans dest) {
    int y=0,l=0;
	char citis[(int)dest->cidz->cidades->tsize][MAXS];
	char users[(int)dest->cidz->cidades->tsize][MAXS];
	/*for(y=0;y<(int)dest->cidz->cidades->tsize;y++){
	    for(l=0;l<MAXS;l++){
	        users[y][l]='\0';
	    ;}
	
	}*//*
	char *buffer,*b;
	buffer=malloc(200*sizeof(char));
	int i=0,j,valor,o=0,x,c,v,z;
	Nodo_ll aux;
	b=buffer;
	FILE *f,*h,*g;
	char nome[MAXS];

		f=fopen("cities.txt","r");
		h=fopen("users.txt","r");
		g=fopen("users2.txt","w");
		
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
				strcpy(citis[i],nome);
				//citis[i][strlen(nome)]='\0';
			   // printf("%s\n",citis[i]);

				i++;
				buffer=b;
				memset(b,0,200*sizeof(char));
				
			}
			
			while(fgets(buffer,200,h)!=NULL) {
				int t=strlen(buffer);
				buffer[t-2]='\0';
				buffer[t-1]='\0';
				Cidade cid;
				char *token;
				token=strsep(&buffer,"|");
				memcpy(nome,token,strlen(token)+1);
				strncpy(users[o],nome,strlen(token)+1);
				//users[o][strlen(nome)]='/0';
				o++;
				buffer=b;
				memset(b,0,200*sizeof(char));
				
			}
			//printf("%d\n",i);
			o--;
			for (j=0;j<i;j++) {
				x=rand()%10;
				//printf("%d\n",x);
				
				for(c=0;c<x;c++){
				        v=rand()%i;
				        z=rand()%i;
				        if(z!=v){
					fprintf(g,"%s|%s|%s|%d|\n",users[rand()%o],citis[z],citis[v],rand()%300);}
					}
				
			}
			
			

		}	
}*/
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