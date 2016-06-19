#include "RutinaConsultarPropiedad.h"

#include "../DataTypes/DataInfoInmobiliaria.h"
#include "../DataTypes/DataDetallePropiedad.h"
#include "../DataTypes/DataDepartamento.h"
#include "../DataTypes/DataZona.h"

#include "../Excepciones/ProcesoCancelado.h"
#include "../Excepciones/NoHayDepartamentos.h"
#include "../Excepciones/ExDptoNoExistente.h"
#include "../Excepciones/NoHayDepartamentoEnMemoria.h"
#include "../Excepciones/ExNoHayZonas.h"
#include "../Excepciones/NoExisteZona.h"
#include "../Excepciones/NoHayPropiedades.h"
#include "../Excepciones/ExPropiedadNoExistente.h"

#include "../Fabrica/Factory.h"

#include <iostream>
#include <set>
#include <string>

#include "../Menus/MenuUtils.h"


RutinaConsultarPropiedad::RutinaConsultarPropiedad(){

  ctrl= Factory::getIPropiedadController();
}

RutinaConsultarPropiedad::~RutinaConsultarPropiedad(){

delete ctrl;
}

void RutinaConsultarPropiedad::seleccionarDepartamento(){

  while (true) {
    try{
      MenuUtils::limpiarConsola();
    cout << "Consultar Propiedad - Seleccion de Departamento" << endl;

    //obtener los departamentos
    set<DataDepartamento*>* departamentos = ctrl->listarDepartamentos();

    //se listan los departamentos luego se limpia la memoria
    cout << "Departamento en el sistema:" << endl;
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
    cout << "Consultar Propiedad - Seleccion de Zona" << endl;

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

void RutinaConsultarPropiedad::ejecutar(){

  while(true){
  		try{
  			//limpiar consola e imprimir encabezado
  			MenuUtils::limpiarConsola();
  			cout << "Consultar Datos de Propiedad." << endl << endl;

        seleccionarDepartamento();  MenuUtils::limpiarConsola();
        seleccionarZona();  MenuUtils::limpiarConsola();

  			set<DataDetallePropiedad*>* propiedades = ctrl->obtenerDetallePropiedad();

        cout << "Propiedades en el sistema: " << endl;

        for(std::set<DataDetallePropiedad*>::iterator it = propiedades->begin(); it != propiedades->end(); ++it){
          DataDetallePropiedad* cast = dynamic_cast<DataDetallePropiedad*>(*it);
          std::cout << *cast << std::endl;
          delete cast;
        }
  			//Comienza a imprimir en pantalla los propiedades en el sistema.
  			propiedades->clear(); delete propiedades;

  			//Se elige la propiedad
  			cout << "Ingrese el codigo de la propiedad que desea consultar: ";
  			int id_c = MenuUtils::leerInt();
  			MenuUtils::limpiarConsola();
		    ctrl->elegirPropiedadzona(id_c);

        DataInfoInmobiliaria* di=ctrl->informacionDetallada();

  			cout <<  *di << endl;
  			delete di;
  			MenuUtils::esperarInput();

  			MenuUtils::limpiarConsola();

  			if(MenuUtils::leerOpcion("Desea ver los datos de otra propiedad?")){
            delete ctrl;
            ctrl = Factory::getIPropiedadController();
        }else{
            break;
        }

  		}catch(NoHayDepartamentos& e){
  			std::cout << e.what() << std::endl;

  			MenuUtils::esperarInput();
  			break;
  		}catch(ExNoHayZonas& e){

  			std::cout << e.what() << std::endl;
  			if(MenuUtils::leerOpcion("Desea intentar nuevamente?")){
            delete ctrl;
				      ctrl = Factory::getIPropiedadController();
			  }else{
				      break;
			  }
  		}catch(NoHayPropiedades& e){

    		std::cout << e.what() << std::endl;
  			if(MenuUtils::leerOpcion("Desea intentar nuevamente?")){
          delete ctrl;
            ctrl = Factory::getIPropiedadController();
        }else{
              break;
        }

  	 }catch(ExPropiedadNoExistente& e){

       std::cout << e.what() << std::endl;
       if(MenuUtils::leerOpcion("Desea intentar nuevamente?")){
         delete ctrl;
           ctrl = Factory::getIPropiedadController();
       }else{
             break;
       }

    }catch(ProcesoCancelado&){
      cout << "Error: Se cancelo su consulta" << '\n';

        if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
          delete ctrl;
          ctrl = Factory::getIPropiedadController();
        }else{
          break;
        }

    }
  }
}
