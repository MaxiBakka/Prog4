
#include <iostream>
#include <string>
#include "MenuAdministradores.h"
#include "ExOpcionInvalida.h"
#include "RutinaCerrarSesion.h"
#include "RutinaAltaInteresado.h"
#include "RutinaAltaInmobiliaria.h"
#include "Sesion.h"

using namespace std;
MenuAdministradores::MenuAdministradores() {
}

void MenuAdministradores::presentar() {
	cout << "------Menu Administradores------" << endl;
	cout << "1 - Alta Inmobiliaria" << endl;
	cout << "2 - Alta Interesado" << endl;
	cout << "3 - Obtener Reporte de Inmobiliarias" << endl;
	cout << endl;
	cout << "0 - Cerrar Sesion" << endl;
	cout << "---------------------------------- " <<endl;
}

void MenuAdministradores::ejecutarOpcion(int opc) {
	UserInterface* submenu = NULL;
	switch(opc){
	case 0:
		submenu= new RutinaCerrarSesion();
		break;
	case 1:
		submenu = new RutinaAltaInmobiliaria();
		break;

	case 2:
		submenu = new RutinaAltaInteresado();
		break;
	case 3:
		submenu = new RutinaObtenerReporteInmobiliarias();
		break;
	default:
		throw ExOpcionInvalida();
	}
	if (submenu!=NULL) {
		submenu->ejecutar();
		delete submenu;
		if(Sesion::getInstancia()->getUsuario()==NULL)
		 salirDelSistema();
	}



}

MenuAdministradores::~MenuAdministradores() {
}
