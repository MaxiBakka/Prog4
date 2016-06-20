#include <iostream>
#include <set>
#include "../Fabrica/Factory.h"
#include "../Excepciones/DatosYaCargados.h"
#include "../Excepciones/ExOpcionInvalida.h"
#include "../Interfaces/UserInterface.h"
#include "../Rutinas/RutinaInicioSesion.h"
#include "../Rutinas/RutinaCargarDatos.h"
#include "../Manejadores/ManejadorDepartamentos.h"
#include "../ManejadoresManejadorEdificios.h"
#include "../ManejadoresManejadorPropiedades.h"
#include "../ManejadoresManejador_Usuario.h"
#include "../Menus/MenuPrincipal.h"

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
