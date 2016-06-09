#include "Zona.h"
#include "Departamento.h"

#include <utility>

using namespace std;

Zona :: Zona(int c,string n,Departamento* &d){
    this->codigo=c;
    this->nombre=n;
    this->departamento=d;
    this->propiedades= new map<int,Propiedad*>();
}

void Zona::setCodigo(int cod){

  this->codigo= cod;
}

void Zona::setNombre(string& name){
  this->nombre = name
}


int Zona :: getCodigo(){
    return this->codigo;
}

string Zona :: getNombre(){
    return this->nombre;
}

Departamento* Zona :: getDepartamento(){
    return this->departamento;
}

DataZona* Zona :: getDataZona(){
    return new DataZona(this->codigo,this->nombre);
}

DataDepartamento* Zona::getDataDepartamento(){

	return this->departamento->getDataDepartamento();
}



void Zona :: AgregarPropiedad(Propiedad* p){
    propiedades->insert(pair<int,Propiedad*>(p->getCodigo(),p));
}

void Zona :: RemoverPropiedad(int& codigo){
    propiedades->erase(codigo);
}


set<Propiedad*>* Zona::getPropiedades(){

    set<Propiedad*>* res=new set<Propiedad*>();
    for (map<int,Propiedad*>::iterator it= propiedades->begin(); it!=propiedades->end(); ++it){
        res[it->first]=it->second;
    }
    return res;
}

Zona::~Zona(){
  this->departamento->borrarZona(this->codigo);
    map<int,Propiedad*>::iterator it;
    for (it= propiedades->begin(); it!=propiedades->end(); ++it){
        delete it->second;
    }
    propiedades->clear();
    delete propiedades;
}
