
#ifndef CHAT_H
#define CHAT_H

#include<string>
#include<stack>
#include "Mensaje.h"
#include "DataMensaje.h"


class Chat {
private:
    string emailInteresado;
    string nombreInmobiliaria;
    std::stack<Mensaje*>* mensajes;
public:
    Chat(string ei,string ni);
    string getEmailInteresado();
    string getNombreInmobiliaria();
    std::stack<Mensaje*>* getMensajes();
    int cantidadMensajes();
    bool esChatPropiedad(int codigo);
    std::stack<DataMensaje*>* getDataMensajes();
    void nuevoMensaje(DataMensaje m);
    ~Chat();
};


#endif /* CHAT_H */

