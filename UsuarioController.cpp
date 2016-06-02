#include "UsuarioController.h"
#include "Manejador_Usuario.h"
#include "Inmobiliaria.h"


private:
	string* email = NULL;
	string* password = NULL;
	string* passwordPrimVez = NULL;
public:
	void UsuarioController::activarSesion(){}
	void UsuarioController::cancelarInicioSesion(){
		delete password;
		password = NULL;
	}

	void UsuarioController::confirmarContrasena(string& pwd){
		if(this->passwordPrimVez==pwd){
			this->password = pwd;
		}else{
			//falta implementar excepcion
			throw pwdNotMatched();
		}
	}

	bool UsuarioController::esUsuarioAdmin(){
		Manejador_Usuario* manUs = Manejador_Usuario::getInstance();
		Usuario* usr = manUs->find(this->email);
		bool esAdmin = manUs->esUsuarioAdministrador(); //no entiendo muy si como funciona esto
		return esAdmin;
	}
	void UsuarioController::ingresarContrasena(string& pwd){
		if(password==NULL){
			password=pwd
		}else{
			//falta implementar
			throw pwdAlreadyExist(); //habria que ver aca no se como manejamos el tema de como saber si correcta o no la pwd
			//throw userAlreadyLogged
		}
	}
	void UsuarioController::ingresarContrasenaNueva(string& pwd){
		if (!password==NULL)		{
			delete password;
			password = pwd;
		}else{
			throw noPwdPreviouslySaved();
		}
	}
	bool UsuarioController::primeraVez(){
		return password==NULL;
	}
	void UsuarioController::ingresarInmobiliaria(DataInmobiliaria* I){
		try{
			Inmobiliaria* Inmo = Manejador_Usuario::getInstance()->CrearInmobiliaria(I); 
			Manejador_Usuario::getInstance()->add(Inmo); // esta operacion para agregar la coleccion de inmobiliarias no aparece en el DCD
														//  asi que capaz que se implementa distinto	
		}catch(string e){ //puede ser una clase excepcion tmb lo dejo asi por ahora
			cout<<"Fallo al ingresar inmobiliaria" << e <<'\n';
		}													
	}
	<DataInfoInmobiliaria*>* UsuarioController::obtenerReporte()
