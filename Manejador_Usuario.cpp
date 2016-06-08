#include "Manejador_Usuario.h"
#include "InmobliariaNotFound.h"
#include "InteresadoNotFound.h"
#include "UsuarioNotFound.h"

#include <utility>

Manejador_Usuario* Manejador_Usuario::instancia = NULL;


Manejador_Usuario :: Manejador_Usuario(){
	inmobiliarias = new map<string,Inmobiliaria*>();
	interesados =  new map<string,Interesado*>();
	administradores = new map<string,Administrador*>();
};
Manejador_Usuario :: ~Manejador_Usuario(){
	
	//creo que aca deberia destruirse todos los usuarios, o destruir la coleccion
};

public Manejador_Usuario::getInstance(){
	if (instancia==NULL) instancia = new Manejador_Usuario();
	return instancia;
}

//getters de usuarios
Inmobiliaria* Manejador_Usuario::getInmobiliaria(string &email){
	map<string,Inmobiliaria*>::iterator it;
	it = inmobiliarias->find(email);
	if(it != inmobiliarias->end()){
		return it->second();
	}else{
		throw InmobiliariaNotFound();
	}

}

Interesado* Manejador_Usuario::getInteresado(string &email){
	map<string,Interesado*>::iterator it;
	it = interesados->find(email);
	if(it != interesados->end()){
		return it->second();
	}else{
		throw InteresadoNotFound();
	}

}
Usuario* Manejador_Usuario::getUsuario(string &email){   // esta operacion se tiene que fijar en todas las colecciones para ver que tipo
	map<string,Inmobiliaria*>::iterator it;		//de usuario retornar
	it = inmobiliarias->find(email);
	if(it != inmobiliarias->end()){
		return it->second();
	}else{
		throw UsuarioNotFound();
	}
}

//operaciones del caso AltaInmobiliaria Y AltaInteresado
void Manejador_Usuario::CrearInmobiliaria(DataInmobiliaria*di){
	Inmobiliaria* inmo = new Inmobiliaria(di->get_email()," ",di->get_nombre(),di->get_direccion()); //no le falta pwd a esto?? vichar DataInmo
	inmobiliarias->insert(pair<string,Inmobiliaria*>(di->get_email(),inmo));	//respuesta:aca es cuando el administrador crea un usuario 
}											//y le asigna un pwd por defecto 
void Manejador_Usuario::CrearInteresado(DataInteresado*di){
	Intresado * inter = new Interesado(di->get_email()," ",di->get_nombre(),di->get_apellido(),di->get_edad());
	interesados->insert(pair<string,Interesado*>(di->get_email(),inter));
}

//existencia del usuario
bool Manejador_Usuario::existeUsuario(string& email);
//obtencion Datatypes
set<DataInfoInmobiliaria*>* Manejador_Usuario::getDataInfoInmobiliaria();
