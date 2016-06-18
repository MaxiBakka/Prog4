#include "../DataTypes/DataChat.h"

DataChat::DataChat(string& ei, string& inm,int cod) {
    this->emailInteresado=ei;
    this->nombreInmobiliaria=inm;
    this->codigo=cod;
}

int DataChat::getCodigo() {
    return this->codigo;
}

string DataChat::getEmailInteresado() {
    return this->emailInteresado;
}
string DataChat::getNombreInmobiliaria() {
    return this->nombreInmobiliaria;
}

DataChat::~DataChat() {

}

ostream& operator <<(ostream& o, DataChat& dc) {
  o << "Conversacion sobre Propiedad: " << dc.getCodigo() << endl;
  o << "Inmobiliaria: " << dc.getNombreInmobiliaria()<< endl;
  o <<"Interesado: " << dc.getEmailInteresado()<< endl;

  return o;
}
