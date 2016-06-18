#include "RutinaAltaPropiedad.h"

#include "DataInfoInmobiliaria.h"
#include "DataDetallePropiedad.h"
#include "DataDepartamento.h"
#include "DataZona.h"

#include "ProcesoCancelado.h"
#include "NoHayDepartamentos.h"
#include "ExDptoNoExistente.h"
#include "NoHayDepartamentoEnMemoria.h"
#include "ExNoHayZonas.h"
#include "NoExisteZona.h"
#include "NoHayPropiedades.h"
#include "ExPropiedadNoExistente.h"
#include "RutinaAltaEdificio.h"

#include "Factory.h"

#include <iostream>
#include <set>
#include <string>

#include "MenuUtils.h"

using namespace std;


RutinaAltaPropiedad::RutinaAltaPropiedad(){

  ctrl= Factory::getIPropiedadController();
}

RutinaAltaPropiedad::~RutinaAltaPropiedad(){

delete ctrl;
}


void RutinaAltaPropiedad::seleccionarDepartamento(){

  while (true) {
    try{
      MenuUtils::limpiarConsola();
    cout << "Alta Propiedad - Seleccion de Departamento" << endl;

    //obtener los departamentos
    set<DataDepartamento*>* departamentos = ctrl->listarDepartamentos();

    //se listan los departamentos luego se limpia la memoria
    cout << "Departamentos en el sistema:" << endl;
    for (set<DataDepartamento*>::iterator it=departamentos->begin(); it!=departamentos->end(); ++it) {
      DataDepartamento* dd = dynamic_cast<DataDepartamento*>(*it);
      cout<< *dd<< endl;
      delete dd;

    }

    departamentos->clear(); delete departamentos;
    //el usuario elige el departamento mediante su letra
    std::cout << "Ingrese letra del departamento donde se encuentra la propiedad" << std::endl;
    string letra = MenuUtils::leerString(); cout << endl;
			ctrl->seleccionarDepartamento(letra);
      break;
    }catch(ExDptoNoExistente& e){

      std::cout << e.what() << std::endl;
      if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
    }

  }

}

void RutinaConsultarPropiedad::seleccionarZona(){

  while (true) {
    try{
    MenuUtils::limpiarConsola();
    cout << "Alta Propiedad - Seleccion de Zona" << endl;

    //obtener las zonas
    set<DataZona*>* zonas = ctrl->listarZonas();

    //se listan los zonas luego se limpia la memoria
    cout << "Zonas en el sistema:" << endl;
    for (set<DataZona*>::iterator it=zonas->begin(); it!=zonas->end(); ++it) {
      DataZona* dz = dynamic_cast<DataZona*>(*it);
      cout << *dz<< endl;
      delete dz;

    }

    zonas->clear(); delete zonas;
    //el usuario elige la zona mediante su codigo
    std::cout << "Ingrese codigo de la zona  donde se encuentra la propiedad" << std::endl;
    int codigo = MenuUtils::leerInt(); cout << endl;
      ctrl->seleccionarZona(codigo);
      break;
    }catch(NoExisteZona& e){

      std::cout << e.what() << std::endl;
      if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) throw ProcesoCancelado();
    }

  }

}


void seleccionarEdificio(){
	while(true){

	}

}

void RutinaConsultarPropiedad::ejecutar(){

	while(true){
		try{
			bool salir = false;
			while(!salir){
				cout << "Menu Alta Propiedad: " << endl << endl;
				cout << "1 - Alta Propiedad." << endl;
				cout << "0 - Salir" << endl;
				int opt = MenuUtils::leerInt();
				MenuUtils::limpiarConsola();
				switch(opt){
					case 0:{
						MenuUtils::limpiarConsola();
						salir = true;
						break;
					}
					case 1:{
						seleccionarZona();
						seleccionarDepartamento();

						MenuUtils::limpiarConsola();
						break;
					}
					default:{
						cout<<"Opcion Invalida. Intente nuevamente.";
						MenuUtils::esperarInput();
						break;
					}
				}
			}
			MenuUtils::limpiarConsola();
			if(!MenuUtils::leerOpcion("Desea modificar otra propiedad?")) break;
		}catch(ProcesoCancelado&){
			MenuUtils::imprimirError("Modificacion cancelada.");
			if(!MenuUtils::leerOpcion("Desea modificar otra propiedad?")) break;
		}
		}


}


