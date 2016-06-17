#include "RutinaAltaInteresado.h"

#include "DtInteresado.h"
#include "ProcesoCancelado.h"
#include "ExisteInteresado.h"
#include "Factory.h"

#include <string>

#include "MenuUtils.h"


#include <iostream>


void RutinaAltaInteresado::IngresarInteresado(){

  while(true){
    DtInteresado* di= NULL;
  		try{
  			string nombre,email,direccion,apellido;
        int edad;




  			cout << "Alta Interesado - Ingrese sus datos" << endl;

  			//el usuario ingresa su email
  			cout << "Ingrese su email: ";
  			email = MenuUtils::leerString();
  			//el usuario ingresa su nombre
  			cout << "Ingrese el nombre: ";
  			 nombre= MenuUtils::leerString();
         //el usuario ingresa su apellido
         cout << "Ingrese el apellido: ";
   			 apellido= MenuUtils::leerString();
         //el usuario ingresa su edad
         cout << "Ingrese la edad: ";
         edad= MenuUtils::leerInt();

  			di= new DtInteresado(nombre,apellido,edad,email);

  			MenuUtils::limpiarConsola();
  			cout << *di;

  			if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
  				ctrl->IngresarInteresado(di);
  				cout << "Datos ingresado correctamente"<< endl;
  				MenuUtils::esperarInput();
  				break;
  			}else{
  				delete di;
  				if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
  			}
      }catch(ExisteInteresado& e){
        if (di!=NULL) delete di;
          cout << e.what() << '\n';
          //en caso de error se le pregunta al usuario si desea continuar
          if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
      }
  }



}

RutinaAltaInteresado::RutinaAltaInteresado(){
  ctrl= Factory::getIUsuarioController();

}


void RutinaAltaInteresado::ejecutar(){
  while(true){
    try{
    cout << "Bienvenido Administrador" << endl;
    cout << "Alta de Interesados" << endl << endl;

      IngresarInteresado();
      MenuUtils::limpiarConsola();

      if(MenuUtils::leerOpcion("Desea realizar otra alta?")){
            delete ctrl;
            ctrl = Factory::getIUsuarioController();
      }else{
            break;
      }
    }catch(ProcesoCancelado& ){

          cout << "Error: Se cancelo el alta interesado" << '\n';

          if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
            delete ctrl;
            ctrl = Factory::getIUsuarioController();
          }else{
            break;
          }
    }

  }
}

RutinaAltaInteresado::~RutinaAltaInteresado(){

delete ctrl;

}
