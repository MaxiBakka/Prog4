#include <iostream>
#include <set>
#include "Factory.h"
#include "DatosYaCargados.h"
#include "ExOpcionInvalida.h"
#include "UserInterface.h"
#include "RutinaInicioSesion.h"
#include "RutinaCargarDatos.h"
#include "ManejadorDepartamentos.h"
#include "ManejadorEdificios.h"
#include "ManejadorPropiedades.h"
#include "Manejador_Usuario.h"
#include "MenuPrincipal.h"

using namespace std;

int main(){
	UserInterface* carga = new RutinaCargarDatos();
	carga->ejecutar();
  delete carga;

  MenuPrincipal*submenu= new MenuPrincipal();
	submenu->ejecutar();
	delete submenu;
	Manejador_Usuario* mu = Manejador_Usuario::getInstancia();
	ManejadorDepartamentos* md = ManejadorDepartamentos::getInstancia();
	ManejadorEdificios * me= ManejadorEdificios::getInstancia();
	ManejadorPropiedades* mp = ManejadorPropiedades::getInstancia();
	delete mp; delete md; delete me; delete mu;

}
