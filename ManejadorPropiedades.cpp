#include "ManejadorPropiedades.h"

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
 void ManejadorPropiedades::crearPropiedad(DataPropiedad* p,Zona z){

//

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
	set<DataInfoPropiedad*>* res= set<DataInfoPropiedad*>();

	set<Propiedades*>* props = z->getPropiedades();
	for(set<Propiedades*>::iterator it= props->begin();it!=props->end();++it ){
		res->insert(*it->getDataInfoPropiedad());

	}
		return res;

}
Propiedad*ManejadorPropiedades::getPropiedad(int c){

	map<int,Propiedad*>::iterator it =propiedades->find(c);
		if(it!= propiedades->end()){
			return it->second;

		}else throw ExPropiedadNoExistente();

}
