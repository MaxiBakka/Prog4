
#ifndef CHAT_H
#define CHAT_H

#include<string>
#include<vector>

#include "Mensaje.h"
#include "DataMensaje.h"



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
    
    //operaciones de caso de uso EnviarMensaje
    int cantidadMensajes();
    bool esChatPropiedad(int codigo);
    void nuevoMensaje(DataMensaje* mensaje);
    //obtencion de datatype
    vector<DataMensaje*>* getDataMensajes();
    
    //operaciones de sobre mensajes
    
    //destructor
    virtual ~Chat();
};


#endif /* CHAT_H */

