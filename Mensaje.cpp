#include "Mensaje.h"

Mensaje :: Mensaje(Fecha& f, Hora& h, string& t){
    this->fecha=f;
    this->hora=h;
    this->texto=t;
}

Fecha& Mensaje :: getFecha(){
    return this->fecha;
}

Hora& Mensaje :: getHora(){
    return this->hora;
}

string& Mensaje :: getTexto(){
    return this->texto;
}

//setters

void Mensaje::setTexto(string& texto){
    this->texto=texto;
    
}

void Mensaje::setFecha(Fecha&fecha){
    
    this->fecha=fecha;
}
void Mensaje::setHora(Hora& hora){
    this->hora=hora;
}

DataMensaje* Mensaje :: getDataMensaje(){
    return new DataMensaje(this->fecha,this->hora,this->texto);
}

Mensaje :: ~Mensaje(){

}
