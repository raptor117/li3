#include "menu_cidades.h"

void head_Localidades(){
	
	printf("|---------------------------------------|\n");
	printf("|            Menu cidades               |\n");
	printf("|---------------------------------------|\n");
	printf("| 1-Ver todas as cidades                |\n");
	printf("| 2-Procurar cidade                     |\n");
	printf("| 3-Criar caminho                       |\n");
	printf("| 4-Remover caminho                     |\n");
	printf("| 5-Alterar custo do caminho            |\n");
	printf("| 6-Inserir localidade                  |\n");
	printf("| 7-Remover localidade                  |\n");
	printf("| 8-Voltar ao menu principal            |\n");
	printf("|---------------------------------------|\n");
	printf("|---------------------------------------|\n");
	printf("\n");
	
	
}


void scan_cidade_origem(char *nome){
		fflushstdin();
		printf("Introduza o nome da cidade origem: ");
		fgets(nome,MAXS,stdin);
}


void scan_cidade_destino(char *nome){
		fflushstdin();
		printf("Introduza o nome da cidade destino: ");
		fgets(nome,MAXS,stdin);
}

void scan_dist(int *km){
	
		printf("\nIntroduza a distancia entre as cidades: ");
		scanf("%d",km);
}


void scan_custo(int *custo){
	
		printf("\nIntroduza a custo entre as cidades: ");
		scanf("%d",custo);
}