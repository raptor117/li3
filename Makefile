cc = gcc

transitorio: aux.c camiao.c cidades.c cliente.c graph.c hash.c menu_camioes.c menu_cidades.c menu_clientes.c menu.c stack.c main.c Transitorio.c escolher.c LL.c
		$(cc) $(CFLAGS) aux.c camiao.c cidades.c cliente.c graph.c hash.c menu_camioes.c menu_cidades.c menu_clientes.c menu.c stack.c main.c Transitorio.c escolher.c LL.c
	
