#include "RutinaAltaEdificio.h"

#include "DataEdificio_h"
#include "MenuUtils.h"
#include "ProcesoCancelado.h"

#include <iostream>
#include <string>

using namespace std;

void RutinaAltaEdificio::IngresarEdificio(){

  while(true){
    DataEdificio* de=NULL;
    try{

      string nombre;
      int cantPisos;
      float gComunes;


      MenuUtils::limpiarConsola()
      cout << "Alta Edificio - Ingrese sus datos" << endl;

      //el usuario ingresa su email
      cout << "Ingrese el nombre: ";
      nombre = MenuUtils::leerString();
      //el usuario ingresa la cantidad de pisos
      cout << "Ingrese la cantidad de pisos: ";
      cantPisos=MenuUtils::leerInt();
      //el usuario ingresa los gastos comunes
      cout << "Ingrese los gastos comunes: ";
      gComunes=MenuUtils::leerFloat();


      de = new DataEdificio(nombre,cantPisos,gComunes);

      MenuUtils::limpiarConsola();
      cout << *de;

      if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
        ctrl->IngresarEdificio(de);
        MenuUtils::imprimirConfirmacion("Dato ingresados correctamente");
        MenuUtils::esperarInput();
        break;
      }else{
        delete de;
        if(!MenuUtils::leerOpcion("Desea Intentarlo Nuevamente?")) throw ProcesoCancelado();
      }
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
          ctrl = Factory::getIUsuarioController();
        }else{
          break
        }
    }
  }
}