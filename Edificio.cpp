#include "Edificio.h"


Edificio :: Edificio(const string& nombre,int cantPisos,float gcomunes){
    nombre=nombre;
    cantPisos=cantPisos;
    gastosComunes=gastosComunes;
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
    gastosComunes=gc;
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
apartamentos->insert(pair<int,Apartamento*>(apto->getCodigo,apto));

}
void Edificio::RemoverApartamento(int& codigo){
  apartamentos->erase(codigo);

}

bool Edificio::ExisteApartamento(int &codigo){
    return apartamentos->find(codigo)!=apartamentos->end();

}

Edificio::~Edificio(){

  for (map<int,Apartamento*>::iterator it= apartamentos->begin(); it!=apartamentos->end(); ++it){
      delete it->second;
  }
  delete apartamentos;

}
