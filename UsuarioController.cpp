#include "UsuarioController.h"
#include "Manejador_Usuario.h"
#include "Inmobiliaria.h"
#include "Interesado.h"




UsuarioController::UsuarioController(){
	email=NULL;
	password=NULL;
	usuario=NULL;

}
UsuarioController::~UsuarioController(){

	usuario=NULL; 	//nose si dejar esto asi esta bien
	delete password;//porque cuando decimos que libera memoria
	delete email;   //si tmb tenemos que destruir el controlador
									//entonces asi se pierde la sesion.
}
void UsuarioController::activarSesion(){
		delete password;
		//Poner delete email o usuario=NULL uno de los dos deberia ser
		// el dato para recordar la sesion(me parece mejor usuario)
}

void UsuarioController::cancelarInicioSesion(){
		if(password!=NULL) delete password;

		delete email;
		usuario=NULL;
}

void UsuarioController::ConfirmarContrasenia(string& pwd){
	/*	if(this->password==pwd){
		usuario->set_contrasenia(pwd);
		}else{
			//falta implementar excepcion
			throw pwdNotMatched();
		}*/
		//Para esta operacion siempre se cumple la precondicion
		//la excepcion se hace por afuera
		usuario->set_contrasenia(pwd);
}

bool UsuarioController::esUsuarioAdmin(){
		Manejador_Usuario* manUs = Manejador_Usuario::getInstance();
		usuario = manUs->getUsuario(this->email);//suplantamos la operacion Esusuarioadmin por getUsuario
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

			Manejador_Usuario* mu = Manejador_Usuario::getInstance();//Hacer delete dsp??
			mu->inmobiliarias->AddInmobiliaria(new mu->Inmobiliaria(di->getNombre(),di->getUbicacion(),di->get_email()," "));

		}catch(string e){ //puede ser una clase excepcion tmb lo dejo asi por ahora.
			cout<<"Fallo al ingresar inmobiliaria" << e <<'\n';//Maxi:esta excepcion debe saltar si el mail o nombre de la inmobiliaria no es unico
		}
}

set<DataInfoInmobiliaria*>* UsuarioController::obtenerReporte(){

	//completamos mas adelante

}

//CASO DE USO CERRAR SESION
void UsuarioController::CerrarSesion(string emailUsuario){
	delete email;		//misma cuestion de arriba (hay que ver si es necesario el parametro de entrada)
	usuario =NULL;
}


//CASO DE USO ALTA INTERESADO
void UsuarioController::IngresarInteresado(DtInteresado*di){

	try{

		Manejador_Usuario* mu = Manejador_Usuario::getInstance();//Hacer delete dsp??
		mu->interesados->AddInteresado(new mu->Interesado(di->get_email()," ",di->get_nombre(),di->get_apellido(),di->get_edad()));

	}catch(string email){
		cout<<"Interesado ya existente" << email.what() <<'\n';//Maxi:esta excepcion debe saltar si el mail de el interesado no es unico
	}

}
