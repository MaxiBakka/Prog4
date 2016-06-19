#include "Interesado.h"
#include "../DataTypes/DtInteresado.h"
#include "../DataTypes/NoExisteChat.h"

Interesado :: Interesado():Usuario(){
    this->nombre="";
    this->apellido="";
    this->edad=-1;

}

Interesado :: Interesado(string& e,string& c,string& n,string& a,int age):Usuario(e,c){

    this->nombre=n;
    this->apellido=a;
    this->edad=age;
    this->chats= new set<Chat*>();
}

//getters
string& Interesado::get_nombre(){
    return this->nombre;
}

string& Interesado::get_apellido(){
    return this->apellido;
}

int Interesado::get_edad(){
    return this->edad;
}
//setters
void Interesado::set_nombre(string &n){
    this->nombre=n;
}

void Interesado::set_apellido(string &a){
    this->apellido=a;
}

void Interesado::set_edad(int &age){
    this->edad=age;
}

//operaciones de chat
void Interesado::AgregarChat(Chat *chat){

  this->chats->insert(chat);
}

void Interesado::EliminarChat(Chat *chat){

  this->chats->erase(chat);
}
bool Interesado::ExisteChat(Chat* &chat){

  return chats->find(chat)!=chats->end();
}

//caso de uso Enviar Mensaje Interesado
set<DataMensaje*>* Interesado::ObtenerDataMensajes(int codigo){
set<DataMensaje*>*res = new set<DataMensaje*>();
bool flag=true;
  for (set<Chat*>::iterator it=chats->begin();it!=chats->end()&& flag;++it) {
    if((*it)->esChatPropiedad(codigo)){
      res = (*it)->getDataMensajes();
      flag=false;
    }
  }

  if (flag) throw NoExisteChat();

  return res;

}

Interesado :: ~Interesado(){

  for (set<Chat*>::iterator it=chats->begin() ;it!=chats->end(); ++it) {
      Chat*chat= *it;
      delete chat;
  }
  chats->clear();
  delete chats;

}
