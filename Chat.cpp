#include "Chat.h"

Chat :: Chat(string ei,string ni){
    this->emailInteresado=ei;
    this->nombreInmobiliaria=ni;
    std::stack<Mensaje*>* this->mensajes;
}

string Chat :: getEmailInteresado(){
    return this->emailInteresado;
}

string Chat::getNombreInmobiliaria() {
    return this->nombreInmobiliaria;
}

std::stack<Mensaje*>* Chat::getMensajes() {
    //Despues hay que hacerlo
}

int Chat::cantidadMensajes() {
    return mensajes.size();
}

bool Chat::esChatPropiedad(int codigo) {
    //No se que hace esta operacion , no encontre ni el dss ni nada
}

std::stack<DataMensaje*>* Chat::getDataMensajes() {     //Devuelve los ultimos 6?
    std::stack<Mensaje*>* aux (this->mensajes);
    std::stack<DataMensaje*>* res;
    for(int i=0;i<5;i++){
        res.push(new DataMensaje(aux.top()->getFecha(),aux.top()->getHora(),aux.top()->getTexto()));
    }
}

void Chat::nuevoMensaje(DataMensaje m) {
    this->mensajes.push(new Mensaje(m->get_fecha(),m->get_hora(),m->get_texto()));
}

Chat::~Chat() {
    while (!this->mensajes.empty()){
        this->mensajes->pop();
    }
}

