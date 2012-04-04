#include "hash_ll.h"
int NovaHash(int tsize,Hash *hash,int  (*compare)(void *,void*),
int  (*libertar)(void *),int  (*imprime)(void *),char *(*key) (void*)) {
	int i,valor=OK;
	Hash nova =(Hash) malloc(sizeof(struct hash));
	if(nova==NULL) {
		valor=NO_MEM;
	} else {
		(nova->tabela)=(Nodo_ll*) malloc(tsize*sizeof(Nodo_ll));
		if(	(nova)->tabela != NULL) {
			(nova)->cmp=compare;
			(nova)->remove_data=libertar;
			(nova)->print=imprime;
			(nova)->tsize=tsize;
			(nova)->nnodo=0;
			(nova)->key=key;
			for (i=0;i<tsize;i++) {
				(nova)->tabela[i]=NULL;
			}
			(*hash)=nova;
		} else {
			valor =NO_MEM;
		}
	}
	return valor;
}
int Insere_Hash(Hash *hash,void *data) {
	unsigned valor = OK;
	int i;
	if((*hash)==NULL) {
		valor =NO_INI;
	}
	/*se a hash nao foi inicializada*/ else {
		/*se esta inicializada*/
		if((*hash)->nnodo/(*hash)->tsize >= 0.75) {
			/*se atingiu o load factor*/
			Hash nova;
			double tsizez =((*hash)->tsize)*2;
			NovaHash(tsizez,&nova,(*hash)->cmp,(*hash)->remove_data,
																			(*hash)->print,(*hash)->key);
			if(nova!=NULL) {
				/*se conseguir allocar a nova tabela*/
				valor=insertNodo((*hash),&((*hash)->tabela[fHash((*hash)->key(data),(*hash)->tsize)]),data);
				for (i=0;i<(*hash)->tsize;i++) {
					/*inserir os elementos na nova tabela*/
					/*funcao que percorra todos os elementos da arvore*/
					InsereElems((*hash)->tabela[i],&nova);
				}
				nova->nnodo=(*hash)->nnodo;
				free(*hash);
				/*nao podemos eliminar os elementos ou a nova tabela fica vazia*/
				*hash=NULL;
				(*hash)=nova;
				(*hash)->nnodo++;
			} else {
				valor=NO_MEM;
			}
		} else {
			valor=insertNodo((*hash),&((*hash)->tabela[fHash((*hash)->key(data),(*hash)->tsize)]),data);
			(*hash)->nnodo++;
		}
		/*se nao atingiu o load factor*/
	}
	return valor;
}
void InsereElems (Nodo_ll antigo,Hash *nova) {
	if(antigo!=NULL) {
		insertNodo(*nova,&((*nova)->tabela[fHash((*nova)->key(antigo->data),(*nova)->tsize)]),antigo->data);
		InsereElems(antigo->next,nova);
	}
}
int CriaNodo(Nodo_ll *novo,void *data) {
	int valor=OK;
	Nodo_ll nova=(Nodo_ll) malloc(sizeof(struct sNodo));
	if(nova ==NULL) {
		valor =NO_MEM;
	} else {
		nova->data=data;
		nova->next=NULL;
		*novo=nova;
	}
	return valor;
}
int insertNodo(Hash cont,Nodo_ll *head,void *data) {
	int valor =OK;
	//cont->print(data);
	if(cont ==NULL || data ==NULL) {
		valor=NO_INI;
	} else {
		if(*head==NULL) {
			valor=CriaNodo(head,data);
		} else {
			if(cont->cmp((*head)->data,data)==IGUAL) {
				(*head)->data=data;
			} else {
				valor= insertNodo(cont,&(*head)->next,data);
			}
		}
	}
	return valor;
}
int fHash(char *str,int tsize) {
	int hash = 5381;
	int c;
	/*	printf("\n%s \t\t",str);*/
	while ((c = *str++))
			            hash = ((hash << 5) + hash) + c;
	/* hash * 33 + c */
		//printf("kk%dkk\n",abs(hash%tsize));
	return abs(hash%tsize);
}


int imprimetab(Hash hash) {
	int i=0,valor=OK;
	Nodo_ll aux;
	if(hash ==NULL || hash->tabela ==NULL) {
		valor=NO_INI;
	} else {
		for (i=0;i<hash->tsize;i++) {
			aux=hash->tabela[i];
			while(aux) {
				valor =hash->print(aux->data);
				aux=aux->next;
			}
		}
	}
	return valor;
}


int remove_hash(Hash *ptr, void *data) {
	int origem =fHash((*ptr)->key(data),(*ptr)->tsize);
	Nodo_ll ant=NULL,actual=(*ptr)->tabela[origem];
	int valor=OK,breack=0;
	if(ptr==NULL || (*ptr)->tabela ==NULL || (*ptr)->tabela[origem]==NULL) {
		valor=NO_INI;
	} else {
		while(actual!=NULL && breack==0) {
			if((*ptr)->cmp(actual->data,data)==IGUAL) {
				if(ant==NULL) {
					(*ptr)->tabela[origem]=actual->next;
					breack=1;
				}
				/*se for o primeiro elemento*/ else {
					ant->next=actual->next;
					breack=1;
				}
			} else {
				ant=actual;
				actual=actual->next;
			}
			/*printf("%d\n",actual->cost);*/
		}
		
		(*ptr)->remove_data(actual->data);
		free(actual);
		actual=NULL;
		(*ptr)->nnodo--;
	}
	return valor;
}

int HashDestroy(Hash *pst) {
	int i;
	Hash Tmp = *pst;
	Nodo_ll TmpNo;
	int valor=OK;
	if(Tmp == NULL) {
		valor =NO_INI;
	} else {
		for (i=0;i<(*pst)->tsize;i++) {
			while(Tmp ->tabela[i] != NULL) {
				/*libertar a memória ocupada pelos elementos da lista*/
				TmpNo =Tmp->tabela[i];
				Tmp->tabela[i]=Tmp->tabela[i]->next;
				(Tmp)->remove_data(TmpNo->data);
				free(TmpNo);
			}
		}
		free(Tmp);
		/*Libertar a memória ocupada pela lista*/
		*pst=NULL;
	}
	return valor;
}

int nElems(Nodo_ll k,void *data,int *n,	int (*cmp) (void*, void*)) {
	int valor =OK;
	n=0;
	Nodo_ll aux=k;
	if(k==NULL) {
		valor =NO_INI;
	} else {
		while(aux!=NULL) {
			if(cmp(aux->data,data)==IGUAL) {
				n++;
			}
			aux=aux->next;
		}
	}
	return valor;
}
int getElems(Hash hash,void *data, void ***elems,int *n,int (*cmp) (void*, void*)) {
	int valor =OK,num=0,pos=fHash(hash->key(data),hash->tsize),k=0;
	//printf("%s %d",hash->key(data),hash->tsize);
	void **lista;

	if(hash ==NULL ||hash->tabela ==NULL || data ==NULL || n ==NULL) {
		valor=NO_INI;
	} else {
		/*Inicialicacao dos elementos*/
		Nodo_ll aux=hash->tabela[pos];
		nElems(hash->tabela[pos],data,&num,cmp);
		lista=(void **)malloc((num)*sizeof(void*));
		/*ciclo de procura dos elementos*/
		while(aux!=NULL) {
			if(cmp(aux->data,data)==IGUAL) {printf("Entrou");
				lista[k]=aux->data;
				/*guardar no array*/
				k++;
			}
			aux=aux->next;
		}
		*elems=lista;
		*n=k;
	}
	return valor;
}