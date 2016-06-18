#include "ManejadorPropiedades.h"
#include "DataCasa.h"
#include "DataApartamento.h"
#include "Casa.h"
#include "Apartamento.h"
//#include "EsPropiedadNoExistente.h"

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

	for(map<int,Propiedad*>::iterator it = propiedades->begin(); it != propiedades->end(); ++it){
			Propiedad* p = it->second;
			delete p;
	}
		propiedades->clear();
		delete propiedades;
		ManejadorPropiedades::instancia = NULL;

}
    //Operaciones DSD
Propiedad* ManejadorPropiedades::crearPropiedad(DataPropiedad* p,Zona* z,Oferta*oferta,Edificio*edificio){
  Propiedad* propiedad;
  DataCasa*dc=dynamic_cast<DataCasa*>(p);
  if(dc!=NULL){
    propiedad= new Casa(dc->getCodigo(),dc->getCantAmbientes(),dc->getDormitorios(),dc->getBanios(),dc->getGaraje(),dc->getDireccion(),dc->getM2totales(),z,oferta,dc->getEspacioVerde(),dc->getM2edificados());//no se deberia pasar solo el datatype,lo voy a cambiar dsp
  }else{
    DataApartamento*da=dynamic_cast<DataApartamento*>(p);
    propiedad= new Apartamento(da->getCodigo(),da->getCantAmbientes(),da->getDormitorios(),da->getBanios(),da->getGaraje(),da->getDireccion(),da->getM2totales(),z,oferta,da->getM2edificados(),edificio);
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
	for(set<Propiedad*>::iterator it= props->begin();it!=props->end();++it ){
		res->insert((*it)->getDataInfoPropiedad(email));
	}
	delete props;
		return res;

}
Propiedad*ManejadorPropiedades::getPropiedad(int c){

	map<int,Propiedad*>::iterator it =propiedades->find(c);
		if(it!= propiedades->end()){
			return it->second;

		}else throw ExPropiedadNoExistente();

}
