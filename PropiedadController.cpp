#include "PropiedadController.h"

#include "Usuario.h"
#include "Sesion.h"
#include "Venta.h"
#include "Alquiler.h"
#include "ManejadorDepartamentos.h"
#include "ManejadorEdificios.h"
#include "Manejador_Usuario.h"
#include "Manejador_Propiedad.h"

#include "PrecioInvalido.h"
#include "YaExistePropiedad.h"
#include "ValoresInvalidos.h"
#include "NoHayDepartamentoEnMemoria.h"

using namespace std;

PropiedadController::PropiedadController() {
    this->zona=NULL;
    this->da=NULL;
    this->dv=NULL;
    this->propiedad=NULL;
    this->edificio=NULL;
    this->dp=NULL;
    this->dpto=NULL;
}
PropiedadController::~PropiedadController(){
  if(da!=NULL) delete da;
    if (dv!= NULL) delete dv;
      if (dp != NULL) delete dp;

  dpto=NULL;
  edificio=NULL;
  zona=NULL;

}

//ALTA PROPIEDAD

void PropiedadController::confirmarAltaPropiedad() {

Sesion*sesion= Sesion::getInstancia();
Inmobiliaria*i= sesion->getUsuario();
Oferta*oferta;
  if (da!=NULL && dv!=NULL) {
    oferta = new Oferta(new Venta(dv->getPrecio()),new Alquiler(da->getPrecio()),NULL,i);
    delete dv;
    delete da;
  } else if (da!=NULL) {
    oferta = new Oferta(NULL,new Alquiler(da->getPrecio()),NULL,i);
    delete da;
  } else {
    oferta = new Oferta(new Venta(dv->getPrecio()),NULL,NULL,i);
    delete dv;
  }

  Manejador_Propiedad*mp= Manejador_Propiedad::getInstancia();
  this->propiedad=mp->crearPropiedad(dp,zona,oferta,edificio);
  i->AgregarOferta(oferta);

   delete dp;
   propiedad=NULL;
   zona=NULL;
   edificio=NULL;
   dpto=NULL;
}


void PropiedadController::ingresarNuevaCasa(DataPropiedad* casa){
  if (ManejadorPropiedades::getInstancia()->ExistePropiedad(casa->getCodigo())){
    throw YaExistePropiedad();
  }
  if(casa->getCantAmbientes()<0 || casa->getDormitorios()<0 || casa->getBanios()<0 || casa->getm2edificados()<=0
    || casa->getEspacioVerde()<0){
    throw ValoresInvalidos();
  }


  this->dp=casa;

}

void PropiedadController::ingresarPrecioAlquiler(DataAlquiler* pAlquiler){
  if(pAlquiler->getPrecio() <= 0) throw PrecioInvalido();
  this->da=pAlquiler;

}

