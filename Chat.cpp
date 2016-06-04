#include "Chat.h"

using namespace std;


Chat::Chat(string ei,string ni,Propiedad*p,Interesado*i,Inmobiliaria*inm{
    this->emailInteresado=ei;
    this->nombreInmobiliaria=ni;
    this->mensajes= new stack<Mensaje*>()
    this->propiedad=p;
    this->interesado=i;
    this->inmobiliaria=inm;
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

Propiedad* Chat::getPropiedad(){
	
}

Interesado* Chat::getInteresado(){
	
	
}
Inmobiliaria *Chat::getInmobiliaria(){
	
	
}
void Chat:: setEmailInteresado(string email){
	
	
}
void Chat:: setNombreInmobiliaria(string nombre){
	
	
}


int Chat::cantidadMensajes() {
    return mensajes->size();
}

bool Chat::esChatPropiedad(int codigo) {
    //No se que hace esta operacion , no encontre ni el dss ni nada
}

vector<DataMensaje*>* Chat::getDataMensajes() {     //Devuelve los ultimos 6? Repuesta:5
    
}

void Chat::nuevoMensaje(DataMensaje m) {
    this->mensajes->pushback(new Mensaje(m->get_fecha(),m->get_hora(),m->get_texto()));
}

Chat::~Chat() {
    while (!this->mensajes->empty()){
        this->mensajes->pop();
    }
}

