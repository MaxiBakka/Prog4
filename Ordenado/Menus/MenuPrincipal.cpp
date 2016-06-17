

#include "MenuPrincipal.h"
#include "MenuInteresados.h"
#include "MenuInmobiliarias.h"
#include "MenuAdministradores.h"

#include "RutinaInicioSesion.h"


#include "Sesion.h"
#include "Interesado.h"
#include "Inmobiliaria.h"
#include "Administrador.h"

#include "ExOpcionInvalida.h"


#include <iostream>
#include <string>



using namespace std;
MenuPrincipal::MenuPrincipal() {
}

void MenuPrincipal::printMenu(){
	cout << "Menu principal de Mi Casa" << endl;
	cout << "1 - Iniciar Sesion" << endl;
	cout << endl;
	cout << "0 - Salir" << endl;
}

void MenuPrincipal::ejecutarOpcion(int opc){
	UserInterface* submenu = NULL;
	switch(opc){
	case 0:
		salirDelSistema();
		break;
	case 1:
		submenu = new RutinaInicioSesion();
		break;
	default:
		throw ExOpcionInvalida();
	}
	if (submenu!=NULL) {
		submenu->ejecutar();
		delete submenu;

		Sesion*sesion=Sesion::getInstancia();
		Usuario*user=sesion->getUsuario();
		if(Interesado*interesado=dynamic_cast<Interesado*>(user)){
			submenu= new MenuIntersados();
			submenu->ejecutar;
			delete submenu;
		}
		else if(Inmobiliaria*inm=dynamic_cast<Inmobiliaria*>(user)){
			submenu= new MenuInmobiliarias();
			submenu->ejecutar;
			delete submenu;
		}
		else if (Administrador*adm=dynamic_cast<Administrador*>(user)){
			submenu= new MenuAdministradores();
			submenu->ejecutar;
			delete submenu;
		}
	}
}

MenuPrincipal::~MenuPrincipal() {
}
