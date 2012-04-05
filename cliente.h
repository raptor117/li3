#pragma once

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/
#define NON_ER 9
#define IGUAL 5
#define NO_FILE 6
#define ENCONTROU 7
#define MAXS 100

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "aux.h"
#include "hash_ll.h"
#include "stack.h"



/*Estrutura de um cliente*/
typedef struct scliente{
	
	char *nome;
	char *morada;
	char *email;
	char *cnb;/*numero de contribuinte*/
	int ide; /*id interno*/
	int total;/*dinheiro total gasto pelo cliente*/
	Stack servicos;/*stack de todos os servicos*/
}*cliente;
 
/*estrutura de controlo  das cidades*/	
typedef struct cliente_cont{
	int ids; /*ultimo id usado*/
	int idc;/*contribuinte do cliente mais importante*/
	int tuts;/*o total que o cliente maximo gastou*/
	Hash nomes; /*tabela organizada por nomes*/
	Hash contrib;/*tabela organizada por contribuinte*/
	
}*clientes;
	

/*compara os clientes atraves do nome e é usada pela funcao de hash para inserir os 
elementos
Retorna OK,NO_IN,MENOR ou MAIOR*/	
int cmplN(void* a,void* b);	

/*funcao que compara os clientes é diferente da primeira porque devolve 
 IGUAL quando encontra um elemento com o mesmo nome*/
int cmplN2(void* a,void* b);

/*Compara os clientes atraves do numero de contribuinte, e usada na hash contrib
Retorna  NO_INI,MENOR,IGUAL OU MAIRO*/
int cmplC(void* aa,void* bb);


/*liberta a estrutura de cliente
Retorna OK ou NO_INI*/
int libcl(void *a);

/*liberta um servico
Retorna OK ou NO_INI*/
int libserv(void *a);

/*retorna o elemento pela qual a ashe se organiza neste caso o tamanho da string
Retorna OK, NO_INI ou o tamanho da string*/
char *keyN(void *elem);


/*retorna o elemento pela qual a ashe se organiza neste caso o numero de contribuinte
Retorna OK, NO_INI ou o tamanho da string*/
char *keyC(void *elem);


/*imprime um servico utilizado pelo cliente
Retorna OK ou NO_INI*/
int impmov(void *a);

/*imprime a informacao de um cliente
Retorna OK ou NO_INI*/
int impcl(void *a);

/*cria uma nova estrutura de controlo de clientes, e aloca o espaco necesario
Retorna OK ou NO_MEM*/
int novoContClie(clientes *cls);

/*
Procura cliente por numero contribuinte
Retorna OK ou NO_INI;
*/
int procuraContrib(clientes c,char *contrib,void ***elems,int *n);

/*Cria um novo cliente com os dados inseridos
Retorna OK,NO_INI ou NO_MEM*/
int novoCliente(cliente *dest,char *nome,char *morada,char *email,char *contribuinte);

/*insere o apontador do cliente nas duas tabelas de hash 
Retorna OK, NO_MEM ou NO_INI*/
int insereCliente(cliente novo,clientes *cls);


/*Regista um servico de um cliente
Retorna OK oi NO_INI ou NO_MEM ou ENCONTROU*/
int registaMovimento(clientes cls,char *contrib,int *valor);

/*mostra o ultimo servico realidade pelo cliente
Retorna OK, NO_INI ou ENCONTROU*/
int verMovimento(clientes c,int contrib);

/*procura e mostra os clientes com aquele nome
Retorna OK ou NO_INI*/
int searchNome(clientes cls,char *nome);

/*funcao que recebe o contribuinte de um cliente e o remove da hash
Retorna OK ou NO_INI*/
int removerCliente(clientes cls,int contribuinte);

