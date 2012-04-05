#include "graph.h"


int inicializa(int size,Graph *graph,int (*libertar)(void *),
 							int (*imprime)(void *),int  sizeofData,
								int switx(void*,void*), int getVal(void*)) {
	int valor=OK;
	int i=0;
	Graph g = (Graph)malloc(sizeof(struct sgraph));
	if(g==NULL){valor=NO_MEM;}
	else{	
			g->adj_list=(Aresta*) malloc(size*sizeof(Aresta));
			if(g->adj_list ==NULL){valor=NO_INI;free(g);}
			else{	
				g->size=size;
				g->sizeofData=sizeofData;
				g->libertar=libertar;
				g->imprime=imprime;
				g->switx=switx;
				g->getVal=getVal;
			
				/*percore os pertices pondo todos a null*/
				for(i=0;i<size;i++){
					g->adj_list[i]=NULL;}

					}
					
					*graph=g;
					
				}
	return valor;
}


int Cria_aresta(Aresta *destino,int dest, void *data){
	int valor =OK;
	Aresta nova=(Aresta) malloc(sizeof(struct sAresta));
	
	if(nova ==NULL){valor=NO_MEM;}
	else{
		nova->dest=dest;
		nova->data=data;
		nova->next=NULL;
		*destino=nova;
	}
	return valor; 
	
}



int add_lig(Graph *g, Aresta *root,void *data,int dest){
	int valor =OK;
	//printf("%p %p %d\n",*root,data,dest);
	if(*root==NULL){valor=Cria_aresta(root,dest,data);}/*se for null cria*/
	else{
		if((*root)->dest==dest){(*root)->data=data;}/*se for igual substitui a informacao*/
		else{valor =add_lig(g,&(*root)->next,data,dest);}/*passa ao proximo elemento*/
	}
	return valor;
}


int veCaminho(Graph g,int orig,int dest) {
	int i=0,valor=OK,enc=0;
	if(g==NULL ||g->adj_list ==NULL) {
		valor=NO_INI;
	} else {
		Aresta e;
		e=g->adj_list[orig];
		while (e && enc==0) {
			if(e->dest=dest) {
				printf("|origem:%d|destino:%d|\n",i,e->dest);
				g->imprime(e->data);
				enc=1;
			}
			e = e->next;
		}
	}
}
int visualiza(Graph g) {
	int i=0,valor=OK;
	if(g==NULL ||g->adj_list ==NULL) {
		valor=NO_INI;
	} else {
		
		Aresta e;
		
		for (i=0; i<g->size; i++) {
			e=g->adj_list[i];
			while (e) {
				printf("|origem:%d|destino:%d|\n",i,e->dest);
				g->imprime(e->data);
				e = e->next;
			}
		}
	}
	return valor;
}

/*percorre o grafo e remove as cidade que tem ligacao a uma cidade*/
int removeLigs(Graph *g,int dest){
	int i=0;
	int valor=OK;
	if(g==NULL || (*g)->adj_list ==NULL || dest>(*g)->size){valor =NO_INI;}
	else{
		for(i=0;i<(*g)->size;i++){
			valor=removeAresta(g,i,dest);
		}
		
	}
	return valor;
	
}

int removeAresta(Graph *g,int origem,int dest) {
	Aresta ant=NULL,actual=(*g)->adj_list[origem];
	int valor=OK,breack=0;
	if(g==NULL || (*g)->adj_list ==NULL || (*g)->adj_list[origem]==NULL) {
		valor=NO_INI;
	} else {
		while(actual!=NULL && breack==0) {
			if(actual->dest==dest) {
				if(ant==NULL) {
					(*g)->adj_list[origem]=actual->next;
					breack=1;
				}
				/*se for o primeiro elemento*/ else {
					ant->next=actual->next;
					breack=1;
				}
			} else {
				ant=actual;
				actual=actual->next;
			}
			/*printf("%d\n",actual->cost);*/
		}
		
		(*g)->libertar(actual->data);
		free(actual);
		actual=NULL;
	}
	return valor;
}

int mudarCusto(Graph *g,int origem,int dest,void *data) {
	int valor=OK,breack=0;
	Aresta actual;
	actual=(*g)->adj_list[origem];
	if(g ==NULL || (*g)->adj_list ==NULL) {
		valor=NO_INI;
	} else {
		while(actual!=NULL && breack==0) {
			if(actual->dest==dest) {
				valor=(*g)->switx(actual,data);
				breack=1;
			}
			actual=actual->next;
		}
	}
	return valor;
}



