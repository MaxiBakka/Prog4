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
		}catch(UsuarioNotFound &e){
			cout<< e.what()<<endl;
			if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
		}
	}

}

void RutinaInicioSesion::ingresoPwd(){
	while(true){
		try{
			cout<<endl<<"Ingrese su Contraseña:";
			string pwd = MenuUtils::leerString();
			ctrl->IngresarContrasenia(pwd);

		}catch(WrongPwd &e){
			cout<< e.what()<<endl;
			if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
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
		}catch(ProcesoCancelado&){
			cout<< "Inicio de Sesion Cancelado!";
			if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")){
				delete ctrl;
				ctrl = Factory::getIUsuarioController();
			}else{
				break;
			}
		}
	}
	MenuUtils::limpiarConsola();
}
