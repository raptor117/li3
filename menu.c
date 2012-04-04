#include "menu.h"

void logo(){
	
	printf(" ______________________________________ \n");
	printf("|                                      |\n");
	printf("|            Transitários LEI          |\n");
	printf("|______________________________________|\n");
		
}

void menu_cli(Trans transitorio){
    int opcao;
    unsigned int contrib;
	char ident[MAXS];
	do{
        system("clear");
		
        opcao = escolher(&clients);
        
        
        if( opcao == 1){
            /* inserir */
        }else if( opcao == 2){
			/* editar */
			
			
        }else if( opcao == 3){
            /* veer todos */
			//imprimetab(cls->nomes);
			
        }else if( opcao == 4){
			/*printf("Introduza o nome do cliente: ");
			scanf("%s",ident);
			printf("\n");
			searchNome(cls,ident);*/
			
		}else if( opcao == 5){
			/*printf("Introduza o numero de contribuinte do cliente: ");
			scanf("%d",&contrib);
			printf("\n");
			procuraContrib(cls,contrib);*/
			
		}else if( opcao == 6){
			//verMovimento(cls);
			
		}else if( opcao == 7){
			/* cliente mais importante */
			
		}else if (opcao == 8) {
			/* encomendas */
		}	
		
		system("clear"); 
        /* Este ciclo é terminado quando o utilizador escolha a opção 9 */
    }while(opcao != 9);
}

void menu_loc(Trans transitorio){
	int opcao,km,custo,valor;
	char origem[MAXS],destino[MAXS];
    
	do{
		
        opcao = escolher(&citys);
        
        
        if( opcao == 1){
			scan_cidade_origem(origem);
			scan_cidade_destino(destino);
			scan_dist(&km);
			scan_custo(&custo);
			valor=insereCaminho(transitorio->cidz,origem,destino,km,custo);
			if(valor==OK){printf("Caminho inserido\n");}
			else{printf("Caminho nao inserido,verifique se os dados esta correctos\n");}
           
        }else if( opcao == 2){
			scan_cidade_origem(origem);printf("x%sx",origem);
			Cidade novo;
			novaCidade(&novo,origem);
			valor=insereCidade(novo,&transitorio->cidz);
			if(valor==OK){printf("Cidade inserida\n");}
			else{printf("Cidade nao inserida,verifique se os dados esta correctos\n");}
		
			
        }else if( opcao == 3){
			scan_cidade_origem(origem);
			scan_cidade_destino(destino);
			scan_dist(&km);
			scan_custo(&custo);
			valor=mudarCustoCid(transitorio->cidz,origem,destino,km,custo);
			if(valor==OK){printf("Custo mudado\n");}
			else{printf("Custo nao mudado,verifique se os dados esta correctos\n");}
			
			
            
			
        }else if( opcao == 4){
			scan_cidade_origem(origem);
			valor=removerCidade(transitorio->cidz,origem);
			if(valor==OK){printf("Cidade removida\n");}
			else{printf("Cidade nao removida,verifique se os dados esta correctos\n");}
			
			
			
		}else if( opcao == 5){
			imprimetab(transitorio->cidz->cidades);
				
		}else if( opcao == 6){
			scan_cidade_origem(origem);
			scan_cidade_origem(destino);
			vePath(transitorio->cidz,origem,destino);
			
		}else if( opcao == 7){
			void **data;
			int l;
			scan_cidade_origem(origem);
			//printf("%s",origem);
			valor=searchCity(transitorio->cidz,origem,&data,&l);
			if(valor ==OK && l ==1){
				imprimeCid(data[0]);
			}

			
		}else if( opcao == 8){
			
			
	    }else if( opcao == 9){
			/* Localidade mais requisitada */
			
		}else if( opcao == 10){
			/* Localidade menos requisitada */
		}	//	system("clear"); 
	}while(opcao != 13);
}
	
/*as coisas do menu estao a funcionar, retirar editar e o ciclo escaxa*/	
void menu_cam(Trans transitorio){
		int opcao,valor;
		char matricula[MAXS],local[MAXS],custo[MAXS];
		void **data;
		int n;
		
		
		do{
			
			opcao = escolher(&truck);
			
			
			if( opcao == 1){
				scan_matricula(matricula);
				printf("\n");
				scan_localidade(local);
				printf("\n");
				scan_custoKM(custo);
				camiao novo;
				NovoCamiao(&novo,matricula,custo,local);
				valor=InsereCamiao(novo,&(transitorio->cmz));
				if(valor ==OK){printf("Camiao Inserido\n");}
				else{printf("Camiao nao Inserido,verifique se introduziu os dados correctos\n");}
				
			}else if( opcao == 2){
				scan_matricula(matricula);
				printf("\n");
				valor=removeCamiao(transitorio->cmz,matricula);
				if(valor ==OK){printf("Camiao removido\n");}
				else{printf("Erro,certefique-se que a matricula esta correcta\n");}
				
				
				
			}else if( opcao == 4){
				imprimetab(transitorio->cmz->frota);
				
			}else if( opcao == 5){
						scan_matricula(matricula);
						printf("\n");
						searchCamiao(transitorio->cmz,matricula,&data,&n);
						if(n==1){imprimeCam(data[0]);}
						else{printf("Erro,certefique-se que a matricula esta correcta\n");}
				
				
				
			}
		//	system("clear"); 
			/* Este ciclo é terminado quando o utilizador escolha a opção 6 */
		}while(opcao != 5);
	}
	
void menu(Trans transitorio) {
	int opcao=0,origem,destino,custo;
	char cid[MAXS];
	system("clear");
	logo();
	while(opcao !=4){
	opcao = escolher(&start);
	
		if( opcao == 1) {menu_cam(transitorio);}
			else {
			if( opcao == 2) {menu_loc(transitorio);} 
			else{
				if( opcao == 3) {menu_cli(transitorio);}
				}
			}
		}
			
		system("clear");
		logo();
		
}



