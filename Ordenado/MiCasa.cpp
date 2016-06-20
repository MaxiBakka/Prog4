
#include <iostream>

#include "UserInterface.h"
#include "MenuPrincipal.h"

using namespace std;

int main(){
	MenuPrincipal * menu = new MenuPrincipal();
	menu->ejecutar();

	delete menu;
	//probablemente se tenga que liberar mas memoria

}
