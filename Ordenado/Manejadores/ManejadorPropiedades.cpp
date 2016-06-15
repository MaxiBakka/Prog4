#include "ManejadorPropiedades.h"

#include <utility>

ManejadorPropiedades* ManejadorPropiedades::instancia= NULL;

ManejadorPropiedades::ManejadorPropiedades(){

	propiedades= new map<int,Propiedad*>();
}



ManejadorPropiedades* ManejadorPropiedades::getInstancia(){
    	 if (instancia==NULL)
    	 	instancia= new ManejadorPropiedades();

    	 	return instancia;


}

    //Destructor
ManejadorPropiedades::~ManejadorPropiedades(){

	for(map<int,Propiedades*>::iterator it = propiedades->begin(); it != propiedades->end(); ++it){
			Propiedad* p = it->second;
			delete p;
	}
		propiedades->clear();
		delete propiedades;
		MajeadorPropiedades::instancia = NULL;

}
    //Operaciones DSD
Propiedad* ManejadorPropiedades::crearPropiedad(DataPropiedad* p,Zona* z,Oferta*oferta,Edificio*edificio){
  DataCasa*dc=dynamic_cast<DataCasa*>(&p);
  if(dc!=NULL){
    Propiedad*propiedad= new Casa(dc,z,oferta);//no se deberia pasar solo el datatype,lo voy a cambiar dsp
  }else{
    DataApartamento*dc=dynamic_cast<DataApartamento*>(&p);
    Propiedad*propiedad= new Apartamento(dc,z,oferta,edificio);
  }

  oferta->setPropiedad(propiedad);
  propiedades->insert(pair<int,Propiedad*>(propiedad->getCodigo(),propiedad));

  return propiedad;
}

void ManejadorPropiedades::eliminarPropiedad(int c){


    	if(!(ExistePropiedad(c))){
    			throw ExPropiedadNoExistente();
    	}else{
    			Propiedad* p =propiedades->find(c)->second;
    			propiedades->erase(c);
    			delete p;
    	}


}

bool ManejadorPropiedades::ExistePropiedad(int codigo){
  return propiedades->find(codigo)!= propiedades->end();

}

set<DataInfoPropiedad*>* ManejadorPropiedades::getConversacionesPropiedad(Zona* z,string& email){

	set<Propiedad*>* props = z->getPropiedades();

	set<DataInfoPropiedad*>* res=new set<DataInfoPropiedad*>();
	for(set<Propiedades*>::iterator it= props->begin();it!=props->end();++it ){
		res->insert(*it->getDataInfoPropiedad(email));

	}
	delete props;//solo borra la memoria asignada al a coleccion sin borrar lo de adentro?
		return res;

}
Propiedad*ManejadorPropiedades::getPropiedad(int c){

	map<int,Propiedad*>::iterator it =propiedades->find(c);
		if(it!= propiedades->end()){
			return it->second;

		}else throw ExPropiedadNoExistente();

}
