#include "cliente.h"
#include <fcntl.h>
int cmplN(void* a,void* b) {
	int valor=OK;
	cliente aa,bb;
	aa= (cliente) a;
	bb= (cliente) b;
	if(aa ==NULL || bb==NULL) {
		valor =NO_INI;
	} else {
		if((strncmp(aa->nome,bb->nome,max(strlen(aa->nome),strlen(bb->nome)))==0 &&
						strncmp(aa->cnb,bb->cnb,max(strlen(aa->cnb),strlen(bb->cnb)))==0)) {
			valor=OK;
		}
	}
	return valor;
}
int cmplN2(void* a,void* b) {
	int valor=OK;
	cliente aa,bb;
	aa= (cliente) a;
	bb= (cliente) b;
	if(aa ==NULL || bb==NULL) {
		valor =NO_INI;
	} else {
		if((strncmp(aa->nome,bb->nome,max(strlen(aa->nome),strlen(bb->nome)))==0)) {
			valor=OK;
		}
	}
	return valor;
}
int cmplC(void* aa,void* bb) {
	int valor=OK;
	cliente a,b;
	a=(cliente) aa;
	b=(cliente) bb;
	if(a== NULL || b==NULL) {
		valor= NO_INI;
	} else {
		//impcl(a);
		//impcl(b);
		if(	strncmp(a->cnb,b->cnb,max(strlen(a->cnb),strlen(b->cnb)))==0) {
			valor=IGUAL;
		}
	}
	return valor;
}
int libserv(void *a) {
	int valor=OK;
	if(a==NULL) {
		valor=NO_INI;
	} else {
		int *aa=(int*) a;
		free(aa);
	}
	return valor;
}
int libcl(void *a) {
	int valor =OK;
	if(a==NULL) {
		valor =NO_INI;
	} else {
		cliente aa= (cliente) a;
		free((aa->nome));
		free(aa->morada);
		StackDestroy(&(aa->servicos));
	}
	return OK;
}
char *keyN(void *elem) {
	int valor =OK;
	cliente aa;
	if(aa=NULL) {
		valor=NO_INI;
	} else {
		aa = (cliente) elem;
		//	char *nome=(char *) malloc(MAXS*sizeof(char));
		//	strncpy(nome,aa->nome,strlen(aa->nome));
		return aa->nome;
	}
}
char *keyC(void *elem) {
	int valor =OK;
	cliente aa;
	if(aa=NULL) {
		valor =NO_INI;
	} else {
		aa = (cliente) elem;
		//	char *contrib=(char *) malloc(MAXS*sizeof(char));
		//	strncpy(contrib,aa->cnb,strlen(aa->cnb));
		return aa->cnb;
	}
}
int impmov(void *a) {
	int valor =OK;
	int *aa;
	if(aa==NULL) {
		valor =NO_INI;
	} else {
		aa=(int *) a;
		printf("|%u|\n",*aa);
	}
	return valor;
}
int impcl(void *a) {
	int valor =OK;
	cliente aa;
	if(aa ==NULL) {
		valor=NO_INI;
	} else {
		aa = (cliente) a;
		//printf("%p",aa);
		printf("|Cliente nº%d|\n",aa->ide);
		printf("|Nome:%s |",aa->nome);
		printf("|Contribuinte:%s|\n",aa->cnb);
		printf("|Morada:%s |",aa->morada);
		printf("|e-mail:%s |\n",aa->email);
		printf("-------------------------------------\n");
	}
	return valor;
}
int novoContClie(clientes *cls) {
	int valor=OK;
	clientes novo = (clientes ) malloc(sizeof(struct cliente_cont));
	if(novo ==NULL) {
		valor =NO_MEM;
	} else {
		novo->ids=0;
		novo->idc=0;
		valor=NovaHash(10000,&novo->nomes,&cmplN,&libcl,&impcl,&keyN);
		valor=NovaHash(10000,&novo->contrib,&cmplC,&libcl,&impcl,&keyC);
		*cls=novo;
	}
	return valor;
}
int registaMovimento(clientes cls,char *contrib,int *custo) {
	int valor =OK;
	if(cls ==NULL || cls->contrib ==NULL || contrib ==NULL) {
		valor =NO_INI;
	} else {
		int n;
		void **data;
		procuraContrib(cls,contrib,&data,&n);
		if(n==1) {
			valor=StackPush((((cliente)data[0])->servicos),custo);
			((cliente)data[0])->total=((cliente)data[0])->total + *custo;
			if(cls->tuts<((cliente)data[0])->total){
				cls->idc=((cliente)data[0])->ide;
				cls->tuts=((cliente)data[0])->total;
			}
		} else {
			valor=NON_ER;
		}
	}
	return valor;
}

int verMovimentos(clientes cls,char *contrib){
	
	int valor =OK;
	if(cls ==NULL || cls->contrib ==NULL || contrib ==NULL) {
		valor =NO_INI;
	} else {
		int n;
		void **data;
		procuraContrib(cls,contrib,&data,&n);
		if(n==1) {print(((cliente)data[0])->servicos);}
		 else {
			valor=NON_ER;
		}
	}
	
	return valor;
	
	
	
}

