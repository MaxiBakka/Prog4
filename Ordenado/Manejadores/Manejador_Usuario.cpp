#include "Manejador_Usuario.h"
#include "InmobiliariaNotFound.h"
#include "InteresadoNotFound.h"
#include "UsuarioNotFound.h"
#include "ExisteInteresado.h"
#include "InmobiliariaYaExistente.h"

#include "Inmobiliaria.h"
#include "Administrador.h"
#include "Interesado.h"
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

	for(inmoIt=inmobiliarias->begin();inmoIt!=inmobiliarias->end();++inmoIt){
		delete inmoIt->second;
	}
	inmobiliarias->clear();
	delete inmobiliarias;

	for(interIt=interesados->begin();interIt!=interesados->end();++interIt){
	 		delete interIt->second;
 	}
	interesados->clear();
	delete interesados;

	for(adminIt=administradores->begin();adminIt!=administradores->end();++adminIt){
			delete adminIt->second;
	}
	administradores->clear();
	delete administradores;


}

Manejador_Usuario* Manejador_Usuario::getInstancia(){
	if (instancia==NULL){
		instancia= new Manejador_Usuario();
    }
    return instancia;
}

//getters de usuarios
Inmobiliaria* Manejador_Usuario::getInmobiliaria(string &email){
	map<string,Inmobiliaria*>::iterator it;
	it = inmobiliarias->find(email);
	if(it != inmobiliarias->end()){
		return it->second;
	}else{
		throw InmobiliariaNotFound();
	}

}
Interesado* Manejador_Usuario::getInteresado(string &email){
	map<string,Interesado*>::iterator it;
 	it = interesados->find(email);

 	if(it != interesados->end()){
 		return it->second;
 	}else{
 		throw InteresadoNotFound();
 	}

}

Usuario* Manejador_Usuario::getUsuario(string &email){

	map<string,Inmobiliaria*>::iterator it;
	map<string,Interesado*>::iterator it2;
	map<string,Administrador*>::iterator it3;
	it = inmobiliarias->find(email);

 	if(it != inmobiliarias->end()){
		return it->second;
	}else if((it2=interesados->find(email))!= interesados->end()){
 		return it2->second;
	}else if ((it3=administradores->find(email))!= administradores->end()){
		return it3->second;
	}else{
 		throw UsuarioNotFound();
	}

}
void Manejador_Usuario::CrearAdministrador(string &email,string &password){

	Administrador*admin= new Administrador(email,password);
	administradores->insert(pair<string,Administrador*>(email,admin));
}

//operaciones del caso AltaInmobiliaria Y AltaInteresado
void Manejador_Usuario::CrearInmobiliaria(DataInmobiliaria*di){
	if(!(inmobiliarias->find(di->get_email())!=inmobiliarias->end() || interesados->find(di->get_email())!=interesados->end() )){
	  for (map<string,Inmobiliaria*>::iterator it = inmobiliarias->begin(); it!=inmobiliarias->end();it++) {
	  	if(it->second->getNombre()==di->get_nombre()) throw InmobiliariaYaExistente();

	  } 					 //tmb hay q fijarse q el nombre de la inmo sea unico ,la coleccion esta hecha por email
        std::string passDefecto=" ";
		Inmobiliaria* inmo = new Inmobiliaria(di->get_email(),passDefecto,di->get_nombre(),di->get_direccion()); //la unica es recorrer toda la coleccion
		inmobiliarias->insert(pair<string,Inmobiliaria*>(di->get_email(),inmo));
	}else{
		throw InmobiliariaYaExistente();
	}
}

void Manejador_Usuario::CrearInteresado(DtInteresado* di){
	if (interesados->find(di->get_Email())!=interesados->end() || inmobiliarias->find(di->get_Email())!=inmobiliarias->end()) {
		throw ExisteInteresado();
	} else {
	    std::string passDefecto=" ";
		Interesado* inter = new Interesado(di->get_Email(),passDefecto,di->get_Nombre(),di->get_Apellido(),di->get_Edad());
		interesados->insert(pair<string,Interesado*>(di->get_Email(),inter));
	}

}


//obtencion Datatypes

set<DataInfoInmobiliaria*>* Manejador_Usuario::getDataInfoInmobiliaria(){

	set<DataInfoInmobiliaria*>* infoInmo =  new set<DataInfoInmobiliaria*>();
 	map<string,Inmobiliaria*>::iterator it;

 	for(it=inmobiliarias->begin();it!=inmobiliarias->end();++it){
 		infoInmo->insert(it->second->getDataInfoInmobiliaria());
 	}
 	return infoInmo;

}
