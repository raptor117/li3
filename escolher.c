#include "menu.h"
#include "string.h"
#include "stdio.h"

int escolher(Menu *m){
    //system("clear");
	int i, option, op = m->nr_op;
    /* Imprime o titulo do menu */
    printf("\n\n -- %s --\n\n", m->option[0]);
    
    /* Percorre as opções dos menus e imprime-as no terminal */
    for(i=1; i<=op; i++) 
        printf("%d - %s\n\n", i, m->option[i]);


    /* Recebe a opção escolhida pelo utilizador */
    option = opcao(op);

    /* Valida a opção */
    if( option == -1 ) return escolher(m);
    return option ;
}

/* Lê um inteiro do teclado (usado nos menus) */
int opcao(int op){
    
	char *str = (char *)malloc(sizeof(char));
	
	printf ("escolher opcao ");
	scanf ("%s", str);
	
	int a = atoi(str);
	free(str);
	
    /* Verifica se o valor está entre o pretendido */
    if( a < 1  || a > op )
        return -1;
    

    /* Devolve o valor */
    return a;
}
