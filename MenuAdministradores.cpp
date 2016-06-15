
#include <iostream>
#include <string>
#include "MenuAdministradores.h"
#include "ExOpcionInvalida.h"

using namespace std;
MenuAdministradores::MenuAdministradores() {
}

void MenuAdministradores::presentar() {
	cout << "Menu Administradores" << endl;
	cout << "1 - Alta Inmobiliaria" << endl;
	cout << "2 - Alta Interesado" << endl;
	cout << "3 - Obtener Reporte de Inmobiliarias" << endl;
	cout << endl;
	cout << "0 - Atrás" << endl;
}

void MenuAdministradores::ejecutarOpcion(int opc) {
	UserInterface* submenu = NULL;
	switch(opc){
	case 0:
		setSalida();
		break;
	case 1:
		//despliega algo para leer datos y crea el dataInmo
		IUsuarioController::IngresarInmobiliaria(dato);
		break;

	case 2:
		//despliega algo para leer datos y crea el dataInt
		IUsuarioController::IngresarInteresado(dato);
		break;
	case 3:
		IUsuarioController::ObtnerReportedato);
		//ImprimirDatos
		break;
	default:
		throw ExOpcionInvalida();
	}
	if (submenu!=NULL) {
		submenu->ejecutar();
		delete submenu;
	}

}

MenuAdministradores::~MenuAdministradores() {
}

