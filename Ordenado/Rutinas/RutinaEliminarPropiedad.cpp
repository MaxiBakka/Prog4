#include "RutinaEliminarPropiedad.h"

#include "../Excepciones/ExPropiedadNoExistente.h"
#include "../Excepciones/ProcesoCancelado.h"
#include "../Fabrica/Factory.h"

#include <iostream>
#include <set>
#include <string>

#include "../Menus/MenuUtils.h"

RutinaEliminarPropiedad::RutinaEliminarPropiedad(){
  ctrl= Factory::getIPropiedadController();
}

RutinaEliminarPropiedad::~RutinaEliminarPropiedad(){
  delete ctrl;
}

void RutinaEliminarPropiedad::eliminarPropiedad(){
  while(true){
    try{

      cout << "Eliminar Propiedad" << endl;

      //el usuario ingresa el codigo de la propiedad que quiere eliminar
      cout << "Ingrese el codigo de la propiedad que quiere eliminar: " << endl;
      int cod = MenuUtils::leerInt(); cout << endl;
      if(MenuUtils::leerOpcion("Realmente quiere eliminar la propiedad? ")){
          ctrl->eliminarPropiedad(cod);
         cout <<"Propiedad eliminada con exito" << endl;
          MenuUtils::esperarInput();
          break;
      }else{
        if(!MenuUtils::leerOpcion("Desea intentarlo nuevamente? ")) throw ProcesoCancelado();
      }
    }catch(ExPropiedadNoExistente &e){
      cout << e.what() << endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }
  }

}

void RutinaEliminarPropiedad::ejecutar(){
  while(true){
    try{
      cout << "Bienvenida Inmobiliaria" << endl;
      cout << "Eliminar Propiedades" << endl << endl;

      eliminarPropiedad();
      MenuUtils::limpiarConsola();

      if(MenuUtils::leerOpcion("Desea eliminar otra Propiedad? ")){
        delete ctrl;
        ctrl = Factory::getIPropiedadController();
      }else{
        break;
      }
    }catch(ProcesoCancelado& ){

      cout << "Error: se cancelo la eliminacion de la Propiedad" << endl;

      if(MenuUtils::leerOpcion("Desea empezar de nuevo? ")){
        delete ctrl;
        ctrl = Factory::getIPropiedadController();
        MenuUtils::limpiarConsola();
      }else{
        break;
      }
    }
  }
}
