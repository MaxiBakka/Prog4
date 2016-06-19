#include "RutinaEnviarMensajeInteresado.h"

#include "../ClasesDeDominio/Sesion.h"
#include "../DataTypes/Hora.h"
#include "../DataTypes/Fecha.h"
#include "../Fabrica/Factory.h"

#include "../Excepciones/ExDptoNoExistente.h"
#include "../Excepciones/ProcesoCancelado.h"
#include "../Excepciones/NoExisteZona.h"
#include "../Excepciones/NoExisteChat.h"
#include "../Excepciones/ExNoHayZonas.h"
#include "../Excepciones/NoHayDepartamentos.h"
#include "../Excepciones/ExPropiedadNoExistente.h"


#include <iostream>
#include <map>
#include <set>
#include <string>
#include <time.h>

#include "../Menus/MenuUtils.h"

using namespace std;

RutinaEnviarMensajeInteresado::RutinaEnviarMensajeInteresado(){
  ctrl=Factory::getIPropiedadController();
}

RutinaEnviarMensajeInteresado::~RutinaEnviarMensajeInteresado(){
    delete ctrl;
}

void RutinaEnviarMensajeInteresado::seleccionarDepartamento(){

  while (true) {
    try{
      MenuUtils::limpiarConsola();
    cout << "Enviar Mensaje - Seleccion de Departamento" << endl;

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

void RutinaEnviarMensajeInteresado::seleccionarZona(){

  while (true) {
    try{
    MenuUtils::limpiarConsola();
    cout << "Enviar Mensaje - Seleccion de Zona" << endl;

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

void RutinaEnviarMensajeInteresado::enviarMensaje(){
  while(true){
      MenuUtils::esperarInput();
      MenuUtils::limpiarConsola();
      cout << "Enviar nuevo Mensaje: "<<endl<<endl;

      string texto;
      time_t currentTime;
      struct tm *localTime;

      time( &currentTime );                   // obtenemos el tiempo
      localTime = localtime( &currentTime );  // lo convertimos en el tiempo local

      int Day    = localTime->tm_mday;
      int Month  = localTime->tm_mon + 1;
      int Year   = localTime->tm_year + 1900;
      int Hour   = localTime->tm_hour;
      int Min    = localTime->tm_min;
      int Sec    = localTime->tm_sec;


      cout << "Ingrese el mensaje: "<< endl;
      texto=MenuUtils::leerString();
      //creo la hora y la fecha utilizando la hora y fecha del sistema
      Fecha* f= new Fecha(Day,Month,Year);
      Hora* h= new Hora(Hour,Min,Sec);
      DataMensaje* dm = new DataMensaje(*f,*h,texto);
      delete f;
      delete h;
      if(MenuUtils::leerOpcion("Desea confirmar estos datos?")){
        ctrl->enviarMensaje(dm);
        delete dm;
        cout << "Datos ingresado correctamente"<< endl;
        MenuUtils::esperarInput();
        if(!MenuUtils::leerOpcion("Desea enviar un nuevo mensaje?")) break;

      }else{
        delete dm;
        if(f!=NULL){delete f;}
        if(h!=NULL){delete h;}
        if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();

      }

  }
}


void RutinaEnviarMensajeInteresado::ejecutar(){
  while(true){

  		try{
  			//limpiar consola e imprimir encabezado
  			MenuUtils::limpiarConsola();
  			cout << "Enviar Mensaje " << endl << endl;

        seleccionarDepartamento();  MenuUtils::limpiarConsola();
        seleccionarZona();  MenuUtils::limpiarConsola();

        set<DataInfoPropiedad*>* ipropiedades = ctrl->obtnerConversaciones();
        set<DataInfoPropiedad*>::iterator it=ipropiedades->begin();

        if(it ==ipropiedades->end()){
          cout<< "No existen Propiedades para la zona seleccionada" << endl;
          if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();

        }else{
        cout << "Informacion de las propiedades" << endl;

        for(set<DataInfoPropiedad*>::iterator it = ipropiedades->begin();it!=ipropiedades->end();++it){
          DataInfoPropiedad* infoProp= dynamic_cast<DataInfoPropiedad*>(*it);
          cout << *infoProp;
          delete infoProp;
        }
        delete ipropiedades;
        }
        cout << endl;
        while(true){
          try{

            cout << "Ingrese el codigo de la Propiedad: " << endl;
            int cod=MenuUtils::leerInt();

            ctrl->seleccionarPropiedad(cod);
            cout <<endl <<endl;
            break;
          }catch(ExPropiedadNoExistente& e){
              cout << e.what() << endl;
              if(!MenuUtils::leerOpcion("Desea intentar nuevamente?"))throw ProcesoCancelado();

          }
        }


    try{
       set<DataMensaje*>* mensajes= ctrl->listarMensajes();
       for(set<DataMensaje*>::iterator it = mensajes->begin();it!=mensajes->end();++it){
       DataMensaje* dm = dynamic_cast<DataMensaje*>(*it);
       cout << *dm;
       delete dm;
       }

       delete mensajes;

     }catch(NoExisteChat& e){
        cout << e.what() << endl;
     }

        enviarMensaje();
        break;
      }catch(ProcesoCancelado& ){

            cout << "Error: se cancelo el envio del mensaje" << '\n';

            if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
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
  		}
    }
}
