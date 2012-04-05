#pragma once
#include <stdlib.h>
#include <stdio.h>

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/


typedef struct no *pelem;

/*elemento de uma lista*/
struct no{
	
	void *data;
	pelem PtAnt;
};

/*estrutura de controlo da stack*/
typedef struct cstack{
	int (*libertar)(void *);
	int (*imprime)(void *);
	pelem Top;/*aponta para a cabeca da stack*/
	
}*Stack;

/*cria um nova estrutura de Stack
Retorna OK ou NO_INI*/
	int StackCreate(Stack *stac,int (*libertar)(void*),int (*imprime)(void *));

/*apaga todos os elementos da stack
Retorna OK ou NO_INI*/
int StackDestroy(Stack *pstack);

/*coloca um elemento no topo da stack*/
int StackPush (Stack pstack,void *data);

/*retira o primeiro elemento da stack  e guarda em data
Retorna OK ou NO_INI*/
int StackPop(Stack pstack, void *data);

/*imprime todos os elementos da stack*
Retorna ok ou NO_INI*/
int print(Stack pstack);