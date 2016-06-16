#include "PropiedadController.h"

#include "Usuario.h"
#include "Sesion.h"
#include "Venta.h"
#include "Alquiler.h"
#include "Chat.h"
#include "Oferta.h"
#include "ManejadorDepartamentos.h"
#include "ManejadorEdificios.h"
#include "Manejador_Usuario.h"
#include "ManejadorPropiedades.h"

#include "DataCasa.h"
#include "DataApartamento.h"

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
Inmobiliaria*i= dynamic_cast<Inmobiliaria*>(sesion->getUsuario());
Oferta*oferta;
  if (da!=NULL && dv!=NULL) {
    oferta = new Oferta(new Venta(dv->get_precio()),new Alquiler(da->get_precio()),NULL,i);
    delete dv;
    delete da;
  } else if (da!=NULL) {
    oferta = new Oferta(NULL,new Alquiler(da->get_precio()),NULL,i);
    delete da;
  } else {
    oferta = new Oferta(new Venta(dv->get_precio()),NULL,NULL,i);
    delete dv;
  }

  ManejadorPropiedades*mp= ManejadorPropiedades::getInstancia();
  this->propiedad=mp->crearPropiedad(dp,zona,oferta,edificio);
  i->AgregarOferta(oferta);

   delete dp;
   propiedad=NULL;
   zona=NULL;
   edificio=NULL;
   dpto=NULL;
}


void PropiedadController::ingresarNuevaCasa(DataPropiedad* casa){
DataCasa*house;
  if (ManejadorPropiedades::getInstancia()->ExistePropiedad(casa->getCodigo())){
    throw YaExistePropiedad();
  }
  house=dynamic_cast<DataCasa*>(casa);
  if(house->getCantAmbientes()<0 || house->getDormitorios()<0 || house->getBanios()<0 || house->getM2edificados()<=0
    || house->getEspacioVerde()<0){
    throw ValoresInvalidos();
  }


  this->dp=house;

}

void PropiedadController::ingresarPrecioAlquiler(DataAlquiler* pAlquiler){
  if(pAlquiler->get_precio() <= 0) throw PrecioInvalido();
  this->da=pAlquiler;

}

void PropiedadController::ingresarNuevoApartamento(DataPropiedad* apartamento){
DataApartamento*apto=dynamic_cast<DataApartamento*>(apartamento);

  if(apto->getCantAmbientes()<0 || apto->getDormitorios()<0 || apto->getBanios()<0 ||
    apto->getM2edificados()<=0){
    throw ValoresInvalidos();
  }

  if (ManejadorPropiedades::getInstancia()->ExistePropiedad(apto->getCodigo())){
    throw YaExistePropiedad();
  }

  this->dp=apto;
}

void PropiedadController::ingresarPrecioVenta(DataVenta* pVenta){
  if(pVenta->get_precio() <= 0) throw PrecioInvalido();
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

  if(this->propiedad->ExisteChat(email)){
    this->propiedad->ingresarMensaje(mensaje,email);
  }
  else{
    Interesado*interesado= dynamic_cast<Interesado*>(sesion->getUsuario());
    Inmobiliaria*inmobiliaria=propiedad->getOferta()->getInmobiliaria();
    Chat*chat= new Chat(email,inmobiliaria->getNombre(),this->propiedad,interesado,inmobiliaria);
    chat->nuevoMensaje(mensaje);
    inmobiliaria->agregarChat(chat);
    propiedad->AgregarChat(chat);
    interesado->AgregarChat(chat);
  }
}

set<DataMensaje*>* PropiedadController::listarMensajes(){
  Sesion* sesion = Sesion::getInstancia();
  Interesado*interesado= dynamic_cast<Interesado*>(sesion->getUsuario());

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
  set<DataReportePropiedad*>* reportes=new  set<DataReportePropiedad*>();
  //me fijo si la propiedad esta en venta y/o alquiler
  float preciov=0;
  float precioa=0;

  if (propiedad->getOferta()->ExisteVenta()) {
    preciov =propiedad->getOferta()->getVenta()->getPrecio();
  }

  if (propiedad->getOferta()->ExisteAlquier()) {
     precioa =propiedad->getOferta()->getAlquiler()->getPrecio();
  }
  //creo los datos de la propiedad sin la zona y departamento.
  reportes->insert(new DataReportePropiedad(propiedad->getCodigo(),propiedad->getCantDeAmbientes(),
  propiedad->getDormitorios(),propiedad->getBanios(),propiedad->getGaraje(),propiedad->getDireccion(),preciov,precioa,NULL,NULL));
  //pido la inmobiliaria de la propiedad
  Inmobiliaria*i= propiedad->getOferta()->getInmobiliaria();
  //retorno el datatype con los datos de la inmobiliaria y la propiedad
  return new DataInfoInmobiliaria(i->getNombre(),i->getDireccion(),i->get_email(),reportes);

}
