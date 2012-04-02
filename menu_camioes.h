#pragma once
#include <stdio.h>
#include "aux.h"

/*pede a matricula de um camiao e guarda em matric*/
void scan_matricula(char *matric);

/*pede a localide original de um camiao e guarda em localidade*/
void scan_localidade(char *localidade);

/*pede o custo por KM de um camiao e guarda em cKM*/
void scan_custoKM(int *cKM);