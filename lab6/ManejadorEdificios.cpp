#include "ManejadorEdificios.h"



ManejadorEdificios* ManejadorEdificios::instancia=NULL;

ManejadorEdificios::ManejadorEdificios() {
    this->edificios=new map<string,Edificio*>*();
}

void ManejadorEdificios::addEdificio(DataEdificio* de) {
    //Primero hay que hacer la excepcion que hay que hacerla
    Edificio* d = new Edificio(de->get_nombre(),de->get_cantPisos(),de->get_gastosComunes());
    this->edificios->insert(pair<string,Edificio*>*(de->get_nombre(),d));
}

Edificio* ManejadorEdificios::getEdificio(const string& nombre) {
    //agregar excepcion existeEdificio
    return this->edificios->find(nombre);
}

set<DataEdificio*>* ManejadorEdificios::getEdificios() {
    return new map<string,Edificio*>* res (this->edificios);
}

ManejadorEdificios* ManejadorEdificios::getInstancia() {
    if (instancia==NULL){
		instancia= new ManejadorEdificios();
    }
    return instancia;
}

ManejadorEdificios::~ManejadorEdificios() {
    for(map<string,Edificio*>::iterator it = this->edificios->begin(); it != this->edificios->end(); ++it){
		Edificio* e = it->second;
		delete e;
	}
    this->edificios->clear();
    delete edificios;
    instancia = NULL;
}
