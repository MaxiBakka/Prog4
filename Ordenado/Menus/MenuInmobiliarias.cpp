
#include <iostream>
#include <string>

#include "MenuInmobiliarias.h"

#include "ExOpcionInvalida.h"
#include "RutinaCerrarSesion.h"
#include "RutinaAltaEdificio.h"
#include "RutinaConsultarPropiedad.h"
//#include "RutinaModificarPropiedad.h"
#include "RutinaEnviarMensajeInmobiliaria.h"
#include "RutinaEliminarPropiedad.h"

using namespace std;
MenuInmobiliarias::MenuInmobiliarias() {
}

void MenuInmobiliarias::presentar() {
	cout << "-------Menu Inmobiliarias-------" << endl;
	cout << "1 - Alta Edificio" << endl;
	cout << "2 - Alta Propiedad" << endl;
	cout << "3 - Consultar Propiedad" << endl;
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
		submenu = new RutinaAltaEdificio();
		break;

	case 2:
		//Alta Prop
		break;
	case 3:
		submenu = new RutinaConsultarPropiedad();
		break;
	case 4:
		submenu = new RutinaModificarPropiedad();
		break;
	case 5:
		submenu= new RutinaEliminarPropiedad();
		break;
	case 6:
		submenu = new RutinaEnviarMensajeInmobiliaria();
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
