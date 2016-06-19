
#include <iostream>
#include <string>
#include "MenuInteresados.h"
#include "../Excepciones/ExOpcionInvalida.h"
#include "../Rutinas/RutinaConsultarPropiedad.h"
#include "../Rutinas/RutinaCerrarSesion.h"
#include "../Rutinas/RutinaEnviarMensajeInteresado.h"
#include "../ClasesDeDominio/Sesion.h"

using namespace std;
MenuInteresados::MenuInteresados() {
}

void MenuInteresados::presentar() {
	cout << "--------Menu Intersados--------" << endl;
	cout << "1 - Consultar Propiedad" << endl;
	cout << "2 - Enviar Mensaje" << endl;
	cout << endl;
	cout << "0 - Cerrar Sesion" << endl;
	cout << "---------------------------------- " <<endl;
}

void MenuInteresados::ejecutarOpcion(int opc) {
	UserInterface* submenu = NULL;
	switch(opc){
	case 0:
		submenu= new RutinaCerrarSesion();
		break;
	case 1:
		submenu = new RutinaConsultarPropiedad();
		break;

	case 2:
		submenu = new RutinaEnviarMensajeInteresado();
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

MenuInteresados::~MenuInteresados() {
}
