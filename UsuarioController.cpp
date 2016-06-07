#include "UsuarioController.h"
#include "Manejador_Usuario.h"
#include "Inmobiliaria.h"
#include "Interesado.h"
#include "../datatypes/DataInmobiliaria.h"









UsuarioController::UsuarioController(){
	email=NULL;
	password=NULL;
	usuario=NULL;

}
UsuarioController::~UsuarioController(){

	usuario=NULL;
	delete password;
	delete email;

}
void UsuarioController::activarSesion(){
		delete password;
		delete email;
		Sesion*sesion= Sesion::getInstancia();
		sesion->ActivarSesion(this->usuario);
		usuario=NULL;

}

void UsuarioController::cancelarInicioSesion(){
		if(password!=NULL) delete password;

		delete email;
		usuario=NULL;
}
// se cumple precond que pwd es correcta
void UsuarioController::ConfirmarContrasenia(string& pwd){
	usuario->set_contrasenia(pwd);
}

bool UsuarioController::esUsuarioAdmin(){
		Manejador_Usuario* manUs = Manejador_Usuario::getInstance();
		usuario = manUs->getUsuario(this->email);
		return (0 != Administrador*admin= dynamic_cast<Administrador*>(&usuario));
}
void UsuarioController::IngresarContrasenia(string& pwd){
		if(pwd==usuario->get_contrasenia()){
			password= new string;
			*password= pwd;
		}else{
			//falta implementar
			throw WrongPwd();

		}
}


void UsuarioController::IngresarContraseniaNueva(string& pwd){

			this->password =new string;
			*password=pwd;
}

bool UsuarioController::primeraVez(){
		return (usuario->get_contrasenia() == " ");
}

 void UsuarioController::IngresarEmail(string& email){

	 		this->email= new string;
			*email= email;
}

void UsuarioController::IngresarInmobiliaria(DataInmobiliaria* di){
		try{

			Manejador_Usuario* mu = Manejador_Usuario::getInstance();
			mu->CrearInmobiliaria(di);
		}catch(string e){
			cout<<"Fallo al ingresar inmobiliaria" << e <<'\n';//Maxi:esta excepcion debe saltar si el mail o nombre de la inmobiliaria no es unico
		}
}

set<DataInfoInmobiliaria*>* UsuarioController::obtenerReporte(){

	Manejador_Usuario* mu = Manejador_Usuario::getInstance();
	return mu->getDataInfoInmobiliaria() ;

}

//CASO DE USO CERRAR SESION
void UsuarioController::CerrarSesion(){

	Sesion*sesion= Sesion::getInstancia();
	sesion->CerrarSesion(this->usuario);
}


//CASO DE USO ALTA INTERESADO
void UsuarioController::IngresarInteresado(DtInteresado*di){

	try{

		Manejador_Usuario* mu = Manejador_Usuario::getInstance();
		mu->CrearInteresado(di);

	}catch(string email){
		cout<<"Interesado ya existente" << email.what() <<'\n';//Maxi:esta excepcion debe saltar si el mail de el interesado no es unico
	}

}
