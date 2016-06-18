#include "RutinaAltaEdificio.h"

#include "../DataTypes/DataEdificio.h"
#include "MenuUtils.h"
#include "ProcesoCancelado.h"
#include "ExisteEdificio.h"
#include "Factory.h"

#include <iostream>
#include <string>

using namespace std;

void RutinaAltaEdificio::IngresarEdificio(){

  while(true){
    DataEdificio* de=NULL;
    try{

      int cantPisos;
      float gComunes;



      cout << "Alta Edificio - Ingrese sus datos" << endl;

      //el usuario ingresa el nombre del edificio
      cout << "Ingrese el nombre: ";
      nombreEdificio = MenuUtils::leerString();
      //el usuario ingresa la cantidad de pisos
      cout << "Ingrese la cantidad de pisos: ";
      cantPisos=MenuUtils::leerInt();
      //el usuario ingresa los gastos comunes
      cout << "Ingrese los gastos comunes: ";
      gComunes=MenuUtils::leerFloat();


      de = new DataEdificio(nombreEdificio,cantPisos,gComunes);

      MenuUtils::limpiarConsola();
      cout << *de;

      if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
        ctrl->IngresarEdificio(de);
        cout <<"Dato ingresados correctamente" << endl;
        MenuUtils::esperarInput();
        break;
      }else{
        delete de;
        if(!MenuUtils::leerOpcion("Desea Intentarlo Nuevamente?")) throw ProcesoCancelado();
      }
      MenuUtils::limpiarConsola();
    }catch(ExisteEdificio& e){
      if (de!=NULL) delete de;
      cout << e.what() << endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }
  }
}

RutinaAltaEdificio::RutinaAltaEdificio(){
  this->ctrl = Factory::getIPropiedadController();
  nombreEdificio = "";
}

RutinaAltaEdificio::~RutinaAltaEdificio(){
  if(ctrl!=NULL) delete ctrl;
}


void RutinaAltaEdificio::ejecutar(){
  while(true){
    try{
      cout << "Bienvenida Inmobiliaria" << endl;
      cout << "Alta de Edificios" << endl << endl;

      IngresarEdificio();
      MenuUtils::limpiarConsola();

      if(MenuUtils::leerOpcion("Desea realizar otra alta?")){
        delete ctrl;
        ctrl = Factory::getIPropiedadController();
      }else{
        break;
      }
    }catch(ProcesoCancelado& ){

        cout << "Error: Se cancelo el alta Edificio" << endl;

        if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
          delete ctrl;
          ctrl = Factory::getIPropiedadController();
        }else{
          break;
        }
    }
  }
}



string RutinaAltaEdificio::getNombreEdificio(){
	return this->nombreEdificio;
}
