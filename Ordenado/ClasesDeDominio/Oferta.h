#ifndef Oferta_h
#define Oferta_h

#include "Venta.h"
#include "Alquiler.h"
#include "Inmobiliaria.h"
#include "Propiedad.h"
#include "../DataTypes/DataReportePropiedad.h"

class Oferta {
private:
  Venta * venta;
  Alquiler * alquiler;
  Propiedad * propiedad;
  Inmobiliaria * inmobiliaria;
public:
  Oferta(Venta* v,Alquiler* a,Propiedad* p,Inmobiliaria* i);
  virtual ~Oferta ();

  bool ExisteVenta();
  bool ExisteAlquier();

  Venta* getVenta();
  Alquiler* getAlquiler();
  Propiedad* getPropiedad();
  Inmobiliaria* getInmobiliaria();

  void setPropiedad(Propiedad* prop);
  //void setInmobiliaria(Inmobiliaria* i);
  void setVenta(float precio);
  void setAlquiler(float precio);

  DataReportePropiedad* getDataReportePropiedad();
  int getCodigoPropiedad();


};

#endif
