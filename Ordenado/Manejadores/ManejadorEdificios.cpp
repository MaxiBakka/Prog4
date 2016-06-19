#include "ManejadorEdificios.h"
#include "../Excepciones/ExisteEdificio.h"
#include "../Excepciones/EdificioNoExistente.h"
#include "../Excepciones/NoExistenEdificios.h"


#include <utility>


ManejadorEdificios* ManejadorEdificios::instancia=NULL;

ManejadorEdificios::ManejadorEdificios() {
    this->edificios = new map<string,Edificio*>();
}

void ManejadorEdificios::addEdificio(DataEdificio* de) {

    if((edificios->find(de->get_nombre())==edificios->end()) && (de->get_cantPisos() > 0) && (de->get_gastosComunes() >0) ){
      Edificio* d = new Edificio(de->get_nombre(),de->get_cantPisos(),de->get_gastosComunes());
      this->edificios->insert(pair<string,Edificio*>(de->get_nombre(),d));
    }else throw ExisteEdificio();
}

Edificio* ManejadorEdificios::getEdificio(const string& nombre) {
    //agregar excepcion existeEdificio
    if(edificios->find(nombre)!=edificios->end()){
      return this->edificios->find(nombre)->second;
    }else throw EdificioNoExistente();
}

set<DataEdificio*>* ManejadorEdificios::getEdificios() {

  if (edificios->size()==0) {
      throw NoExistenEdificios();
  }else{
      set<DataEdificio*>*res= new set<DataEdificio*>;
      for (map<string,Edificio*>::iterator it =edificios->begin();it!=edificios->end();it++) {
        res->insert(it->second->getDataEdificio());
      }
   return res;
  }

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
