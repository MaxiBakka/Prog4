
#ifndef CHAT_H
#define CHAT_H

#include<string>
#include<vector>
#include <set>

#include "Mensaje.h"
#include "DataMensaje.h"
#include "DataChat.h"



using namespace std;

class Interesado;
class Inmobiliaria;
class Propiedad;


class Chat {
private:
    string emailInteresado;
    string nombreInmobiliaria;
    vector<Mensaje*>* mensajes;
    Propiedad*propiedad;
    Interesado*interesado;
    Inmobiliaria * inmobiliaria;

public:
    Chat(string ei,string ni,Propiedad*p,Interesado*i,Inmobiliaria*inm);
    //getters
    string getEmailInteresado();
    string getNombreInmobiliaria();
    Propiedad* getPropiedad();
    Interesado* getInteresado();
    Inmobiliaria * getInmobiliaria();
    //setters
    void setEmailInteresado(string email);
    void setNombreInmobiliaria(string nombre);

    //operaciones de caso de uso EnviarMensaje Inreresado
    int cantidadMensajes();
    bool esChatPropiedad(int codigo);
    void nuevoMensaje(DataMensaje* m);
    //obtencion de datatype, ultimos 5 mensajes
    set<DataMensaje*>* getDataMensajes();
    DataChat* getDataChat();
    //operaciones de sobre mensajes

    //destructor
    virtual ~Chat();
};


#endif /* CHAT_H */