void PropiedadController::ingresarNuevoApartamento(DataPropiedad* apartamento){

  if(apartamento->getCantAmbientes()<0 || apartamento->getDormitorios()<0 || apartamento->getBanios()<0 ||
    apartamento->getm2edificados()<=0{
    throw ValoresInvalidos();
  }
  if (ManejadorPropiedades::getInstancia()->ExistePropiedad(apartamento->getCodigo())){
    throw YaExistePropiedad();
  }

  this->dp=apartamento;
}

void PropiedadController::ingresarPrecioVenta(DataVenta* pVenta){
  if(pVenta->getPrecio() <= 0) throw PrecioInvalido();
  this->dv=pVenta;
}

set<DataDepartamento*>* PropiedadController::listarDepartamentos(){

  ManejadorDepartamentos*md= ManejadorDepartamentos::getInstancia();
  set<DataDepartamento*>* res =md->getDepartamentos();
  return res;

}

set<DataEdificio*>* PropiedadController::listarEdificios(){

  ManejadorEdificios* me=ManejadorEdificios::getInstancia();
  set<DataEdificio*>* res = me->getEdificios();
  return res;
}

set<DataZona*>* PropiedadController::listarZonas(){
	if(dpto == NULL) throw NoHayDepartamentoEnMemoria();
  set<DataZona*>* res= dpto->getDataZonas();
  return res;

}

void PropiedadController::seleccionarDepartamento(string& letra){

  ManejadorDepartamentos*md= ManejadorDepartamentos::getInstancia();
  this->dpto= md->getDepartamento(letra);

}

void PropiedadController::seleccionarZona(int codigo){
  if(dpto == NULL) throw NoHayDepartamentoEnMemoria();
  this->zona= dpto->ObtenerZona(codigo);

}

void PropiedadController::seleccionarEdificio(const string& nombre){

  ManejadorEdificios* me=ManejadorEdificios::getInstancia();
  this->edificio= me->getEdificio(nombre);
}


//caso de uso eliminarPropiedad
void PropiedadController::eliminarPropiedad(int codigo){

  ManejadorPropiedades* mp = ManejadorPropiedades::getInstancia();
  mp->eliminarPropiedad(codigo);
}


//caso de uso enviarMensaje interesado
void PropiedadController::enviarMensaje(DataMensaje* mensaje){

Sesion*sesion = Sesion::getInstancia();
string email = sesion->getUsuario()->get_email();

  propiedad->ingresarMensaje(email,mensaje);
  //sujeto a cambios, me parece q es mejor si el interesado ingresa el mensaje y si no hay chat el lo crea.


}

set<DataMensaje*>* PropiedadController::listarMensajes(){
  Sesion* sesion = Sesion::getInstancia();
  Interesado*interesado= dynamic_cast<Interesado*>(&sesion->getUsuario());

  set<DataMensaje*>* dm = interesado->ObtenerDataMensajes(propiedad->getCodigo());

  return dm;
}

set<DataInfoPropiedad*>* PropiedadController::obtnerConversaciones(){

  ManejadorPropiedades*mp= ManejadorPropiedades::getInstancia();
  Sesion*sesion= Sesion::getInstancia();
  string email= sesion->getUsuario()->get_email();

  set<DataInfoPropiedad*>* dip = mp->getConversacionesPropiedad(zona,email);
  return dip;

}
void PropiedadController::seleccionarPropiedad(int codigo){

    ManejadorPropiedades*mp= ManejadorPropiedades::getInstancia();
    this->propiedad= mp->getPropiedad(codigo);

}

//Alta Edificio
void PropiedadController::IngresarEdificio(DataEdificio*de){

  ManejadorEdificios* me= ManejadorEdificios::getInstancia();
  me->addEdificio(de);
  //en el caso de uso altaPropiedad el usuario puede elegir crear un Edificio
  //por lo que capaz este caso de uso deberia devolver el edificio creado.
}


//caso de uso consultarPropiedad

set<DataDetallePropiedad*>* PropiedadController::obtenerDetallePropiedad(){

  set<DataDetallePropiedad*>* result= zona->getDataDetallePropiedad();

  return result;

}

DataInfoInmobiliaria* PropiedadController::informacionDetallada(){
  set<DataReportePropiedad*>* reportes= set<DataReportePropiedad*>();
  //me fijo si la propiedad esta en venta y/o alquiler
  if (propiedad->getOferta()->ExisteVenta()) {
    float preciov =propiedad->getOferta()->getVenta()->getPrecio();
  } else {
    float preciov=0;
  }
  if (propiedad->getOferta()->ExisteAlquier()) {
    float precioa =propiedad->getOferta()->getAlquiler()->getPrecio();
  } else {
    float precioa=0;
  }
  //creo los datos de la propiedad sin la zona y departamento.
  reportes->insert(new DataReportePropiedad(propiedad->getCodigo(),propiedad->getCantDeAmbientes(),
  propiedad->getDormitorios(),propiedad->getBanios(),propiedad->getGaraje(),propiedad->getDireccion(),preciov,precioa,NULL,NULL));
  //pido la inmobiliaria de la propiedad
  Inmobiliaria*i= propiedad->getOferta()->getInmobiliaria();
  //retorno el datatype con los datos de la inmobiliaria y la propiedad
  return new DataInfoInmobiliaria(i->getNombre(),getDireccion(),get_email(),reportes);

}
