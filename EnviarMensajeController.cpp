#include "EnviarMensajeController.h"

EnviarMensajeController::EnviarMensajeController() {
    this->chat=NULL;
}

void EnviarMensajeController::enviarMensaje(DataMensaje* mensaje) {
    //no sabria como hacer esto
}

set<DataChat*>* EnviarMensajeController::listarChats() {
    
}

set<DataMensaje*>* EnviarMensajeController::listarMensajes() {
    
}

void EnviarMensajeController::seleccionarChat(DataChat* dc) {

}

EnviarMensajeController::~EnviarMensajeController() {
    this->chat=NULL;
}

