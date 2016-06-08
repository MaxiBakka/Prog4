#include "Propiedad.h"
#include "Zona.h"

Propiedad::Propiedad(int cod, int cda, int dormi, int banios, bool garaje, string dir, float m2t,Zona* z) {
    this->codigo=cod;
    this->cantDeAmbientes=cda;
    this->dormitorios=dormi;
    this->Banios=banios;
    this->garaje=garaje;
    this->direccion=dir;
    this->m2Totales=m2t;
    this->zona=z;
    this->alquiler=NULL;
    this->venta=NULL;
    this->zona->AgregarPropiedad(this);
}

Alquiler* Propiedad::getAlquiler() {
    return this->alquiler;
}

int Propiedad::getBanios() {
    return this->Banios;
}

int Propiedad::getCantDeAmbientes() {
    return this->cantDeAmbientes;
}

int Propiedad::getCodigo() {
    return this->codigo;
}

string Propiedad::getDireccion() {
    return this->direccion;
}

int Propiedad::getDormitorios() {
    return this->dormitorios;
}

bool Propiedad::getGaraje() {
    return this->garaje;
}

float Propiedad::getM2Totales() {
    return this->m2Totales;
}

Venta* Propiedad::getVenta() {
    return this->venta;
}

Zona* Propiedad::getZona() {
    return this->zona;
}

Propiedad::~Propiedad() {
    if(this->venta!=NULL){
    this->venta->~Venta();
    }
    if(this->alquiler!=NULL){
    this->alquiler->~Alquiler();
    }
    //aca hay que ver como hacer para que la inmobiliaria tambien remueva dichas ventas y alquileres de sus colecciones
}









