#include "LL.h"

int init_ll(genLL *nova,int (*ll_cmp) (void*, void*), int (*remove_data) (void*),int (*print) (void*)) {
	int valor =OK;
	if(nova ==NULL) {
		valor=NO_INI;
	} else {
		genLL ptr = (genLL) malloc(sizeof(struct sGLL));
		if(ptr==NULL) {
			valor=NO_MEM;
		} else {
			ptr->remove_data = remove_data;
			ptr->ll_cmp = ll_cmp;
			ptr->print=print;
			ptr->ocupado = 0;
			ptr->root = NULL;
			*nova=ptr;
		}
	}
}

int Cria_elem(LL *novo,void *data){
	int valor=OK;
	LL nova=(LL) malloc(sizeof(struct sLL));
	if(nova ==NULL){valor =NO_MEM;}
	else{
		nova->data=data;
		nova->next=NULL;
		*novo=nova;
	}
	
	return valor;
	
}


int imprime_elems(genLL ll){
	LL aux=ll->root;
	while(aux!=NULL){
		ll->print(aux->data);
		aux=aux->next;
	}
	
}

int insert_LL_s(genLL cont,LL *head,void *data){
	int valor =OK;
	if(*head==NULL){cont->ocupado++; valor=Cria_elem(head,data);}
	else{
		if(cont->ll_cmp((*head)->data,data)==IGUAL){(*head)->data=data;}
		else{
			valor= insert_LL(cont,&(*head)->next,data);}
	}
	
}

int insert_LL(genLL cont,LL *head,void *data){
	
	int valor =OK;
	LL novo,ant=NULL,act;
	act=*head;
	Cria_elem(&novo,data);
	//printf("%p\n",act);
	//printf("%p--%d--%p",act,act->next);


	//printf("%p--%d--%p",act,cont->ll_cmp(data,(*head)->data),act->next);
	
	if(novo==NULL){valor=NO_MEM;}
	else{
		while(act!=NULL && cont->ll_cmp(data,(*head)->data)==MAIOR ){

			ant=act;
			act=act->next;
		}
		if(ant == NULL){
			novo->next=*head;
			
			*head=novo;
		}
		else{
			novo->next=act;
			ant->next=novo;
		}
	}
	
}

int get_head(genLL ptr,void *data){
	int valor =OK;
	LL aux;
	if(ptr==NULL){valor =NO_INI;}
	else{
		if(ptr->root!=NULL){
		data=ptr->root->data;
	 	aux=ptr->root;
		ptr->root=ptr->root->next;
		free(aux);
		ptr->ocupado --;}
		else{valor=NO_HEAD;}
	}
	return valor;
	
}
int get_ll(genLL ptr, void **data) {
	int valor=OK;
	if(ptr==NULL || data==NULL) {
		valor=NO_INI;
	} else {
		LL aux = (ptr->root);
		for (; aux; aux = (aux)->next) {
			if (ptr->ll_cmp((aux)->data, *data)==IGUAL) {
				*data=(aux)->data;
			}
		}
	}
	return valor;
}


int remove_ll(genLL ptr, void *data) {
	int valor=OK;
	LL aux = ptr->root, prev = NULL;
	if(!aux) {
		valor=NO_INI;
	} else {
		if(ptr->ll_cmp(aux->data, data)) {
			ptr->root = aux->next;
			free(aux);
			ptr->ocupado--;
		} else {
			for (prev = aux, aux = aux->next; aux; prev = aux, aux = aux->next) {
				if(ptr->ll_cmp(aux->data, data)) {
					prev->next = aux->next;
					free(aux);
					ptr->ocupado --;
					return 1;
				}
			}
		}
	}
	return 0;
}

int LLDestroy(genLL *pst){
	
	genLL Tmp = *pst;
	LL TmpNo;
	int valor=OK;
	
	if(Tmp == NULL){valor =NO_INI;}
	else{
		
		while(Tmp ->root != NULL){
			/*libertar a memória ocupada pelos elementos da stack*/
			TmpNo =Tmp->root;
			Tmp->root=Tmp->root->next;
			(Tmp)->remove_data(TmpNo->data);
			free(TmpNo);
			
		}
		free(Tmp);  /*Libertar a memória ocupada pela stack*/
		*pst=NULL;
		
	}
	return valor;
		
}