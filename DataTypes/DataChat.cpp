#include "DataChat.h"

DataChat::DataChat(string& ei, string& inm, vector<DataMensaje*>* m) {
    this->emailInteresado=ei;
    this->nombreInmobiliaria=inm;
    this->mensajes=m;
}

vector<DataMensaje*>* DataChat::getDataMensajes() {
    return this->mensajes;
}

string DataChat::getEmailInteresado() {
    return this->emailInteresado;
}
string DataChat::getNombreInmobiliaria() {
    return this->nombreInmobiliaria;
}

DataChat::~DataChat() {
    for(vector<DataMensaje*>::iterator it=this->mensajes->begin();it!=this->mensajes->end();++it){
        delete *it;
    }
}
