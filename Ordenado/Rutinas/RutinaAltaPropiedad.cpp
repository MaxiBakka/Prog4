#include "RutinaAltaPropiedad.h"
#include "RutinaConsultarPropiedad.h"
#include "DataInfoInmobiliaria.h"
#include "DataDetallePropiedad.h"
#include "DataDepartamento.h"
#include "DataZona.h"
#include "DataEdificio.h"
#include "DataCasa.h"
#include "DataApartamento.h"

#include "ProcesoCancelado.h"
#include "NoHayDepartamentos.h"
#include "ExDptoNoExistente.h"
#include "NoHayDepartamentoEnMemoria.h"
#include "ExNoHayZonas.h"
#include "NoExisteZona.h"
#include "NoHayPropiedades.h"
#include "ExPropiedadNoExistente.h"
#include "RutinaAltaEdificio.h"
#include "EdificioNoExistente.h"
#include "YaExistePropiedad.h"
#include "PrecioInvalido.h"
#include "ValoresInvalidos.h"

#include "Factory.h"

#include <iostream>
#include <set>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "MenuUtils.h"

using namespace std;


RutinaAltaPropiedad::RutinaAltaPropiedad(){

  ctrl= Factory::getIPropiedadController();
  srand(time(NULL));
}

RutinaAltaPropiedad::~RutinaAltaPropiedad(){
if(ctrl!=NULL) delete ctrl;
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

void RutinaAltaPropiedad::seleccionarZona(){

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


void RutinaAltaPropiedad::seleccionarEdificio(){
	while(true){
    string nameEd;
    string nameEdi;
    set<DataEdificio*>* listaEd;
		try{

			MenuUtils::limpiarConsola();
			cout << "Alta Propiedad - Seleccion de Edificio" << endl;
			cout << "Edificios en sistema: "<<endl;
			 listaEd = ctrl->listarEdificios();
			cout << *listaEd<< endl<<endl;

			  for(set<DataEdificio*>::iterator it=listaEd->begin();it!=listaEd->end();++it){
                DataEdificio* dedificio = dynamic_cast<DataEdificio*>(*it);
                delete dedificio;
              }
                listaEd->clear();
                delete listaEd;

			cout<< "1 - Seleccionar Edificio"<<endl;
			cout<< "2 - Ingresar Nuevo Edificio"<<endl;
			int opt = MenuUtils::leerInt();
			MenuUtils::limpiarConsola();
			switch(opt){
				case 1:{
					cout<<"Ingrese el nombre del edificio: ";
					nameEd = MenuUtils::leerString();
					ctrl->seleccionarEdificio(nameEd);
					MenuUtils::limpiarConsola();
					break;
				}

				case 2:{
					RutinaAltaEdificio* submenu = new RutinaAltaEdificio();
					submenu->ejecutar();
					nameEdi = submenu->getNombreEdificio();
					ctrl->seleccionarEdificio(nameEdi);
					delete submenu;
					break;
				}
				default:{
					cout <<"Opcion Invalida. Intente nuevamente."<< endl;
					MenuUtils::esperarInput();
					break;
				}
			}
        break;
		}catch(EdificioNoExistente& e){
			MenuUtils::limpiarConsola();
			cout<< e.what()<<endl;
			if(!MenuUtils::leerOpcion("Desea intentarlo de nuevo?")) break;
		}
	}

}

void RutinaAltaPropiedad::ingresarAlquilerVenta(){
float venta;
float alquiler;
  while(true){
    try{
      if(MenuUtils::leerOpcion("Esta propiedad estara a la venta? ")){
        cout << "Ingrese el precio de venta: " << endl;
        venta=MenuUtils::leerFloat();
        DataVenta*dv= new DataVenta(venta);
        ctrl->ingresarPrecioVenta(dv);
      }else{
        venta=-1;
      }
      if(MenuUtils::leerOpcion("Esta propiedad estara para alquilar? ")){
        cout << "Ingrese el precio de alquiler: " << endl;
        alquiler=MenuUtils::leerFloat();
        DataAlquiler*da=new DataAlquiler(alquiler);
        ctrl->ingresarPrecioAlquiler(da);
      }else{
        alquiler=-1;
      }
      if((venta<0 && alquiler<0)) throw ProcesoCancelado();
      break;
    }catch(ProcesoCancelado& ){
        cout << "Error: debe ingresar al menos un precio de oferta." <<endl;
        if(!MenuUtils::leerOpcion("Desea empezar de nuevo?")) break;

    }catch(PrecioInvalido& e){

        cout << e.what() << endl;
        if(!MenuUtils::leerOpcion("Desea empezar de nuevo?"))throw ProcesoCancelado();
    }
  }
}

void RutinaAltaPropiedad::ingresarNuevaCasa(){
  while(true){
    DataPropiedad* dcasa;
    try{

      cout << "Ingresar una nueva Casa: " << endl<<endl;
      int cod,cAmbientes,dormitorios,banios;
      string direccion;
      bool garaje;
      float m2totales,m2edificados,espacioverde;
      cout << "Ingreso de datos: " <<endl<<endl;
      //se genera randomicamente el codigo de la casa
      cod= rand() % 3000 + 3000;
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
      cout << "Ingrese la direccion de la propiedad: " << endl;
      direccion= MenuUtils::leerString();

      garaje=MenuUtils::leerOpcion("Tiene garage? ");
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
      m2totales=espacioverde + m2edificados;
      ////el ususario confirma los datos
      float f=0,f1=0;
      if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
        dcasa = new DataCasa(cod,cAmbientes,dormitorios,banios,direccion,garaje,f,f1,m2totales,m2edificados,espacioverde);

        ctrl->ingresarNuevaCasa(dcasa);
        cout << "Datos ingresado correctamente"<< endl;
        ctrl->confirmarAltaPropiedad();
        cout<< "Propiedad ingresada con exito" << endl;

        MenuUtils::esperarInput();
        break;
      }else{
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
      }
    }catch(YaExistePropiedad& e){
        if(dcasa!=NULL){delete dcasa;}
        cout << e.what() << endl;
        //en caso de error se le pregunta al usuario si desea continuar
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }catch(ValoresInvalidos& exc){
      if(dcasa!=NULL){delete dcasa;}
      cout << exc.what() << endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }
  }
}

void RutinaAltaPropiedad::ingresarNuevoApartamento(){
  while(true){
    DataPropiedad* dapto;

    try{
    cout << "Ingresar un nuevo Apartamento: " << endl<<endl;


      seleccionarEdificio();
      MenuUtils::limpiarConsola();

      cout <<  "Ingresar los datos del Apartamento: "<<endl<<endl;
      int cod,cAmbientes,dormitorios,banios;
      bool garaje;
      string direccion;
      float m2edificados,m2totales;
      cout << "Ingreso de datos: " <<endl<<endl;
      //se genera randomicamentecodigo del Apartamento
      cod= rand() % 3000 + 3000;
      //el ususario ingresa la cantidad de ambientes del Apartamento
      cout << "Ingrese la cantidad de ambientes: " <<endl;
      cAmbientes=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de dormitorios
      cout << "Ingrese la cantidad de dormitorios" << endl;
      dormitorios=MenuUtils::leerInt();
      //el ususario ingresa la cantidad de banios
      cout << "Ingrese la cantidad de banios: " << endl;
      banios=MenuUtils::leerInt();
       cout << "Ingrese la direccion de la propiedad: " << endl;
      direccion= MenuUtils::leerString();
      //el ususario ingresa si tiene garaje o no
      garaje=MenuUtils::leerOpcion("Tiene garage? ");
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
        dapto = new DataApartamento(cod,cAmbientes,dormitorios,banios,direccion,garaje,(float)(0),(float)(0),m2totales,m2edificados);
        ctrl->ingresarNuevoApartamento(dapto);
        cout << "Datos ingresado correctamente"<< endl;

        ctrl->confirmarAltaPropiedad();
        cout<< "Propiedad ingresada con exito" << endl;

        MenuUtils::esperarInput();
        break;
      }else{
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
      }
    }catch(YaExistePropiedad& e){
        if(dapto!=NULL){delete dapto;}

        cout << e.what() << endl;
        //en caso de error se le pregunta al usuario si desea continuar
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }catch(ValoresInvalidos& exc){
      if(dapto!=NULL){delete dapto;}

      cout << exc.what() << endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }
  }
}