int novoCliente(cliente *dest,char *nome,char *morada,char *email,char *contribuinte) {
	int valor=OK;
	if(nome == NULL || morada==NULL || contribuinte == NULL) {
		valor=NO_INI;
	} else {
		cliente novo= (cliente )malloc(sizeof(struct scliente));
		/*aloca o espaco do novo cliente*/
		novo->nome=(char*) malloc(MAXS*sizeof(char));
		/*aloca espaco para a string nome*/
		novo->morada=(char *) malloc (MAXS*sizeof(char));
		/*aloca espaco para a string  morada*/
		novo->email=(char *) malloc (MAXS*sizeof(char));
		novo->cnb=(char *) malloc (MAXS*sizeof(char));
		if(novo ==NULL || novo->nome ==NULL || novo->morada == NULL) {
			valor=NO_MEM;
		} else {
			memcpy(novo->nome,nome,strlen(nome));
			memcpy(novo->morada,morada,strlen(morada));
			memcpy(novo->cnb,contribuinte,strlen(contribuinte));
			memcpy(novo->email,email,strlen(email));
			//printf("%s %s\n",contribuinte,novo->cnb);
			StackCreate(&novo->servicos,&impmov,&libserv);
			/*cria a stack dos servicos*/
			*dest=novo;
		}
	}
}
int insereCliente(cliente novo,clientes *cls) {
	int valor=OK;
	if(cls==NULL || novo ==NULL) {
		valor=NO_INI;
	}
	/*se uma estrutura nao estiver inicializada*/ else {
		(novo)->ide = (*cls)->ids;
		(*cls)->ids++;
		Insere_Hash(&((*cls)->contrib),novo);
		/*Insere na tabela dos contribuinte*/
		Insere_Hash(&((*cls)->nomes),novo);
		/*insere na tabeela dos nomes*/
	}
	return valor;
}
int procuraContrib(clientes c,char *contrib,void ***elems,int *n) {
	int valor =OK;
	if(c!=NULL && c->contrib !=NULL) {
		cliente nov;
		novoCliente(&nov,"","","",contrib);
		getElems(c->contrib,nov,elems,n,&cmplC);
		//	printf("xxx%dxx\n",);
		//	free(nov);
	} else {
		valor=NO_INI;
	}
	return valor;
}

int procuraNome(clientes c,char *nome,void ***elems,int *n) {
	int valor =OK;
	if(c!=NULL && c->contrib !=NULL) {
		cliente nov;
		novoCliente(&nov,nome,"","","");
		getElems(c->contrib,nov,elems,n,&cmplN2);
		printf("xxx%dxx\n",*n);
		//	free(nov);
	} else {
		valor=NO_INI;
	}
	return valor;
}

int load_users(clientes *cls,char *path) {
	int valor=OK,fdin;
	char *buffer,*b;
	buffer=malloc(200*sizeof(char));
	b=buffer;
	FILE *f;
	char cnb[MAXS],morada[MAXS],email[MAXS],nome[MAXS];
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
				//printf("%s\n",buffer);
				//printf("-------\n");
				cliente usr;
				char *token;
				token=strsep(&buffer,"|");
				memcpy(cnb,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",cnb);
				token=strsep(&buffer,"|");
				memcpy(nome,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",nome);
				token=strsep(&buffer,"|");
				memcpy(email,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",email);
				token=strsep(&buffer,"|");
				memcpy(morada,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",morada);
				novoCliente(&usr,nome,morada,email,cnb);
				//p	printf("%p",usr);
				insereCliente(usr,cls);
				//printf("\n\n");
				buffer=b;
				memset(b,0,200*sizeof(char));
			}
		}
	}
	return valor;
}
int load_users2(clientes *cls,char *path) {
	int valor=OK,fdin;
	char *buffer,*b;
	buffer=malloc(200*sizeof(char));
	b=buffer;
	FILE *f;
	char cnb[MAXS];
	char morada[MAXS];
	char email[MAXS];
	char nome[MAXS];
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
				//printf("%s\n",buffer);
				//printf("-------\n");
				cliente usr;
				char *token;
				token=strsep(&buffer,"\t");
				memcpy(cnb,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",cnb);
				token=strsep(&buffer,"\t");
				memcpy(nome,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",nome);
				token=strsep(&buffer,"\t");
				memcpy(email,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",email);
				token=strsep(&buffer,"\t");
				memcpy(morada,token,strlen(token)+1);
				//printf("%s\t\t",token);printf("%s\n",morada);
				novoCliente(&usr,nome,morada,email,cnb);
				//p	printf("%p",usr);
				insereCliente(usr,cls);
				//printf("\n\n");
				buffer=b;
				memset(b,0,200*sizeof(char));
			}
		}
	}
	return valor;
}
int save_users(clientes cls) {
	int valor=OK,handle,i;
	Nodo_ll aux;
	FILE *f;
	f=fopen("users.txt","w");
	if(f==NULL) {
		perror("fopen");
		valor=NON_ER;
	}
	for (i=0;i<cls->ids;i++) {
		aux=cls->nomes->tabela[i];
		while (aux !=NULL) {
			cliente a=((cliente)(aux->data));
			fprintf(f,"%s|%s|%s|%s;\n",a->cnb,a->nome,a->email,a->morada);
			aux = aux->next;
		}
	}
	return 0;
}
/*
int main() {
	clientes c;
	novoContClie(&c);
	load_users(&c,"users.txt");
	int n;
	void **data;
	imprimetab(c->nomes);
	procuraContrib(c,"9000025351",&data,&n);
	printf("%d",n);
	strncpy((((cliente)data[0])->nome),"rogerui",MAXS);
	printf("caifba");
	imprimetab(c->nomes);
	// save_users(c);
	return 1;
}*/