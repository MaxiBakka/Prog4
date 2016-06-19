#include "EnviarMensajeController.h"
#include "../ClasesDeDominio/Usuario.h"
#include "../ClasesDeDominio/Sesion.h"
#include "../ClasesDeDominio/Inmobiliaria.h"

#include "../Excepciones/NoHayChatEnMemoria.h"
#include "../Excepciones/NoHayConversaciones.h"

EnviarMensajeController::EnviarMensajeController() {
    this->chat=NULL;
}

void EnviarMensajeController::enviarMensaje(DataMensaje* mensaje) {

  this->chat->nuevoMensaje(mensaje);

}

set<DataChat*>* EnviarMensajeController::listarChats() {

Sesion* sesion = Sesion::getInstancia();
Inmobiliaria*inmobiliaria= dynamic_cast<Inmobiliaria*>(sesion->getUsuario());
  set<Chat*>* chats=inmobiliaria->getChats();
  set<DataChat*>* dc= new set<DataChat*>();

  for (set<Chat*>::iterator it =chats->begin(); it!=chats->end(); ++it) {
    dc->insert((*it)->getDataChat());
  }
  if(dc->size()==0){
		dc->clear();
		delete dc;
		throw NoHayConversaciones();
	}
  return dc;
}

set<DataMensaje*>* EnviarMensajeController::listarMensajes() {
  if (chat==NULL) throw NoHayChatEnMemoria();

  return chat->getDataMensajes();
}

void EnviarMensajeController::seleccionarChat(DataChat* dc) {

  Sesion * sesion = Sesion::getInstancia();
  Inmobiliaria*inmobiliaria= dynamic_cast<Inmobiliaria*>(sesion->getUsuario());
  this->chat= inmobiliaria->ElegirChat(dc);

}

EnviarMensajeController::~EnviarMensajeController() {
    this->chat=NULL;
}
