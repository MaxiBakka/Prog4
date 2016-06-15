#include "ModificarPropiedadController.h"

#include "ManejadorPropiedades.h"
#include "Propiedad.h"


ModificarPropiedadController::ModificarPropiedadController(){

  propiedad=NULL;
}

ModificarPropiedadController::~ModificarPropiedadController(){

}

DataPropiedad* ModificarPropiedadController::ObtenerPropiedad(int &codigo){
    ManejadorPropiedades* mp= ManejadorPropiedades::getInstancia();
    propiedad=mp->getPropiedad(codigo);
    return propiedad->getDataPropiedad();

}
void ModificarPropiedadController::guardarPropiedad(DataPropiedad*p){
  propiedad->modificarPropiedad(p);

}
