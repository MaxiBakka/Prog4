

#include "Menu.h"
#include "UserInterface.h"
#include "ExOpcionInvalida.h"
#include "MenuUtils.h"
#include <iostream>

using namespace std;

Menu::Menu() {
	this->salir = false;
}

void Menu::leerOpcion(){
	cout << "Seleccione una opcion:" << endl;
	int opc = MenuUtils::leerInt();
	MenuUtils::limpiarConsola();
	ejecutarOpcion(opc);
}

void Menu::ejecutar(){
	bool errorIngreso = false;
	while(true){
		try{
			MenuUtils::limpiarConsola();
			presentar();
			if (errorIngreso) {
				cout << "Opcion inválida. Intente nuevamente."<< endl;
				errorIngreso = false;
			}
			leerOpcion();
		}catch(ExOpcionInvalida &e){
			errorIngreso = true;
		}
		if (salir) break;
	}
}

void Menu::salirDelSistema(){
	salir = true;
}


Menu::~Menu() {
}

