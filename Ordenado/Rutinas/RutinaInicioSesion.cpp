#include "RutinaInicioSesion.h"
#include "MenuUtils.h"
#include "UsuarioNotFound.h"
#include "ProcesoCancelado.h"
#include "WrongPwd.h"
#include <iostream>

#include <string>

#include "Factory.h"


using namespace std;

void RutinaInicioSesion::ingresoEmail(){
	while(true){
		try{
			cout<<endl<<"Ingrese su Email: ";
			string usr = MenuUtils::leerString();
			ctrl->IngresarEmail(usr);
			break;
		}catch(UsuarioNotFound &e){
			cout<< e.what()<<endl;
			if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
		}
	}

}

void RutinaInicioSesion::ingresoPwd(){
	while(true){
		try{
			cout<<endl<<"Ingrese su Contrasenia:";
			string pwd = MenuUtils::leerString();
			ctrl->IngresarContrasenia(pwd);
			MenuUtils::limpiarConsola();
			break;
		}catch(WrongPwd &e){
			cout<< e.what()<<endl;
			if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
			MenuUtils::limpiarConsola();
		}
	}
}

void RutinaInicioSesion::ingPrimeraVez(){
	string primPwd ="";
	int intentos = 0;
	while(primPwd==""){
		if (intentos != 0){
			cout<<endl<<"La contraseña no puede ser vacia:";
			if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
		}
		cout<<endl<<"Ingrese su Nueva Contraseña:";
		primPwd = MenuUtils::leerString();
		intentos++;
	}
	ctrl->IngresarContraseniaNueva(primPwd);
		string confirmpwd;
while (true) {
	std::cout << "Confirmacion de Contrasenia:" << std::endl;
	 confirmpwd= MenuUtils::leerString();
	if(confirmpwd!=primPwd){
		std::cout << "contrasenia incorrecta" << std::endl;
		if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
	}else{
			ctrl->ConfirmarContrasenia(confirmpwd);
			break;
	}

}

}



RutinaInicioSesion::RutinaInicioSesion(){
	ctrl = Factory::getIUsuarioController();
}
RutinaInicioSesion::~RutinaInicioSesion(){}

void RutinaInicioSesion::ejecutar(){

	while(true){
		try{
			cout<< " Inicio de Sesion ";
			ingresoEmail();
			if(ctrl->esUsuarioAdmin() || !ctrl->PrimeraVez()){
				ingresoPwd();
			}else{
				ingPrimeraVez();
			}
			ctrl->activarSesion();
			std::cout << "Inicio de sesion exitoso." << std::endl;
			break;
		}catch(ProcesoCancelado&){
			cout<< "Inicio de Sesion Cancelado!"<< endl;
			ctrl->CancelarInicioSesion();
			if(MenuUtils::leerOpcion("Desea intentar iniciar sesion nuevamente?")){
				delete ctrl;
				ctrl = Factory::getIUsuarioController();
			}else{
				break;
			}
		}catch(UsuarioNotFound &e){
			cout<< e.what()<< endl;
			ctrl->CancelarInicioSesion();
			if(MenuUtils::leerOpcion("Desea intentar iniciar sesion nuevamente?")){
				delete ctrl;
				ctrl = Factory::getIUsuarioController();
			}else{
				break;
			}
	}

}
