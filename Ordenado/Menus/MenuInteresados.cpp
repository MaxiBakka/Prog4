
#include <iostream>
#include <string>
#include "MenuIntersados.h"
#include "ExOpcionInvalida.h"

using namespace std;
MenuIntersados::MenuIntersados() {
}

void MenuIntersados::presentar() {
	cout << "Menu Intersados" << endl;
	cout << "1 - Consultar Propiedad" << endl;
	cout << "2 - Enviar Mensaje" << endl;
	cout << endl;
	cout << "0 - Cerrar Sesion" << endl;
}

void MenuIntersados::ejecutarOpcion(int opc) {
	UserInterface* submenu = NULL;
	switch(opc){
	case 0:
		UserInterface*cerrarSesion= new RutinaCerrarSesion();
		cerrarSesion->ejecutar();
		delete cerrarSesion;
	break;
	case 1:
		//Consulta prop
		break;

	case 2:
		//Enviar MEnsaje
		break;
	default:
		throw ExOpcionInvalida();
	}
	if (submenu!=NULL) {
		submenu->ejecutar();
		delete submenu;
	}

}

MenuIntersados::~MenuIntersados() {
}
