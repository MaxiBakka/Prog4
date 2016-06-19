#include "RutinaCerrarSesion.h"

#include "../Fabrica/Factory.h"
#include "../Menus/Menu.h"
#include "../Menus/MenuUtils.h"


#include <iostream>
#include <string>

using namespace std;


RutinaCerrarSesion::RutinaCerrarSesion(){
  ctrl= Factory::getIUsuarioController();
}

RutinaCerrarSesion::~RutinaCerrarSesion(){

  delete ctrl;
}

void RutinaCerrarSesion::ejecutar(){

      if (MenuUtils::leerOpcion("Realmente desea cerrar sesion?")) {
        MenuUtils::limpiarConsola();
        ctrl->CerrarSesion();
        std::cout << "Sesion cerrada con exito" << std::endl;

      }
    MenuUtils::esperarInput();
  MenuUtils::limpiarConsola();

}
