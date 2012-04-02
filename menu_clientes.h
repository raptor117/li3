#pragma once
#include <stdio.h>
#include "aux.h"

/*mostra as opcoes dos clientes*/
void head_Clientes();
/*pede o nome de um cliente e guarda em nome*/
void scan_Nome(char *nome);
/*pede o contribuinte de um cliente e guarda em custo*/
void scan_contrib(int *custo);