int removeEdge(Graph *g,int origem){
	
	int valor =OK;
	Aresta next=NULL,actual=(*g)->adj_list[origem];
	
	if(g==NULL || (*g)->adj_list == NULL|| actual ==NULL){valor=NO_INI;}
	else{
		
		
		while(actual !=NULL){
			next=actual->next;
			free(actual);
			(*g)->libertar(actual->data);
			actual=next;
			
		}
		free((*g)->adj_list[origem]);
		(*g)->adj_list[origem]=NULL;
		
	}
	
	return valor;	
}

	
	
int convertGraphtoMatrix(Graph *g,int **array) {
	int valor=OK;

	if(*g==NULL || (*g)->adj_list==NULL) {
		valor=NO_INI;
	} else {
		int i,j,k;
		Aresta e;
		for (j=0;j<(*g)->size;j++) {
			for (k=0;k<(*g)->size;k++) {
				array[j][k]=0;
			}
		}
		for (i=0;i<(*g)->size;i++) {
			e=(*g)->adj_list[i];			
			while(e!=NULL) {
			    
				array[i][e->dest]=(*g)->getVal(e->data);
			//	printf("%d\n",array[i][e->dest]);    
				
				e=e->next;
			}
		}
	}
	
	
	
	return 0;
}

int dijkstra(int s,Graph g,int **dist,int d[g->size]) {
	int valor =OK;
	if(g ==NULL) {
		valor =NO_INI;
	} else {
		int i, k, mini;
		int visited[g->size];
		int n=g->size;
		for (i = 0; i < n; ++i) {
			d[i] = 999999999;
			/*coloca o custo ao valor maximo */
			visited[i] = 0;
			/*coloca todos os visitados a 0*/
		}
		
		d[s] = 0;
		for (k = 0; k < n; ++k) {
			mini = -1;
			for (i = 0; i < n; ++i)
							if (!visited[i] && ((mini == -1) || (d[i] < d[mini]))) {
				mini = i;
			}
			visited[mini] = 1;
			for (i = 0; i < n; ++i) {
				if (dist[mini][i]) {
					if (d[mini] + dist[mini][i] < d[i]) {
						d[i] = d[mini] + dist[mini][i];
					}
				}
			}
		}
	
	}
	return valor;
}

int getMindist(int source,Graph *g,int d[(*g)->size]) {
	int valor=OK;
	int i=0;
	if(*g==NULL || (*g)->adj_list ==NULL) {
		valor=NO_INI;
	} else {
		if(source <0 || source >(*g)->size) {
			valor=NON_ER;
		} else {
			int ncolumns;
			int nrows=ncolumns=(*g)->size;
			//int array[(*g)->size][(*g)->size];
			int **array;
			array = malloc(nrows * sizeof(int *));
			if(array == NULL) {
				fprintf(stderr, "out of memory\n");
				valor=NO_MEM;
			}
			for (i = 0; i < nrows; i++) {
				array[i] = malloc(ncolumns * sizeof(int));
				if(array[i] == NULL) {
					fprintf(stderr, "out of memory\n");
					valor=NO_MEM;
									}
			}
			
			
			convertGraphtoMatrix(g,array);/*coloca o grafo na matrix custos*/
			dijkstra(source,*g,array,d);/*calcula os caminhos mais curtos*/
		for (i = 0; i < nrows; i++) {
		//printf("%d\n",d[i]);
                        free(array[i]);}
                    free(array);
		}
	}
	
	return valor;
}

int aumentaGraph(Graph g,int x){
	int valor =OK;
	if(g ==NULL || (g)->adj_list ==NULL){valor =NO_INI;}
	else{      
			(g)->adj_list=(Aresta*) realloc(g->adj_list,x*2*sizeof(Aresta));	
			(g)->size=x;		
			if(g->adj_list ==NULL){valor =NO_MEM;}
	}
	return valor;
}

int insere_lig(Graph *g,int origem,int destino,void *data){
	int valor=OK;
	if(origem > (*g)->size || destino >(*g)->size){
		if(origem>destino){valor=aumentaGraph(*g,origem);valor=add_lig(g,&(*g)->adj_list[origem],data,destino);}
		else{valor=aumentaGraph(*g,destino);valor=add_lig(g,&(*g)->adj_list[origem],data,destino);}
	       	}
			else{
			
			valor=add_lig(g,&(*g)->adj_list[origem],data,destino);
		}
		
		
		return valor;
}
