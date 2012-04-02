#pragma once
#include "camiao.h"
#include "cidades.h"
#include "cliente.h"

typedef struct sTrans{
	
	camioes cmz;
	ControlCid cidz;
	clientes cliez;
	}*Trans;


/*Cria um novo transitorio*/
unsigned int novo_transitorio(Trans *dest);
	