void RutinaAltaPropiedad::ejecutar(){

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
					case 0:
						MenuUtils::limpiarConsola();
						salir = true;
						break;
					case 1:{
					    seleccionarDepartamento();
						seleccionarZona();

                    //ahora decide si ingresar una casa o un apartamento
                    cout << "Que tipo de Propiedad desea dar de alta? " << endl << endl;
    				cout << "1 - Casa" << endl;
    				cout << "0 - Apartamento" << endl;
    				int opt = MenuUtils::leerInt();
    				MenuUtils::limpiarConsola();
                        if(opt==1){
                          ingresarNuevaCasa();
                        }else{
                          ingresarNuevoApartamento();
                        }
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
			if(MenuUtils::leerOpcion("Desea dar de alta otra Propiedad? ")) {
                  delete ctrl;
                  ctrl = Factory::getIPropiedadController();
            }else{
                break;
            }
		}catch(ProcesoCancelado&){
			cout << "Alta Propiedad cancelada"<<endl ;
			if(!MenuUtils::leerOpcion("Desea dar de alta otra Propiedad? ")) break;
		}catch(ExNoHayZonas&e ){

        cout << e.what() << endl;

        if(!MenuUtils::leerOpcion("Desea intentar nuevamente?")) break;

    }
	}
}
