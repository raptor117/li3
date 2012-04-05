#pragma once

#define OK 0 /*operacao realizada com sucesso*/
#define NO_MEM 1 /*nao consegue alocar memoria*/
#define NO_INI 2 /*uma estrutura nao foi inicializada*/
#define MAIOR 4
#define IGUAL 5
#define MENOR 6
#define NON_ER 9
#define NO_FILE 6
#define ENCONTROU 7
#define MAXS 100


#include "hash_ll.h"
#include "aux.h"
#include <stdio.h>
#include <string.h>

/*Estrutura de um um camiao*/
typedef struct scamiao {
	int ide;/*id interno*/
	char *matricula;/*matriclua do camiao,unico a cada camiao*/
	char *custokm;/*custo por km*/
	char *local;/*local onde se encontra actualmente*/
}*camiao;
/*estrutura de controlo dos camioes*/
typedef struct contCamioes {
	int ids;/*ultimo id atribuido*/
	Hash frota;/*Tabela de hash com todos os camioes*/
}*camioes;


/*Recebe um apotador para um camiao e eimprime a informacao deste.
 Retorna OK se consgue imprimir e NO_INI se o apontador estiver para NULL*/
int imprimeCam (void *a);

/*Recebe dois apontadores para dois camioes, e compara a sua matricula.
 Retorna IGUAL  ou OK consoante a matricula*/
int compareCam(void *a,void *b);


/*Recebe dois apontadores para dois camioes, e compara o seu cuso por km.
 Retorna MAIOR our MENOR*/
int compareCamCusto(void *a,void *b);

/*Recebe um apontador para um camiao e liberta a estrutura*/
int freeCamiao(void *a);

/*Recebe um apontador para um camiao e devolve o elemento que fhash vai usar,
 A funcao retorna ou o valor ou NO_INI caso o apontador estiver a nulo*/
char *keyCam(void *a);

/*Recebe a estrutura de controlo e o tamanho com que que deseja criar a hash.
 Retortna OK se conseguir alocar a nova estrutura e a hash ou NO_MEM se nao conseguir alocar algo */
int NovaFrota(camioes *frota,double ncam);

/*Funcao que recebe os parametros para criar um novo camiao e guarda em dest,
 Retorna OK se conseguir alocar e NO_MEM caso contrario*/
int NovoCamiao(camiao *dest,char *matricula,char *custo,char *local);

/*Recebe um camiao e uma estrutura de controlo e insere nessa estrutura de controlo 
 Retorna Ok ou NO_INI se algum dos argumentos estiver a NULL*/
int InsereCamiao(camiao cam,camioes *frta);

/*Recebe uma matricula, a localidade destino e  a  estrutura de controlo, 
e muda o camiao para o novo sitio, retorna Ok ou NO_INI se algum dos argumentos estiver a NULL*/
int mudarLocalidade(camioes frota,char *matricula,char *local);

/*procura o camiao com a matricula dada na estrutura de controlo,
  Retorna Ok ou NO_INI se algum dos argumentos estiver a NULL*/
int  searchCamiao (camioes frota,char *matricula,void ***elems,int *n);
	
/*remove um camiao da frota com a matricula dada
Retorna OK ou NO_INI ou NO_MEM*/
int removeCamiao(camioes frota,char *matricula);