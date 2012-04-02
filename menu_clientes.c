#include "menu_clientes.h"
void head_Clientes(){
	
	printf("|---------------------------------------|\n");
	printf("|            Menu Cliente               |\n");
	printf("|---------------------------------------|\n");
	printf("| 1-Ver todos os clientes               |\n");
	printf("| 2-Procurar cliente por nome           |\n");
	printf("| 3-Procurar cliente por contribuinte   |\n");
	printf("| 4-Ver movimentos de cliente           |\n");
	printf("| 5-Cliente mais importarnte            |\n");
	printf("| 6-Voltar ao menu principal            |\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("\n");
	
	
}


void scan_Nome(char *nome){
	printf("Introduza o nome do cliente: ");
	fgets(nome,MAXS,stdin);
    fixString(nome,MAXS);
	
}

void scan_contrib(int *contrib){
	
	printf("Introduza o numero de contribuinte do cliente: ");
	scanf("%d",contrib);
}