

#include "MenuPrincipal.h"
#include "MenuInteresados.h"
#include "MenuInmobiliarias.h
#include "MenuAdministradores.h

#include "RutinaInicioSesion.h"
#include "RutinaAltaInmobiliaria.h"
#include "RutinaAltaInteresado.h"
#include "RutinaCargarDatos.h"

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
	cout << "Menu principal" << endl;
	cout << "1 - Iniciar Sesion" << endl;
	cout << "2 - Cargar Set de Datos de Prueba" << endl;
	cout << "3 - Cerrar Sesion"<<  endl;
	cout << endl;
	cout << "0 - Salir" << endl;
	leerOpcion();// no se si va esto me entro la duda de como leia la opcion y de quien mandaba a impirmir el menu
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
	case 2:
		submenu = new RutinaCargarDatos();
		break;
	case 3:


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
		}
		else if(Inmobiliaria*inm=dynamic_cast<Inmobiliaria*>(user)){
			submenu= new MenuInmobiliarias();
		}
		else if (Administrador*adm=dynamic_cast<Administrador*>(user)){
			submenu= new MenuAdministradores();
		}else{
			break;
		}
	}
}

MenuPrincipal::~MenuPrincipal() {
}
