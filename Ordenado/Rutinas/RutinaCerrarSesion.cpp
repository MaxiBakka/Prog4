#include "RutinaCerrarSesion.h"

#include "Factory.h"
#include "Menu.h"

#include <iostream>
#include <string>

using namespace std;


RutinaCerrarSesion::RutinaCerrarSesion{
  ctrl= Factory::getIUsuarioController();
}

RutinaCerrarSesion::~RutinaCerrarSesion{

  delete ctrl;
}

void RutinaCerrarSesion::ejecutar{

      if (MenuUtils::leerOpcion("Realmente desea cerrar sesion?")) {
        IOConsola::limpiarConsola();
        ctrl->CerrarSesion();
        std::cout << "Sesion cerrada con exito" << std::endl;
        Menu::salirDelSistema();
      }

  IOConsola::limpiarConsola();

}
