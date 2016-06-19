#include "Departamento.h"

#include <utility>
#include "../DataTypes/DataDepartamento.h"
#include "../Excepciones/ExNoHayZonas.h"
#include "../Excepciones/NoExisteZona.h"
#include "../Excepciones/YaExisteZona.h"

using namespace std;

Departamento::Departamento(const string &l,const string &nombre){
  this->letra=l;
  this->nombre=nombre;
  this->zonas= new std::map<int,Zona*>();
}
Departamento::Departamento(DataDepartamento*dd){
 this->letra=dd->get_letra();
 this->nombre=dd->get_nombre();
 this->zonas= new map<int,Zona*>();
}


//getters
const string& Departamento::getNombre() const{
  return nombre;
}
const string& Departamento::getLetra() const{
  return letra;
}

//getters de datatypes
DataDepartamento* Departamento::getDataDepartamento(){
  return new DataDepartamento(this->nombre,this->letra);

}
set<DataZona*>* Departamento::getDataZonas(){
    if (zonas->size()==0) throw ExNoHayZonas();
    set<DataZona*>*sdz= new set<DataZona*>;
    for (map<int,Zona*>::iterator it = zonas->begin(); it!=zonas->end(); it++) {
      sdz->insert(it->second->getDataZona());
    }
    return sdz;
}

//setters
void Departamento::setNombre(const string& nombre){
  this->nombre=nombre;
}
void Departamento::setLetra(const string& letra){
  this->letra=letra;
}

//Operaciones de zona
void Departamento::AddZona(Zona*z){

  if (!(zonas->find(z->getCodigo())!= zonas->end())) {
    this->zonas->insert(pair<int,Zona*>(z->getCodigo(),z));
  }else{
    throw YaExisteZona();
  }
}

Zona* Departamento::ObtenerZona(int codigo){
  map<int,Zona*>::iterator it=this->zonas->find(codigo);
  if (it!=zonas->end()) {
    return it->second;
  } else {
    throw NoExisteZona();
  }

}
void Departamento::borrarZona(int codigo){
  this->zonas->erase(codigo);

}

//Destructor
 Departamento::~Departamento(){
  //se libera la memoria de las zonas que implica eliminar las propiedades de esa zona
  for(map<int,Zona*>::iterator it = this->zonas->begin();it!=zonas->end();++it){
		delete it->second;
	}
	zonas->clear();
	delete zonas;

}
