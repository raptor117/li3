#include "avl.h"
int new_ControlAvl(Cont_avl *nova,int (*compare)(void *,void *),int (*libertar)(void *), int (*imprime)(void*),int tamanho){
		
		int valor =OK;
		Cont_avl novo =(Cont_avl) malloc(sizeof(struct sCont));
		if(novo==NULL){valor=NO_MEM;}
		else{
			
			novo->compare=compare;
			novo->libertar=libertar;
			novo->imprime=imprime;
			novo->sizeofData=tamanho;
			*nova=novo;
		}
		
		
	}

int insertAVl(Cont_avl cont,Nodo *root,void *data){
	
	int valor=OK;
	if( *root ==NULL) {
		/*inserir elemento*/
		if((valor= CriaNo(data,root)==OK));
		return valor;
	} else if( (cont)->compare((*root)->data, data)==MENOR){insertAVl(cont,&(*root)->esq, data);}
	 else if( (cont)->compare((*root)->data,data)==MAIOR){insertAVl(cont, &(*root)->dir, data); }
	else CriaNo(data,root) ;
	
	Balance(root);
	return valor;
}


int CriaNo (void *data,Nodo *root) {
	int valor=OK;
	Nodo no = (Nodo) malloc (sizeof(struct nodo));
	if(no==NULL) {
		valor=NO_MEM;
	} else {
		no->data=data;
		no->esq=NULL;
		no->dir=NULL;
		no->altura=1;
		*root=no;
	}
	return valor;
}	


int AlturArv(Nodo praiz) {
	if(praiz ==NULL) return 0; else return praiz->altura;
}

int ShiftRight (Nodo *pno) {
	int Altesq,Altdir,valor=OK;
	if (pno==NULL) {
		valor =NO_INI;
	} else {
		Nodo No =(*pno)->esq;
		(*pno)->esq=No->dir;
		No->dir=*pno;
		/*actualizar a altura dos nós envolvidos*/
		Altesq=AlturArv((*pno)->esq);
		Altdir=AlturArv((*pno)->dir);
		(*pno)->altura = Altesq>Altdir ? Altesq +1 : Altdir+1;
		Altesq=AlturArv(No->esq);
		Altdir=(*pno)->altura;
		No->altura =Altesq>Altdir ? Altesq+1 : Altdir +1;
		*pno=No;
	}
	return valor;
}

int ShiftLeft (Nodo *pno) {
	int Altesq,Altdir,valor=OK;
	if(pno ==NULL) {
		valor =NO_INI;
	} else {
		Nodo No =(*pno)->dir;
		(*pno)->dir=No->esq;
		No->esq=*pno;
		/*actualizar a altura dos nós envolvidos*/
		Altesq=AlturArv((*pno)->esq);
		Altdir=AlturArv((*pno)->dir);
		(*pno)->altura = Altesq>Altdir ? Altesq +1 : Altdir+1;
		Altesq=(*pno)->altura;
		Altdir=AlturArv(No->dir);
		No->altura =Altesq>Altdir ? Altesq+1 : Altdir +1;
		*pno=No;
	}
	return valor;
}

int DoubleShiftLeft(Nodo *pno) {
	int valor=OK;
	if(pno==NULL) {
		valor =NO_INI;
	} else {
		ShiftRight((void*)&(*pno)->dir);
		ShiftLeft(pno);
	}
	return valor;
}

int DoubleShiftRight(Nodo *pno) {
	int valor=OK;
	if(pno==NULL) {
		valor =NO_INI;
	} else {
		ShiftLeft((void*)&(*pno)->esq);
		ShiftRight(pno);
	}
	return valor;
}

int Balance (Nodo *root) {
	int Altesq,Altdir,valor=OK;
	if (*root ==NULL) {
		valor=NO_INI;
	}
	/*subarvore vazia */ else {
		/*calculo da altura das subarvores esquerda e direita*/
		Altesq=AlturArv((*root)->esq);
		Altdir=AlturArv((*root)->dir);
		if (Altesq -Altdir ==2) {
			/*subarvore da esquerda desiquilibrada ?*/
			Altesq=AlturArv(((*root)->esq)->esq);
			Altdir=AlturArv(((*root)->esq)->dir);
			if (Altesq >=Altdir) {
				ShiftRight(root);
			} else DoubleShiftRight(root);
		} else if (Altdir -Altesq == 2) {
			/*subarvore da direita desiquilibrada*/
			Altesq=AlturArv(((*root)->dir)->esq);
			Altdir=AlturArv(((*root)->dir)->dir);
			if (Altdir >= Altesq) {
				ShiftLeft(root);
			} else DoubleShiftLeft(root);
		} else {
			(*root)->altura= Altesq > Altdir? Altesq+1 :Altdir+1;
		}
		/*actualizar a altura do no*/
	}
	return valor;
}


int  TraveOrder(Nodo root,int (*imprime)(void *)) {
	int valor=OK;
	if(root != NULL) {
		TraveOrder(root->esq,imprime);
		imprime(root->data);
		TraveOrder(root->dir,imprime);
	} else {
		valor =NO_INI;
	}
	return valor;
}


void DestruirNo (Nodo *aux,int (*libertar)(void *)) {
	    libertar((*aux)->data);
		free(*aux);
		*aux=NULL;
}


int SubstituirNo(Nodo *root,void** data,int (*libertar)(void *)) {
	int valor=OK;
	Nodo aux=*root;
	if(*root ==NULL) {
		valor=NO_INI;
	} else {
		if((*root)->esq ==NULL) {
			*data= (*root)->data;
			*root =(*root)->dir;
			DestruirNo(&aux,libertar);
		} else SubstituirNo(&(*root)->esq, data,libertar);
		Balance(root);
	}
	return valor;
}


int  RemoverNo (Nodo *root,int (*libertar)(void *)) {
	int valor=OK;
	Nodo aux=*root;
	if(*root==NULL) {
		valor=NO_INI;
	} else {
		if ((*root)->esq ==NULL && (*root)->dir ==NULL) {
			DestruirNo(&aux,libertar);
		}
		/*Sem subarvores*/ else if ((*root)-> esq == NULL) {
			/*com subarvore direito*/
			*root=(*root)->dir;
			/*ligar a direita*/
			DestruirNo(&aux,libertar);
			/*eliminar o elemento*/
		} else if ((*root)->dir ==NULL) {
			/*com subarvore esquerda*/
			*root=(*root)->esq;
			/*ligar a esquerda*/
			DestruirNo(&aux,libertar);
			} else {
			/*com subarvires direita e esquerda , substituir pelo menor elemento da subarvore direita*/
			SubstituirNo(&(*root)->dir,&(*root)->data,libertar);
		}
	}
	return valor;
}

int  RemoverElem(Cont_avl cont,Nodo *root,void *data,int (*compare)(void*,void*)) {
	int valor=OK;
	if(*root ==NULL) valor=NO_INI;
	/*a arvore esta vazia ou o elemento nao existe*/ else {
		if (compare((*root)->data,data)==MAIOR) {
			RemoverElem(cont,&(*root)->dir, data,compare);
		} else {
			if (compare((*root)->data,data)==MENOR) {
				RemoverElem(cont,&(*root)->esq, data,compare);
			} else {
				/*copiar e eleminar o elemento*/
				if(compare((*root)->data,data)==IGUAL) {
					data =(*root)->data;
					RemoverNo(root,(cont)->libertar);
				}
			}
		}
	}
	Balance(root);
	/*reequilibrar a arvore*/
	return valor;
}

