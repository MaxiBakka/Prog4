#include "Zona.h"

Zona :: Zona(int c,string n,Departamento* &d){
    this->codigo=c;
    this->nombre=n;
    this->departamento=d;
    this->propiedades= new map<int,Propiedad*>();
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

void Zona :: AgregarPropiedad(Propiedad* p){
    propiedades[p->getCodigo()]=p;
}

void Zona :: RemoverPropiedad(Propiedad* p){
    propiedades->erase(p->getCodigo());
}

map<int,Propiedad*>* Zona :: getPropiedades(){
    res=new map<int,Propiedad*>();
    for (map<int,Propiedad*>::iterator it= propiedades->begin(); it!=propiedades->end(); ++it){
        res[it->first]=it->second;
    }
    return res;
}

~Zona(){
    map<int,Propiedad*>::iterator it;
    for (it= propiedades->begin(); it!=propiedades->end(); ++it){
        delete it->second;
    }
}
