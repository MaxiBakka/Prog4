#include "Manejador_Usuario.h"
#include "InmobliariaNotFound.h"
#include "InteresadoNotFound.h"
#include "UsuarioNotFound.h"
#include "ExisteInteresado.h"
#include "InmobiliariaYaExistente.h"
#include <utility>


Manejador_Usuario* Manejador_Usuario::instancia = NULL;



Manejador_Usuario::Manejador_Usuario(){
	inmobiliarias = new map<string,Inmobiliaria*>();
 	interesados =  new map<string,Interesado*>();
	administradores = new map<string,Administrador*>();

}

Manejador_Usuario::~Manejador_Usuario(){
	map<string,Inmobiliaria*>::iterator inmoIt;
	map<string,Interesado*>::iterator interIt;
	map<string,Administrador*>::iterator adminIt;

	for(inmoIt=inmobiliarias->begin(),inmoIt!=inmobiliarias->end(),++inmoIt){
		delete inmoIt->second();
	}
	inmobiliarias->clear()
	delete inmobiliarias;

	for(interIt=interesados->begin(),interIt!=interesados->end(),++interIt){
	 		delete interIt->second();
 	}
	interesados->clear()
	delete interesados;

	for(adminIt=administradores->begin(),adminIt!=administradores->end(),++adminIt){
			delete adminIt->second();
	}
	administradores->clear();
	delete administradores;


}

public Manejador_Usuario::getInstance(){
	if (instancia==NULL) instancia = new Manejador_Usuario();
	return instancia;
}

//getters de usuarios
Inmobiliaria* Manejador_Usuario::getInmobiliaria(string &email){
	map<string,Inmobiliaria*>::iterator it;
	it = inmobiliarias.find(email);
	if(it != inmobiliarias.end()){
		return inmobiliarias[email];
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
	}else if((it2=interesados->find(email))!= interesados->end()){
 		return it2->second();
	}else if ((map<string,Administrador*>::itereador it3=administradores->find(email))!= administradores->end()){
		return it3->second();
	}else{
 		throw UsuarioNotFound();
	}

}

//operaciones del caso AltaInmobiliaria Y AltaInteresado
void Manejador_Usuario::CrearInmobiliaria(DataInmobiliaria*di){
	if(!(inmobiliarias->find(di->get_email())!=inmobiliarias->end()))
	  for (map<string,Inmobiliaria*>::iterator it = inmobiliarias->begin(); it!=inmobiliarias->end();it++) {
	  	if(it->second->getNombre()==di->get_nombre()) throw InmobiliariaYaExistente;

	  } 															 //tmb hay q fijarse q el nombre de la inmo sea unico ,la coleccion esta hecha por email
		Inmobiliaria* inmo = new Inmobiliaria(di->get_email()," ",di->get_nombre(),di->get_direccion()); //la unica es recorrer toda la coleccion
		inmobiliarias->insert(pair<string,Inmobiliaria*>(di->get_email(),inmo));
	}else{
		throw InmobiliariaYaExistente;
	}
}

void Manejador_Usuario::CrearInteresado(DataInteresado*di){
	if (interesados->find(di->get_email())!=interesados->end()) {
		throw ExisteInteresado;
	} else {
		Intresado * inter = new Interesado(di->get_email()," ",di->get_nombre(),di->get_apellido(),di->get_edad());
		interesados->insert(pair<string,Interesado*>(di->get_email(),inter));
	}

}


//obtencion Datatypes

set<DataInfoInmobiliaria*>* Manejador_Usuario::getDataInfoInmobiliaria(){
	set<DataInfoInmobiliaria*>* infoInmo =  new <DataInfoInmobiliaria*>();
 	map<string,Inmobiliaria*>::iterator it;

 	for(it=inmobiliarias->begin(),it!=inmobiliaras->end(),++it){
 		infoInmo->insert(it->second->getInfoInmobiliaria());
 	}
 	return infoInmo;

}
