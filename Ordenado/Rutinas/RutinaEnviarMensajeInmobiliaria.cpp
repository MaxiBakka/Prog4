#include "RutinaEnviarMensajeInmobiliaria.h"

#include "Sesion.h"
#include "Hora.h"
#include "Fecha.h"
#include "Factory.h"
#include "NoExisteChat.h"
#include "ProcesoCancelado.h"
#include "ExNoHayMensajes.h"
#include "NoHayConversaciones.h"


#include <iostream>
#include <map>
#include <set>
#include <string>
#include <time.h>

#include "MenuUtils.h"

using namespace std;

RutinaEnviarMensajeInmobiliaria::RutinaEnviarMensajeInmobiliaria(){
  ctrl= Factory::getIEnviarMenajeController();
}

RutinaEnviarMensajeInmobiliaria::~RutinaEnviarMensajeInmobiliaria(){

  delete ctrl;
}

void RutinaEnviarMensajeInmobiliaria::seleccionarChat(){
  while(true){
    DataChat* dc;
    try{

      cout << "Sus conversaciones existentes: "<<endl<<endl;
      set<DataChat*>* chats = ctrl->listarChats();
      for(set<DataChat*>::iterator it = chats->begin();it!=chats->end();++it){
        DataChat* c = dynamic_cast<DataChat*>(*it);
        cout << *c << endl;
        delete c;
      }

      chats->clear();
      delete chats;
      cout << endl;
      int cod;
      string emailInteresado,nombreInmobiliaria;
      cout << "Seleccionar conversacion: " << endl;
      //el ususario ingresa el codigo de la propiedad
      cout << "Ingrese el codigo de la propiedad: " ;
       cod=MenuUtils::leerInt();cout << endl;
       //el ususario ingresa el email del interesado
      cout << "Ingrese el email del Interesado: ";
      emailInteresado=MenuUtils::leerString();cout << endl;
      //obtengo el email de la inmobiliaria que tiene sesion iniciada
      Sesion* s=Sesion::getInstancia();
      Usuario* u= s->getUsuario();
      nombreInmobiliaria=u->get_email();
       dc = new DataChat(emailInteresado,nombreInmobiliaria,cod);
        ctrl->seleccionarChat(dc);
      break;
    }catch(NoExisteChat& e){
      if(dc!=NULL){delete dc;}
      cout<<e.what()<<endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();
    }
  }
}

void RutinaEnviarMensajeInmobiliaria::enviarMensaje(){
  while(true){
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

void RutinaEnviarMensajeInmobiliaria::ejecutar(){
  while(true){
    try{
      cout << "Bienvenida Inmobiliaria" << endl;
      seleccionarChat();
      //se listan los mensajes del chat seleccionado
      try{
        set<DataMensaje*>* mensajes= ctrl->listarMensajes();
        for(set<DataMensaje*>::iterator it = mensajes->begin();it!=mensajes->end();++it){
        DataMensaje* dm = dynamic_cast<DataMensaje*>(*it);
        cout << *dm;
        delete dm;
        }

        delete mensajes;

      }catch(ExNoHayMensajes& e){
         cout << e.what() << endl;
      //en caso de error se le pregunta al usuario si desea continuar
      if(!MenuUtils::leerOpcion("Desea Intentarlo nuevamente?")) throw ProcesoCancelado();

      }

      //se le pregunta al usuario si desea enviar un nuevo mensaje
      if(MenuUtils::leerOpcion("Desea enviar un nuevo Mensaje? ")){
          enviarMensaje();
          if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
            delete ctrl;
            ctrl = Factory::getIEnviarMenajeController();
          }else{
            break;
          }
      }else{
        throw ProcesoCancelado();
      }
    }catch(ProcesoCancelado& ){

          cout << "Error: se cancelo el envio del mensaje" << '\n';

          if(MenuUtils::leerOpcion("Desea empezar de nuevo?")){
            delete ctrl;
            ctrl = Factory::getIEnviarMenajeController();
          }else{
            break;
          }
    }catch(NoHayConversaciones &e){
        cout << e.what() << endl ;

        MenuUtils::esperarInput();
        break;
    }
  }
}
