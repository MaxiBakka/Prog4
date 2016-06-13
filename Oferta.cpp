#include "Oferta.h"



Oferta::Oferta(Venta* v,Alquiler* a,Propiedad* p,Inmobiliaria* i){
  this->venta=v;
    this->alquiler=a;
      this->propiedad=p;
        this->inmobiliaria=i;
}

Oferta::~Oferta(){

  if(alquiler!=NULL) delete alquiler;
  if(venta!=NULL) delete venta;
  inmobiliaria->borrarOferta(this);
  //propiedad->borrarOferta(this);
}

bool Oferta::ExisteVenta(){

  return (this->venta!=NULL);
}

bool Oferta::ExisteAlquier(){

  return (this->alquiler!=NULL);
}

Venta* Oferta::getVenta(){
  return this->venta;
}

Alquiler* Oferta::getAlquiler(){
  return this->alquiler;
}

Propiedad* Oferta::getPropiedad(){

  return this->propiedad;
}

Inmobiliaria* Oferta::getInmobiliaria(){

  return this->inmobiliaria;
}
//SETTERS
void Oferta::setVenta(float precio){

  this->venta->setPrecio(precio);
}
void Oferta::setAlquiler(float precio){

  this->alquiler->setPrecio(precio);
}

void Oferta::setPropiedad(Propiedad* prop){
  this->propiedad= prop;
}


DataReportePropiedad* Oferta::getDataReportePropiedad(){

  return this->propiedad->getDataReportePropiedad();

}

int Oferta::getCodigoPropiedad(){

return this->propiedad->getCodigo();

}
