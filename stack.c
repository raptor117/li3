#include "stack.h"

int StackCreate(Stack *stac,int (*libertar)(void*),int (*imprime)(void *)){
	
	
	Stack stack=OK;
	int valor=0;
	
	if((stack =(Stack) malloc(sizeof(struct cstack)))== NULL){valor=NO_MEM;}/*alocar memória da stack*/ 
	else{
		stack->Top = NULL; /*iniciar o topo da stack*/
		stack->libertar=libertar;
		stack->imprime=imprime;
		*stac=stack; /*guardar o endreco da stack*/
	
		}
		return valor;

}

int StackDestroy(Stack *pstack){
	
	Stack TmpStack = *pstack;
	pelem TmpNo;
	int valor=OK;
	
	if(TmpStack == NULL){valor =NO_INI;}
	else{
		
		while(TmpStack ->Top != NULL){
			/*libertar a memória ocupada pelos elementos da stack*/
			TmpNo =TmpStack->Top;
			TmpStack->Top=TmpStack->Top->PtAnt;
			(TmpStack)->libertar(TmpNo->data);
			free(TmpNo);
			
		}
		free(TmpStack->libertar);
		free(TmpStack);  /*Libertar a memória ocupada pela stack*/
		*pstack=NULL;
		
	}
	return valor;
		
}


int StackPush (Stack pstack,void *data) {
	pelem TmpNo,aux;
	
	int valor=OK;
	
	if(!pstack) {
		valor=NO_INI;
	} else {
		
		if((TmpNo = (pelem) malloc(sizeof(struct no))) ==NULL) {
			valor =NO_MEM;
		} else {
			
			TmpNo->PtAnt=pstack->Top;
			pstack->Top=TmpNo;
			aux=pstack->Top;
			aux->data=data;
		}
	}
	return valor;
}



int StackPop(Stack pstack, void *data) {
	pelem TmpNo,aux;
	int valor=OK;
	if(pstack == NULL) {
		valor =NO_INI;
	} else {
		if(pstack->Top == NULL) {
			valor =NO_INI;
		} else {
			if(data==NULL) {
				valor =NO_INI;
			} else {
				*aux=*pstack->Top;
				data=aux->data;
				TmpNo=pstack->Top;
				pstack->Top=pstack->Top->PtAnt;
				pstack->libertar(TmpNo->data);
				free(TmpNo);
			}
		}
	}
	return valor;
}



int print(Stack pstack){
	int valor =OK;
	if(pstack ==NULL || pstack->Top==NULL){valor =NO_INI;}
	while(pstack->Top){
        pstack->imprime(pstack->Top->data);
        pstack->Top=pstack->Top->PtAnt;
    }
    
    return 1;
}



