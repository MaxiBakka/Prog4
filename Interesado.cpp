#include "Interesado.h"
#include "DataMensaje.h"
#include "DtInteresado.h"

Interesado :: Interesado():Usuario(){
    this->nombre='';
    this->apellido='':
    this->edad=-1;

}

Interesado :: Interesado(string& e,string& c,string& n,string& a,int age):Usuario(e,c){

    this->nombre=n;
    this->apellido=a:
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
bool Interesado::ExisteChat(Chat&* chat){

  return chats->find(chat)!=chats->end();
}
set<DataMensaje*>* Interesado::ObtenerDataMensajes(){



}



Interesado :: ~Interesado(){


}
