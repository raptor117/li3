#pragma once
#include <stdlib.h>
#include <stdio.h>

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/
#define CARGA 3/*a carga da hashtable foi atingida*/
#define IGUAL 5
#define ENCONTROU 7

/*nodo de uma lista ligada*/
typedef struct sNodo{
	void *data;
	struct sNodo *next;
}*Nodo_ll;

	
/*estrutura de dados de controlo da tabela hash*/	
typedef struct hash{

	char *(*key) (void*);/*funcao que devolve o elemento que vai gerar a chave*/
	int sizeofData;/*tamanho dos dados usados nesta estrutura*/
	int (*cmp) (void*, void*);/*funcao de comparacao*/
	int (*remove_data) (void*);/*funcao de remover data*/
	int (*print) (void*);/*funcao de imprimir data*/
	double tsize;/*tamanho do array*/
	double nnodo;/*numero de nodos inseridos*/
	Nodo_ll *tabela;/*tabela de has*/
	
} *Hash;


/*Insere um elemento na Hash em que a key é um int*/
int Insere_Hash(Hash *hash,void *data);

/*igual a funcao anterior mas usa o HashI em vez de HashS*/
void InsereElems (Nodo_ll antigo,Hash *nova);

/*funcao que pega num inteiro e devolve um valor para a hashtable,
se usar strings devolva o tamanho das strings*/
int fHash (char * k,int tsize);

/*Cria um nodo de uma lista,
Retorna OK ou NO_MEM */
int CriaNodo(Nodo_ll *novo,void *data);


/*funcao que cria e e inicia uma tabela de hash*/
int NovaHash(int tsize,Hash *hash,int  (*compare)(void *,void*),
int  (*libertar)(void *),int  (*imprime)(void *),char *(*key) (void*));


/*insere um elemento num nodo, se quisermos que substituia um elemento igaul
a funcao compare deve retornar igual, caso nao retorne a funcao coloca um 
elemento com os dados repetidos
Retorna Ok ou NO_INI ou NO_MEM*/
int insertNodo(Hash cont,Nodo_ll *head,void *data);

/*imprime todos os elementos da hash*/
int imprimetab(Hash hash);

/*Liberta a hash e todos os seus elementos
Retorna OK ou NO_INI*/
int HashDestroy(Hash *pst);

/*Remove um elemento da hash
Retorna OK ou NO_INI*/
int remove_hash(Hash *ptr, void *data);
/*danos o numero de elementos no argumento n, sao iguais a data passada
Retorna OK ou NO_INI*/
int nElems(Nodo_ll k,void *data,int *n,	int (*cmp) (void*, void*));

/*Esta funcao recebe pega no data passado e  procura na hash os elementos iguas a este e 
guarda o apontadores para este num array que tambem e passado, o tamnho do array e guardado no argumento n
e é calculado pela funcao anterior
Retorna OK e NO_INI*/
int getElems(Hash hash,void *data, void ***elems,int *n,int (*cmp) (void*, void*));

