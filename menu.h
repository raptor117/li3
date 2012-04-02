#pragma once
#include "menu_clientes.h"
#include "menu_cidades.h"
#include "menu_camioes.h"
#include "Transitorio.h"
#include <Stdio.h>
#include <stdlib.h>
#include <String.h>


typedef struct sMenu{
	
	int nr_op;
	char *option[];
	
} Menu;

static Menu start = {
	4,
	{"Menu Principal",
	"Menu Camiões", 
	"Menu Cidades",	
	"Menu Clientes",
	"Sair"}
};

static Menu truck = {
	6,
	{"Menu Camiões",
	"Inserir",
	"Remover",
	"Editar",	
	"Ver todos", 
	"Pesquisar",
	"Voltar ao Menu Principal"}
};

static Menu citys = {
	13,
	{"Menu Cidades",
	"Inserir Caminho",
	"Inserir Cidade",
	"Remover Caminho",
	"Editar Caminho",
	"Remover Cidade",
	"Editar Cidade",	
	"Ver todas as cidades ", 
	"Pesquisar Caminho",
	"Pesquisar Cidade",
	"Localidade mais requisitada",
	"Localidade menos requisitada",
	"Clientes que solicitam entregas em determinada localidade",	
	"Voltar ao Menu Principal"}
};

static Menu clients = {
	9,
	{"Menu Cliente",
	"Inserir",
	"Editar dados",	
	"Ver todos", 
	"Procurar cliente por nome",     
	"Procurar cliente por contribuinte",  
	"Ver movimentos",           
	"Cliente mais importante",
	"Realizar Encomenda",
	"Voltar ao menu principal"}
};

void logo();

/*recebe um transitorio e parte para o menu escolhido*/
void menu(Trans transitorio);

/*menu com as opcoes dos camioes*/
void menu_cam(Trans transitorio);

/*menu com as opcoes das localidades*/
void menu_loc(Trans transitorio);

/*menu com as opcoes dos clientes*/
void menu_cli(Trans transitorio);
