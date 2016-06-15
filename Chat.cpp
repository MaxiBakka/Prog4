#include "Chat.h"
#include "Propiedad.h"
#include "ExNoHayMensajes.h"

using namespace std;


Chat::Chat(string& ei,string& ni,Propiedad*p,Interesado*i,Inmobiliaria*inm){
    this->emailInteresado=ei;
    this->nombreInmobiliaria=ni;
    this->mensajes= new vector<Mensaje*>();
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

Propiedad* Chat::getPropiedad(){
  return this->propiedad;
}

Interesado* Chat::getInteresado(){
  return this->interesado;

}
Inmobiliaria* Chat::getInmobiliaria(){
  return this->inmobiliaria;

}
void Chat:: setEmailInteresado(string email){
    this->emailInteresado=email;

}
void Chat:: setNombreInmobiliaria(string nombre){
  this->nombreInmobiliaria=nombre;

}

DataChat* Chat::getDataChat(){

  return new DataChat(emailInteresado,nombreInmobiliaria,propiedad->getCodigo());

}

int Chat::cantidadMensajes() {
    return (mensajes->size());
}

bool Chat::esChatPropiedad(int codigo) {
    return (codigo == propiedad->getCodigo());
}

set<DataMensaje*>* Chat::getDataMensajes() {
    if (mensajes->size()==0) {
      throw ExNoHayMensajes();
    }
    else{
        set<DataMensaje*>* res = new set<DataMensaje*>();
        for (int i =0,vector<Mensaje*>::reverse_iterator it=mensajes->rbegin(); (it!=mensajes->rend() && i<5); i++,++it) {
          res->insert(it->getDataMensaje());
        }
    }
  return res;
}

void Chat::nuevoMensaje(DataMensaje* m) {
    this->mensajes->push_back(new Mensaje(m->get_fecha(),m->get_hora(),m->get_texto()));
}

Chat::~Chat() {

  for (vector<Mensaje*>::iterator it=mensajes->begin() ; it!=mensajes->end() ;++it) {
    Mensaje* msg= *it;
    delete msg;
  }
  delete mensajes;
  interesado->EliminarChat(this);
  inmobiliaria->EliminarChat(this);
  propiedad->EliminarChat(this);
  //segun el diagrama solo la propiedad llama al destructor de chat cuando una propiedad se Elimina
  //nose si dejarlo asi porque supongo que no se puede pedir que el sistema elimine un chat porq le pinto no tendria sentido


}
