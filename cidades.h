#pragma once

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/
#define IGUAL 5
#define ENCONTROU 7
#define NO_CID 8
#define NON_ER 9
#define MAXS 100


#include "aux.h"
#include "hash_ll.h"
#include "graph.h"
#include "camiao.h"
#include <stdio.h>
#include <stdlib.h>
#include "LL.h"

/*estrutura de um cidade*/
typedef struct scidade{
   
    int ide;/*id privado do camiao*/
    char *nome;/*nome da cidade*/
	int nacedidas;/*numero de vezes que a cidade foi acedida*/
    //genLL  *camioes;/*todos os camioes na cidade*/
   
    }*Cidade;

/*estrutura de uma ligacao entre cidades*/
typedef struct sCustos{
	
	//char *tipo_transp;/*nome do transporte*/
	int km;
	int custo;/*custo de usar o tranporte*/
	//struct sCustos *prox;/*proxo transporte neste caminho*/
	
}*Custos;

/*estrutura de controlo da cidade*/
typedef struct cidadeControl{
   
    int ids;/*ultimo id usado*/
	Cidade mais_aced[10];
	Cidade mennos_aced[10];
    Hash cidades;/*tabela de hash com as cidades*/
    Graph ligacoes;/*grapho com as ligacoes entre as cidades*/
   
    }*ControlCid;

/*Danos o custo de um tranporte*/
int getCustotrans(void *a);


/*Funcao para alterar os custos num nodo ja existente. 
Substitui o custo de a pelo custo de b.
Devolve valor OK ou NO_INI.
*/
int switx(void *a,void *b);

/*Funcao que compara as cidades em relação ao nome,assumimos que nao existe duas cidades
diferenetes mas com o mesmo nome
Retorna Menor,Maior ou Igual
*/
int compareCid(void *a,void *b);

/*Liberta o nodo de uma cidade
Retorna OK ou NO_INI
*/
int freeCid(void *a);

/*Liberta o nó de uma ligacao
Retorna OK ou NO_INI*/
int  freeLig(void *a);

/*Da nos o ID de uma cidade para o apontador de inteiro que damos
Retorna OK ou NO_INI*/
int getIDcid(ControlCid cids,char *nome,int *id);

/*Imprime o Id da cidade e o seu Nome
Devolve  OK ou NO_INI*/
int imprimeCid (void *a);

/*Imprime o tipo de transporte e o seu custo
Devolve  OK ou NO_INI*/
int imprimeTransp(void *a);

/*
Devolve o elemento chave usado na funcao de hash neste caso o tamanho da string inserida
*/
char *keyCidade(void *elem);

/*
Cria uma nova estrutra de controlo de cidades, onde aloca o espaco das estruturas 
Retorna OK ou NO_MEM
*/
int novoContCid(ControlCid *cntcid,int nCidades);	

/*
Aloca o espaco para uma nova cidade e guarda o nome desta
Retorna NO_MEM ou OK
*/
int novaCidade(Cidade *dest, char *nome);

/*
Insere uma nova cidade na hash table, e da um Id a cidade
Retorna OK ou NO_INI
*/
int insereCidade(Cidade cid,ControlCid *cids);

/*Diz nos se uma cidade existe ou nao
Retorna OK,NO_INI ou ENCONTROU*/
int existeCidade(ControlCid cids, char *nome);

/*Procura o id da cidade com o nome dado e se encontrar guarda em id
Retorna OK, NO_INI*/
int getIDcid(ControlCid cids,char *nome,int *id);

/*
Procura uma cidade e coloca em elems
Retorna OK, NO_INI e ENCONTROU
*/
int searchCity(ControlCid cids,char *nome,void ***elsems,int *n);

/*
Cria um caminho entre duas localidades, temos que indicar a distancia e o nome do transporte
Retorna OK, NO_INI e NO_CID
*/
int insereCaminho(ControlCid cids,char *orig,char *dest,int km,int custo);
/*
Remove o caminho entre dois locais
Devolve OK, ou NO_INI
*/
int removerCaminho(ControlCid cids,int ido,int idd);

/*
Muda o custo de um caminho entre duas cidades,
Retorna o valor OK,NO_INI ou NO_CID 
*/
int mudarCustoCid(ControlCid cids,char *orig,char *dest, int custo,int km);

/*
Remove uma cidade da tabela de hash e poem o apontador do grafo a NULL
Retorna OK,NO_INI ou NO_CID 
*/
int removerCidade(ControlCid cids,char *nome);

