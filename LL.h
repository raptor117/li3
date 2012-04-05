#pragma once
#include <stdlib.h>
#include <stdio.h>

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/
#define MAIOR 4
#define IGUAL 5
#define MENOR 6
#define ENCONTROU 7 
#define NO_HEAD 10 


/*nodo de uma lista ligada*/
typedef struct sLL{
	void *data;
	struct sLL *next;
}*LL;

/*estrutura de controlo da lista ligada*/
typedef struct sGLL{
	int (*ll_cmp) (void*, void*);/*funcao de comparacao*/
	int (*remove_data) (void*);/*funcao de remover data*/
	int (*print) (void*);/*funcao de imprimir data*/
   	int ocupado;
	LL root;
}*genLL;

/*funcao que inicia a estrutura de controlo,
Retorna OK ou NO_MEM ou NO_INI*/
int init_ll(genLL *nova,int (*ll_cmp) (void*, void*), int (*remove_data) (void*),
	int (*print) (void*));
/*Funcao que cria um elemento dda lista
Retorna OK ou NO_MEM*/
int Cria_elem(LL *novo,void *data);

/*Funcao de insercao de um elemento  na LL,mas subsititui os lementos repetidos
retorna OK ou NO_MEM ou NO_INI*/
int insert_LL_s(genLL cont,LL *head,void *data);

/*Funcao de insercao de um elemento  na LL,nao substitui e eacrescenta na lista
retorna OK ou NO_MEM ou NO_INI*/
int insert_LL(genLL cont,LL *head,void *data);

/*Funcao que vai buscar a informacao igual a data
Retorna  OK e NO_INI*/
int get_ll(genLL ptr, void **data);
/*Remove um elemento da LL,
Retorna OK,NO_INI*/
int remove_ll(genLL ptr, void *data);

/*Destroy a ll toda
Retorna  OK ou NO_INI*/
int LLDestroy(genLL *ptr);
