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
    int opcao,origem,destino,custo;
	char cid[MAXS];
    
	do{
		
        opcao = escolher(&citys);
        
        
        if( opcao == 1){
           
        }else if( opcao == 2){
		
			
        }else if( opcao == 3){
            
			
        }else if( opcao == 4){
			
			
		}else if( opcao == 5){
			
			
		}else if( opcao == 6){
			/* editar cidade */
			
		}else if( opcao == 7){
			//imprimetab(cids->cidades);
			
		}else if( opcao == 8){
			/* pesquisar caminho */
			
		}else if( opcao == 9){
			
			
	    }else if( opcao == 10){
			/* Localidade mais requisitada */
			
		}else if( opcao == 12){
			/* Localidade menos requisitada */
		}		system("clear"); 
	}while(opcao != 13);
}
	
	
void menu_cam(Trans transitorio){
		int opcao,ckm;
		char matricula[MAXS];
		char local[MAXS];
		
		
		do{
			
			opcao = escolher(&truck);
			
			
			if( opcao == 1){
			/*	scan_matricula(matricula);
				printf("\n");
				scan_localidade(local);
				printf("\n");
				scan_custoKM(&ckm);
				camiao novo;
				NovoCamiao(&novo,matricula,ckm,local);
				InsereCamiao(novo,&(transitorio->cmz));*/
				
			}else if( opcao == 2){
			/*	scan_matricula(matricula);
				printf("\n");
				removeCamiao(transitorio->cmz,matricula);*/
				
				
			}else if( opcao == 3){
				/* editar */
				
			}else if( opcao == 4){
				//imprimetab(transitorio->cmz->frota);
				//imprimetab(transitorio->cmz->frota);
				
				
			}else if( opcao == 5){
				/*pesquisar camiao				*/
			}
		//	system("clear"); 
			/* Este ciclo é terminado quando o utilizador escolha a opção 6 */
		}while(opcao != 6);
	}
	
void menu(Trans transitorio){
	int opcao,origem,destino,custo;
	char cid[MAXS];
	system("clear");
	logo();
	do{
		
		opcao = escolher(&start);
					
		if( opcao == 1){
			menu_cam(transitorio);
		}else if( opcao == 2){
			menu_loc(transitorio);
		}else if( opcao == 3){
			menu_cli(transitorio);
		}
		system("clear");
		logo();/* Este ciclo é terminado quando o utilizador escolha a opção 4 */
	}while(opcao != 4);
}
	




