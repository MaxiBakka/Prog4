#include "MenuAdministradores.h"
#include <iostream>
#include <string>

#include "../Excepciones/ExOpcionInvalida.h"
#include "../Rutinas/RutinaCerrarSesion.h"
#include "../Rutinas/RutinaAltaInteresado.h"
#include "../Rutinas/RutinaAltaInmobiliaria.h"
#include "../ClasesDeDominio/Sesion.h"

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
