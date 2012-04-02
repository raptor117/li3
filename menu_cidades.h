#pragma once
#include <stdio.h>
#include "aux.h"

/*mostra as opcoes das localidades*/
void head_Localidades();
/*pede o nome de uma cidade e guarda em nome*/
void scan_cidade(char *nome);
/*pede o distancia entre duas cidades e guarda em custo*/
void scan_dist(int *custo);