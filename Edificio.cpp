#include "Edificio.h"
 #include <utility>

Edificio :: Edificio(const string& nombre,int cantPisos,float gcomunes){
  if(de->get_gastosComunes < 0 || de->get_cantPisos < 1) throw ExValoresNoPositivos;
    nombre=nombre;
    cantPisos=cantPisos;
    gastosComunes=gcomunes;
    this->apartamentos= new map<int,Apartamento*>();
}

Edificio::Edificio(DataEdificio*de){
  if(de->get_gastosComunes < 0 || de->get_cantPisos < 1) throw ExValoresNoPositivos;
  this->nombre=de->get_nombreNombre();
  this->gastosComunes=de->get_gastosComunes();
  this->cantPisos=de->get_cantPisos();
  this->apartamentos= new map<int,Apartamento*>();
}

//getters
const string& Edificio :: getNombre(){
    return nombre;
}

int Edificio :: getCantPisos(){
    return cantPisos;
}

float Edificio :: getGastosComunes(){
    return gastosComunes;
}
//setters
void Edificio::setGastosComunes(float &gcomunes){
    gastosComunes=gcomunes;
}
void Edificio::setNombre(const string& nombre){

  this->nombre=nombre;
}
void Edificio::setCantPisos(int cantPisos){

  this->cantPisos=cantPisos;
}


DataEdificio* Edificio :: getDataEdificio(){
    return new DataEdificio(this->nombre,this->cantPisos,this->gastosComunes);
}

void Edificio::agregarApartamento(Apartamento*apto){
apartamentos->insert(pair<int,Apartamento*>(apto->getCodigo(),apto));

}
void Edificio::RemoverApartamento(int codigo){
  apartamentos->erase(codigo);

}

bool Edificio::ExisteApartamento(int codigo){
    return apartamentos->find(codigo)!=apartamentos->end();

}

Edificio::~Edificio(){

  for (map<int,Apartamento*>::iterator it= apartamentos->begin(); it!=apartamentos->end(); ++it){
      delete it->second;
  }
  apartamentos->clear();

  delete apartamentos;

}
