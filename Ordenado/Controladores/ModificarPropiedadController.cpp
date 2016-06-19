#include "ModificarPropiedadController.h"

#include "../Manejadores/ManejadorPropiedades.h"
#include "../ClasesDeDominio/Inmobiliaria.h"
#include "../ClasesDeDominio/Sesion.h"
#include "../Excepciones/ProcesoCancelado.h"



ModificarPropiedadController::ModificarPropiedadController(){

  propiedad=NULL;
}

ModificarPropiedadController::~ModificarPropiedadController(){

}

DataPropiedad* ModificarPropiedadController::ObtenerPropiedad(int &codigo){
    ManejadorPropiedades* mp= ManejadorPropiedades::getInstancia();
    propiedad=mp->getPropiedad(codigo);
    Inmobiliaria*inm=dynamic_cast<Inmobiliaria*>(Sesion::getInstancia()->getUsuario());
  if(propiedad->getOferta()->getInmobiliaria()->getNombre()==inm->getNombre())throw ProcesoCancelado();
    return propiedad->getDataPropiedad();

}
void ModificarPropiedadController::guardarPropiedad(DataPropiedad*p){
  propiedad->modificarPropiedad(p);

}
