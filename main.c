#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "Transitorio.h"


int main() {
	Trans trans;

	novo_transitorio(&trans);
	loadData(&trans);
	//atribCity(trans);	
	menu(trans);
	
	return 1;

}

