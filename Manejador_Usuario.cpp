#include "Manejador_Usuario.h"
#include "InmobliariaNotFound.h"

Manejador_Usuario* Manejador_Usuario::instancia = NULL;
map<string,Administrador*>* Manejador_Usuario::administradores = NULL;
map<string,Interesado*>* Manejador_Usuario::interesados = NULL;
map<string,Inmobiliaria*>* Manejador_Usuario::inmobiliarias = NULL;


Manejador_Usuario :: Manejador_Usuario(){};
Manejador_Usuario :: ~Manejador_Usuario(){};

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
Interesado* Manejador_Usuario::getInteresado(string &email);
Usuario* Manejador_Usuario::getUsuario(string &email);

//operaciones del caso AltaInmobiliaria Y AltaInteresado
void Manejador_Usuario::CrearInmobiliaria(DataInmobiliaria*di);
void Manejador_Usuario::CrearInteresado(DataInteresado*di);

//existencia del usuario
bool Manejador_Usuario::existeUsuario(string& email);
//obtencion Datatypes
set<DataInfoInmobiliaria*>* Manejador_Usuario::getDataInfoInmobiliaria();
