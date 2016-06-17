
#include <iostream>
#include <string>
#include "MenuInmobiliarias.h"
#include "ExOpcionInvalida.h"
#include "RutinaCerrarSesion.h"
using namespace std;
MenuInmobiliarias::MenuInmobiliarias() {
}

void MenuInmobiliarias::presentar() {
	cout << "-------Menu Inmobiliarias-------" << endl;
	cout << "1 - Alta Edificio" << endl;
	cout << "2 - Alta Propiedad" << endl;
	cout << "3 - Consulta Propiedad" << endl;
	cout << "4 - Modificar Propiedad" << endl;
	cout << "5 - Eliminar Propiedad" << endl;
	cout << "6 - Enviar Mensaje" << endl;
	cout << endl;
	cout << "0 - Cerrar Sesion" << endl;
	cout << "---------------------------------- " <<endl;
}

void MenuInmobiliarias::ejecutarOpcion(int opc) {
	UserInterface* submenu = NULL;
	bool salir=false;
	switch(opc){
	case 0:
		submenu= new RutinaCerrarSesion();
		salir=true;
		break;
	case 1:
		//Alta Edifcio
		break;

	case 2:
		//Alta Prop
		break;
	case 3:
		//Consulta prop
		break;
	case 4:
		//Modificar prop
		break;
	case 5:
		//Eliminar
		break;
	case 6:
		//Enviar MEnsaje
		break;
	default:
		throw ExOpcionInvalida();
	}
	if (submenu!=NULL) {
		submenu->ejecutar();
		delete submenu;
    if(salir) salirDelSistema();
	}

}

MenuInmobiliarias::~MenuInmobiliarias() {
}

