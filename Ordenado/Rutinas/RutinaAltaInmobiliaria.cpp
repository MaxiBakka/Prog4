#include "RutinaAltaInmobiliaria.h"
#include "DataInmobiliaria.h"
#include "ProcesoCancelado.h"

#include <iostream>

#include <string>

#include "MenuUtils.h"



void IngresarInmobiliaria(){

  while(true){
    DataInmobiliaria* di= NULL;
  		try{
  			string nombre,email,direccion;



  			MenuUtils::limpiarConsola();
  			cout << "Alta Inmobiliaria - Ingrese sus datos" << endl;

  			//el usuario ingresa su email
  			cout << "Ingrese su email: ";
  			email = MenuUtils::leerString();
  			//el usuario ingresa su nombre
  			cout << "Ingrese el nombre: ";
  			 nombre= MenuUtils::leerString();
  			//el usuario ingresa la direccion
  			cout << "Ingrese la direccion: ";
  			direccion = MenuUtils::leerString(); ;


  			di= new DataInmobiliaria(nombre,email,direccion);

  			MenuUtils::limpiarConsola();
  			cout << *di;

  			if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
  				ctrl->IngresarInmobiliarial(di);
  				MenuUtils::imprimirConfirmacion("Datos ingresado correctamente");
  				MenuUtils::esperarInput();
  				break;
  			}else{
  				delete di;
  				if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
  			}
      }catch(InmobiliariaYaExistente& e){
        if (di!=NULL) delete dol;
          cout << e.what() << '\n';
          //en caso de error se le pregunta al usuario si desea continuar
          if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
      }
  }

}

RutinaAltaInmobiliaria::RutinaAltaInmobiliaria(){
  ctrl= Factory::getIUsuarioController();

}

RutinaAltaInmobiliaria::ejecutar(){
  while(true){
    try{
    cout << "Bienvenido Administrador" << endl;
    cout << "Alta de Inmobiliarias" << endl << endl;

      IngresarInmobiliaria();
      MenuUtils::limpiarConsola();

      if(MenuUtils::leerOpcion("Desea realizar otra alta?")){
    				delete ctrl;
    				ctrl = Factory::getIUsuarioController();
    	}else{
    				break;
    	}
    }catch(ProcesoCancelado& ){

    			cout << "Error: Se cancelo el alta inmobiliaria" << '\n';

    			if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
    				delete ctrl;
    				ctrl = Factory::getIUsuarioController();
    			}else{
    				break;
    			}
    }

  }
}
RutinaAltaInmobiliaria::~RutinaAltaInmobiliaria(){
delete ctrl;

}
