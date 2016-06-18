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
		try{
			bool salir = false;
			MenuUtils::limpiarConsola();
			cout << "Alta Propiedad - Seleccion de Edificio" << endl;
			cout << "Edificios en sistema: "<<endl;
			set<DataEdificio*>* listaEd = ctrl->listarEdificios();
			cout << *listaEd<< endl<<endl;
			cout<< "1 - Seleccionar Edificio"<<endl;
			cout<< "2 - Ingresar Nuevo Edificio"<<endl;
			cout<< "0 - Salir"<<endl;
			int opt = MenuUtils::leerInt();
			MenuUtils::limpiarConsola();
			switch(opt){
				case 0:{
					MenuUtils::limpiarConsola();
					salir = true;
					break;
				}
				case 1:{
					cout<<"Ingrese el nombre del edificio: ";
					string nameEd = MenuUtils::leerString();
					ctrl->seleccionaEdificio(nameEd);
					MenuUtils::limpiarConsola();
					break;
				}
				case 2:{
					UserInterface* submenu = new RutinaAltaEdificio();
					submenu->ejecutar();
					string nameEd = submenu->getNombreEdificio();
					ctrl->seleccionarEdificio(nameEd);
					delete subemenu;
					break;
				}
				default:{
					cout<<"Opcion Invalida. Intente nuevamente.";
					MenuUtils::esperarInput();
					break;
				}
			}

		}catch(EdificioNoExistente& e){
			MenuUtils::limpiarConsola();
			cout<< e.what()<<endl;
			if(!MenuUtils::leerOpcion("Desea intentarlo de nuevo?")) break;
		}
	}

}

void RutinaAltaPropiedad::ingresarAlquilerVenta(){
  while(true){
    try{
      if(MenuUtils::leerOpcion("Esta casa estara a la venta? ")){
        cout << "Ingrese el precio de venta: " << endl;
        venta=MenuUtils::leerFloat();
      }else{
        venta=-1;
      }
      if(MenuUtils::leerOpcion("Esta casa estara para alquilar? ")){
        cout << "Ingrese el precio de alquiler: " << endl;
        alquiler=MenuUtils::leerFloat();
      }else{
        alquiler=-1;
      }
      if((venta<0 && alquiler<0)) throw ProcesoCancelado();
    }catch(ProcesoCancelado& ){
        cout << "Error: debe agregar al menos uno de los datos." <<endl;
        if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
          delete ctrl;
          ctrl = Factory::getIPropiedadController();
        }else{
          break;
        }
    }
  }
}

void RutinaAltaPropiedad::ingresarNuevaCasa(){
  while(true){
    DataPropiedad* dprop;
    DataCasa* dcasa;
    try{

      cout << "Ingresar una nueva Casa: " << endl<<endl;
      int cod,cAmbientes,dormitorios,banios;
      bool garaje;
      float alquiler,venta,m2totales,m2edificados,m2totales,espacioverde;
      cout << "Ingreso de datos: " <<endl<<endl;
      //el usuario ingresa el codigo de la casa
      cout << "Ingrese el codigo: " << endl;
      cod=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de ambientes de la casa
      cout << "Ingrese la cantidad de ambientes: " <<endl;
      cAmbientes=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de dormitorios
      cout << "Ingrese la cantidad de dormitorios" << endl;
      dormitorios=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de banios
      cout << "Ingrese la cantidad de banios: " << endl;
      banios=MenuUtils::leerInt();
      //el ususario ingresa si tiene garaje o no
      banios=MenuUtils::leerOpcion("Tiene garage? ");
      //el ususario ingresa el precio de venta y/o el de alquiler
      //siendo obligatorio ingresar al menos uno de los dos
      ingresarAlquilerVenta();
      //el ususario ingresa los metros edificados
      cout << "Ingrese la cantidad de m2 edificados: " << endl;
      m2edificados=MenuUtils::leerFloat();
      //el ususario ingresa los m2 de espacio verde
      cout << "Ingrese los m2 de espacio verde: " << endl;
      espacioverde = MenuUtils::leerFloat();
      //se calcula los m2 totales
      m2totales=espacioverde+m2edificados;
      ////el ususario confirma los datos
      if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
        dcasa = new DataCasa(cod,cAmbientes,dormitorios,banios,direccion,garaje,venta,alquiler,m2totales,m2edificados,espacioverde);
        dprop = dynamic_cast<DataPropiedad*>(dcasa);
        ctrl->ingresarNuevaCasa(dprop);
        delete dcasa;
        delete dprop;
        cout << "Datos ingresado correctamente"<< endl;
        MenuUtils::esperarInput();
        break;
      }else{
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
      }
    }catch(YaExistePropiedad& e){
        if(dcasa!=NULL){delete dcasa};
        if(dprop!=NULL){delete dprop};
        cout << e.what() << endl;
        //en caso de error se le pregunta al usuario si desea continuar
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }catch(ValoresInvalidos& exc){
      if(dcasa!=NULL){delete dcasa};
      if(dprop!=NULL){delete dprop};
      cout << exc.what() << endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }
  }
}

void RutinaAltaPropiedad::ingresarNuevoApartamento(){
  while(true){
    DataPropiedad* dprop;
    DataApartamento* dapto;
    try{

      cout << "Ingresar un nuevo Apartamento: " << endl<<endl;
      int cod,cAmbientes,dormitorios,banios;
      bool garaje;
      float alquiler,venta,m2totales,m2edificados,m2totales;
      cout << "Ingreso de datos: " <<endl<<endl;
      //el usuario ingresa el codigo del Apartamento
      cout << "Ingrese el codigo: " << endl;
      cod=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de ambientes del Apartamento
      cout << "Ingrese la cantidad de ambientes: " <<endl;
      cAmbientes=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de dormitorios
      cout << "Ingrese la cantidad de dormitorios" << endl;
      dormitorios=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de banios
      cout << "Ingrese la cantidad de banios: " << endl;
      banios=MenuUtils::leerInt();
      //el ususario ingresa si tiene garaje o no
      banios=MenuUtils::leerOpcion("Tiene garage? ");
      //el ususario ingresa el precio de venta y/o el de alquiler
      //siendo obligatorio ingresar al menos uno de los dos
      ingresarAlquilerVenta();
      //el ususario ingresa los metros edificados
      cout << "Ingrese la cantidad de m2 edificados: " << endl;
      m2edificados=MenuUtils::leerFloat();
      //se calcula los m2 totales
      m2totales=m2edificados;
      ////el ususario confirma los datos
      if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
        dapto = new DataApartamento(cod,cAmbientes,dormitorios,banios,direccion,garaje,venta,alquiler,m2totales,m2edificados);
        dprop = dynamic_cast<DataPropiedad*>(dapto);
        ctrl->ingresarNuevaCasa(dprop);
        delete dapto;
        delete dprop;
        cout << "Datos ingresado correctamente"<< endl;
        MenuUtils::esperarInput();
        break;
      }else{
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
      }
    }catch(YaExistePropiedad& e){
        if(dcasa!=NULL){delete dcasa};
        if(dprop!=NULL){delete dprop};
        cout << e.what() << endl;
        //en caso de error se le pregunta al usuario si desea continuar
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }catch(ValoresInvalidos& exc){
      if(dcasa!=NULL){delete dcasa};
      if(dprop!=NULL){delete dprop};
      cout << exc.what() << endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }
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


>>>>>>> 819dafabe3716a771ae5f1cf2c36cb1b30234e3b
