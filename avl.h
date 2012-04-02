//#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/
#define MAIOR 4
#define IGUAL 5
#define MENOR 6
#define ENCONTROU 7

typedef struct nodo{
	void *data;
	int altura;
	struct nodo *esq,*dir;

	}*Nodo;


typedef struct sCont{

	int (*compare)  (void *,void*);
	int (*libertar) (void *);
	int (*imprime)  (void *);
	int sizeofData;
	Nodo root;
	} *Cont_avl;
	

/*Cria uma nova estrutura de controle de uma avl
Retorna OK OU NO_MEM*/	
	int new_ControlAvl(Cont_avl *nova,int (*compare)(void *,void *),int (*libertar)(void *), int (*imprime)(void*),int tamanho);
	
/*insere um elemento numa arvore
Retorna OK ou NO_MEM*/
int insertAVl(Cont_avl cont,Nodo *root,void *data);

/*funcao que cria um nodo da arvore
Retorna OK ou NO_MEM*/
int CriaNo (void *data,Nodo *root);

/*funcao que calcula a altura da arvore
Retorna a altura*/
int AlturArv(Nodo praiz);

/*balanceamento simple da arvore a direita
Retorna OK ou NO_INI*/
int ShiftRight (Nodo *pno);

/*balanceamento simple da arvore a esquerda
Retorna OK ou NO_INI*/
int ShiftLeft (Nodo *pno);

/*rotacao dupla a esquerda
Retorna OK ou NO_INI*/
int DoubleShiftLeft(Nodo *pno);

/*rotacao dupla a direita
Retorna Ok ou NO_INI*/
int DoubleShiftRight(Nodo *pno);

/*verifica se é preciso balancear e se for balanceia
Retorna OK ou NO_INI*/
int Balance (Nodo *root);

/*traversia das arvores em ordem
Retorna OK ou NO_INI*/
int  TraveOrder(Nodo root,int (*imprime)(void *));

/*liberta o espaco usado pelo nodo, a funcao libertar liberta a data especifica*/
void DestruirNo (Nodo *aux,int (*libertar)(void *));

/*substitui um nodo antes de libertar*/
int SubstituirNo(Nodo *root,void** data,int (*libertar)(void *));

/*verifica qual o tipo de arvore em que o no esta inserido para o libertar*/
int  RemoverNo (Nodo *root,int (*libertar)(void *));

/*remove um elemento da arvore*/		
int  RemoverElem(Cont_avl cont,Nodo *root,void *data,int (*compare)(void*,void*));

