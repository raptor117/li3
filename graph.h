#pragma once
#include <stdio.h>
#include <stdlib.h>

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/
#define MAIOR 4
#define IGUAL 5
#define MENOR 6
#define ENCONTROU 7
#define NON_ER 9/*Erro geral*/

/*Aresta de um grafo*/
typedef struct sAresta {
   	struct sAresta *next;
    int dest;
    void *data;
} *Aresta;


/*estrutura de controlo de um grafo*/
typedef struct sgraph {
	int size;
	int (*libertar)(void *);/*funcao de libertar a data*/
	int (*imprime)(void *);/*funcao que imprime a data*/
	int (*switx)(void*,void*);/*funcao que troca a data por outra*/
 	int (*getVal)(void*);/*funcao que devolve o valor  de custo em data*/
	int sizeofData;
    Aresta *adj_list;
} *Graph;



/*funcao que inicializa  a estrutura de controlo do grafo
Retorna OK,NO_MEM ou NO_INI*/
int inicializa(int size,Graph *graph,int (*libertar)(void *),
 							int (*imprime)(void *),int  sizeofData,
							int switx(void*,void*), int getVal(void*));
							

/*Funcao que cria uma aresta do grafo
Retorna OK ou NO_MEM*/							
int Cria_aresta(Aresta *destino,int dest, void *data);

/*Adiciona uma nova ligacao na aresta root
Retorna OK  OU NO _MEM*/
int add_lig(Graph *g, Aresta *root,void*data,int dest);

/*mostra todas as ligacoes do grafo, imprime a origme e o destino 
Retorna OK ou NO_INI*/
int visualiza(Graph g);

/*Remove a aresta entre origem e dest
Retorna OK ou NO_INI*/
int removeAresta(Graph *g,int origem,int dest);

/*Muda a data entre origem e dest
Retorna OK ou NO_INI;*/
int mudarCusto(Graph *g,int origem,int dest,void *data);

/*Remove um vertice do grafico
Retorna OK ou NO_INI*/
int removeEdge(Graph *g,int origem);

/*Converte o grafo que numa matrix em que tem os custos 
REtorna Ok ou NO_INI*/
int convertGraphtoMatrix(Graph *g,int array[(*g)->size][(*g)->size]);

/*Pega numa matriz calculada pela funcao anterior e menor distancia de s a todos 
os outros pontos no array d
Retorna OK ou NO_INI*/
int dijkstra(int s,Graph g,int dist[g->size][g->size],int d[g->size]);

/*Esta funcao utiliza as duas ultimas funcoes acima para calcula o camino mais curto entre s
a todos os outros nodos
Retorna OK ,NO_INI ou NON_ER*/
int getMindist(int source,Graph *g,int d[(*g)->size]);


/*Funcao que aumeta o array do Graph para  x
Retorna OK ou NO_INI ou NO_MEM*/
int aumentaGraph(Graph g,int x);

/*funcao que deve ser usada para colocar uma ligacao nova pois , verifica se pode fazer,
e se tem espaco sufeciente e se puder usa a funcao add_lig
Retorna OK ou NO_INI ou NO_MEM*/
int insere_lig(Graph *g,int origem,int destino,void *data);
