#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "leitura.h"
#include "camiao.h"
#include "Transitorio.h"

int user(char *ln, Trans transitorio)
{
	
	
	int i = 0,j=0, cont, serv[500], id;
	
	char *aux, *nome,*morada, *aux_serv;
	
	
	aux= strtok(ln, "\t");
	while (aux != NULL ) {
		if (i== 0) {
			id =  atoi(aux);
		}
		else if (i==1) {
			nome = strdup(aux);
		}
		else if (i==2){
			
			morada = strdup(aux);
		}
		else if (i==3){
			int a= atoi(aux);
			cont = a;
			
		}
		else {
			aux_serv= strtok(aux, ",");
			while (aux_serv != NULL) {

				serv[j] = atoi(aux_serv); 
				//printf("%d\n", serv[j]);
				j++;

				aux_serv = strtok(NULL, ",");
			}
			serv[j] = '\0';
			
		}

		i++;
		aux = strtok(NULL, "\t");
		
	}
	/*printf("%d - ", id);
	printf("%s - ", nome);
	printf("%s - ", morada);
	printf("%d - ", cont);
	for (i=0; i<j; i++) {
		printf("%d ,", serv[i]);
	}
	printf("\n");
	*/
	
	cliente c;
	novoContClie(c);
	novoCliente(&c,nome,morada,cont);
	insereCliente(c,&(transitorio->cliez));
	//imprimetab(transitorio->cliez);
	
	
	return 1;
	
}

int load_user (Trans transitorio) {
	
	
	FILE *fl = fopen("DadosTeste/user.txt", "r");
	
	
	char ln[200];
	char a=0;
	int i =0;

	
	
	if (fl) {
		do {
			i=0;
			a=fgetc(fl);
			do{
				ln[i]=a;
				a=fgetc(fl);
				i++;
			}
		
			while(a!= '\n' &&  a!=EOF);
			ln[i] = '\0';
			user(ln, transitorio);

		} 
		while (a!=EOF);
	}
	else {
		printf("não existe");
	}
	fclose(fl);
	return 1;

}

int cam(char *ln, Trans transitorio)
{
	
	
	int i = 0, custokm, id;
	
	char *aux, *matricula,*cidade;
	
	
	aux= strtok(ln, "\t");
	while (aux != NULL ) {
		if (i== 0) {
			id =  atoi(aux);
		}
		else if (i==1) {
			matricula = strdup(aux);
		}
		else if (i==2){
			
			custokm = atoi(aux);
		}
		else if (i==3){
			cidade = strdup(aux);
			
		}
		
		i++;
		aux = strtok(NULL, "\t");
		
	}
	
	camiao novo;
	NovoCamiao(&novo,matricula,custokm,cidade);
	//printf("%s", novo->matricula);
	//printf("%d ", )
    InsereCamiao(novo,&(transitorio->cmz));
	
	
	//printf("%d - ", id);
	//printf("%s - ", matricula);
	//printf("%d - ", custokm);
	//printf("%s - \n", cidade);
	
	
	return 1;
	
}


int load_camiao (Trans transitorio)
{
	FILE *fl = fopen("DadosTeste/camioes.txt", "r");
	
	
	char ln[200];
	char a=0;
	int i =0;
	
	
	
	if (fl) {
		do {
			i=0;
			a=fgetc(fl);
			do{
				ln[i]=a;
				a=fgetc(fl);
				i++;
			}
			
			while(a!= '\n' &&  a!=EOF);
			ln[i] = '\0';
			cam(ln, transitorio);
			
		} 
		while (a!=EOF);
	}
	
	else {
		printf("não existe");
	}
	fclose(fl);

	return 1;
	
}

int save_cam(Trans transitorio){

    /* Abre o ficheiro para escrita */
    FILE *fw = fopen("DadosTeste/camioes.txt", "a");
    if(!fw){
        /* Se o ficheiro não pode ser escrito */
		printf("falha");
		return;
    }
    

    /* Percorre a tabela de hash guardando cada nodo numa linha do ficheiro */
	fprintf(fw, "%d \t %s \t %d \t %s \n", 6, "01-02-03", 4, "famalicao");

    fclose(fw);

	return 1;
}

int save_user(Trans transitorio){
	
    /* Abre o ficheiro para escrita */
    FILE *fw = fopen("DadosTeste/user.txt", "a");
    if(!fw){
        /* Se o ficheiro não pode ser escrito */
		printf("falha");
		return;
    }
    
	
    /* Percorre a tabela de hash guardando cada nodo numa linha do ficheiro */
	//fprintf(fw, "%d \t %s \t %d \t %s \n", 6, "01-02-03", 4, "famalicao");
	
    fclose(fw);
	
	return 1;
}

