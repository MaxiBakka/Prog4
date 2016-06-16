

#include "MenuPrincipal.h"
#include "/Rutinas/RutinaInicioSesion.h"

#include <iostream>
#include <string>



using namespace std;
MenuPrincipal::MenuPrincipal() {
}

void MenuPrincipal::printMenu(){
	cout << "Menu principal" << endl;
	cout << "1 - Iniciar Sesion" << endl;
	cout << "2 - Cargar Set de Datos de Prueba" << endl;
	cout << endl;
	cout << "0 - Salir" << endl;
}

void MenuPrincipal::ejecutarOpcion(int opc){
	PantallaUI* submenu = NULL;
	switch(opc){
	case 0:
		salirDelSistema();
		break;
	case 1:
		subemenu = new RutinaInicioSesion();

		/*Sesion*sesion=Sesion::getInstancia();
		Usuario*user=sesion->getUsuario()
		if(Interesado*int=dynamic_cast<Interesado*>(user)){
			submenu= new MenuIntersados();
		}
		else if(Inmobiliaria*inm=dynamic_cast<Inmobiliaria*>(user)){
			submenu= new MenuInmobiliarias();
		}
		else{
			submenu= new MenuAdministradores();
		}	*/
		break;
	case 2:
		IUsuarioController::CerrarSesion();
		break;

	default:
		throw ExOpcionInvalida();
	}
	if (submenu!=NULL) {
		submenu->ejecutar();
		delete submenu;
	}
}

MenuPrincipal::~MenuPrincipal() {
}
