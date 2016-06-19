#ifndef CARGARDATOSCONTROLLER_H
#define CARGARDATOSCONTROLLER_H

#include <map>
#include <string>

#include "../ClasesDeDominio/Departamento.h"
#include "../ClasesDeDominio/Zona.h"
#include "../ClasesDeDominio/Propiedad.h"
#include "../ClasesDeDominio/Administrador.h"
#include "../ClasesDeDominio/Inmobiliaria.h"
#include "../ClasesDeDominio/Edificio.h"
#include "../ClasesDeDominio/Interesado.h"
#include "../ClasesDeDominio/Mensaje.h"
#include "../ClasesDeDominio/Apartamento.h"
#include "../ClasesDeDominio/Casa.h"
#include "../ClasesDeDominio/Administrador.h"
#include "../Interfaces/ICargarDatosController.h"

using namespace std;

class CargarDatosController:public ICargarDatosController{
private:
  static bool DatosCargados;

  virtual void cargarDepartamentos();
  virtual void cargarZonas();
  virtual void cargarApartamentos();
  virtual void cargarCasas();
  virtual void cargarInmobiliarias();
  virtual void cargarInteresados();
  virtual void cargarEdificios();
  virtual void cargarMensajes();
  virtual void cargarAdministrador();

  //Atributos que guarden las referencias como en el pdf.
  map<string,Departamento*>* refDepartamentos;
  map<string,Zona*>* refZonas;
  map<string,Edificio*>* refEdificios;
  map<string,Inmobiliaria*>* refInmobiliarias;
  map<string,Interesado*>* refInteresados;
  map<string,Propiedad*>* refCasas;
  map<string,Chat*>* refChats;
  map<string,Propiedad*>* refApartamentos;
  Administrador* administrador;

public:
  CargarDatosController();
  virtual ~CargarDatosController();
  virtual void cargarDatosdeSistema();

};

#endif
