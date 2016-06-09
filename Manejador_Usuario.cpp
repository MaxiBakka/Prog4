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
	map<string,Inmobiliaria*>::iterator inmoIt;
	map<string,Interesado*>::iterator interIt;
	map<string,Administrador*>::iterator adminIt;
	
	for(inmoIt=inmobiliarias->begin(),inmoIt!=inmobiliarias->end(),++inmoIt){
		delete inmoIt->second();
		delete inmobiliarias;
	}
	for(interIt=interesados->begin(),interIt!=interesados->end(),++interIt){
		delete interIt->second();
		delete interesados;
	}
	for(adminIt=administradores->begin(),adminIt!=administradores->end(),++adminIt){
		delete adminIt->second();
		delete administradores;
	}

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
Usuario* Manejador_Usuario::getUsuario(string &email){
	map<string,Inmobiliaria*>::iterator it;
	map<string,Interesado*>::iterator it2;
	it = inmobiliarias->find(email);
	if(it != inmobiliarias->end()){
		return it->second();
	}else if(it2 != interesados->end()){
		return it2->second();
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
bool Manejador_Usuario::existeUsuario(string& email){
	map<string,Inmobiliaria*>::iterator it;
	map<string,Interesado*>::iterator it2;
	it = inmobiliarias->find(email);
	it2 = interesados->find(email);
	return (it != inmobiliarias->end() || it2 != interesados->end())
}

//obtencion Datatypes
set<DataInfoInmobiliaria*>* Manejador_Usuario::getDataInfoInmobiliaria(){
	set<DataInfoInmobiliaria*>* infoInmo =  new <DataInfoInmobiliaria*>();
	map<string,Inmobiliaria*>::iterator it;
	for(it=inmobiliarias->begin(),it!=inmobiliaras->end(),++it){
		infoInmo->insert(*it->getInfoInmobiliaria());
	}
	return infoInmo;
}
