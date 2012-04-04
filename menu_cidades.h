#pragma once
#include <stdio.h>
#include "aux.h"

/*mostra as opcoes das localidades*/
void head_Localidades();
/*pede o nome da cidade origem e guarda em nome*/
void scan_cidade_origem(char *nome);

/*pede o nome da cidade destino e guarda em nome*/
void scan_cidade_destino(char *nome);

/*pede o distancia entre duas cidades e guarda em  km*/
void scan_dist(int *km);

/*pede o custo entre duas cidades e guarda em  km*/
void scan_custo(int *custo);

