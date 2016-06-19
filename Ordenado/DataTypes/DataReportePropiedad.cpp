#include "DataReportePropiedad.h"


DataReportePropiedad::DataReportePropiedad(int c,int cda, int d,int b,bool g,string &dir,float iv,float ia,DataZona* dz,DataDepartamento* dpto) {
    this->codigo=c;
    this->cantDeAmbientes=cda;
    this->dormitorios=d;
    this->banios=b;
    this->garaje=g;
    this->direccion=dir;
    this->infoAlquiler=ia;
    this->infoVenta=iv;
    this->ddpto=dpto;
    this->dzona=dz;

}

int DataReportePropiedad::getBanios() {
    return this->banios;
}

int DataReportePropiedad::getCantDeAmbientes() {
    return this->cantDeAmbientes;
}

int DataReportePropiedad::getCodigo() {
    return this->codigo;
}

int DataReportePropiedad::getDormitorios() {
    return this->dormitorios;
}

bool DataReportePropiedad::getGaraje() {
    return this->garaje;
}

float DataReportePropiedad::getInfoAlquiler() {
    return this->infoAlquiler;
}

float DataReportePropiedad::getInfoVenta() {
    return this->infoVenta;
}

string DataReportePropiedad::getDireccion(){
  return this->direccion;
}

DataDepartamento* DataReportePropiedad::getDataDepartamento() {
    return this->ddpto;
}

DataZona* DataReportePropiedad::getDataZona() {
    return this->dzona;
}

DataReportePropiedad::~DataReportePropiedad(){
  delete this->dzona;
  delete this->ddpto;

}
