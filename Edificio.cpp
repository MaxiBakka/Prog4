#include "Edificio.h"

Edificio :: Edificio(){
    this->nombre='';
    this->cantPisos=-1;
    this->gastosComunes=-1;
}

Edificio :: Edificio(string n,int cp,float gc){
    this->nombre=n;
    this->cantPisos=cp;
    this->gastosComunes=gc;
}

string& Edificio :: getNombre(){
    return nombre;
}

int Edificio :: getCantPisos(){
    return cantPisos;
}

float Edificio :: getGastosComunes(){
    return gastosComunes;
}

void Edificio :: setGastosComunes(float &gc){
    gastosComunes=gc;
}

DataEdificio Edificio :: getDataEdificio(){
    return DataEdificio(this->nombre,this->cantPisos,this->gastosComunes);
}

Edificio :: ~Edificio(){}

