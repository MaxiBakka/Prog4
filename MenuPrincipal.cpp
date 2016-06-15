

#include "MenuPrincipal.h"

#include <iostream>
#include <string>



using namespace std;
MenuPrincipal::MenuPrincipal() {
}

void MenuPrincipal::printMenu(){
	cout << "Menu principal" << endl;
	cout << "1 - Iniciar Sesion" << endl;
	cout << "2 - Cerrar Sesion " << endl;
	cout << "3 - Menu para Administradores" << endl;
	cout << "4 - Menu para Inmobiliarias" << endl;
	cout << "5 - Menu para Interesados" << endl;
	cout << "5 - Cargar Set de Datos de Prueba" << endl;
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
		IniciarSesion();
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
	case 3:
		submenu = new MenuAdministradores();
		break;
	case 4:
		submenu = new MenuInombiliarias();
		break;
	case 5:
		submenu = new MenuInteresados();
		break;
	case 6:
		submenu = //cargar datos;
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
