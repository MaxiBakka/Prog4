#include "Mensaje.h"

Mensaje :: Mensaje(Fecha f, Hora h, string t){
    this->fecha=f;
    this->hora=h;
    this->texto=t;
}

Fecha Mensaje :: getFecha(){
    return this->fecha;
}

Hora Mensaje :: getHora(){
    return this->hora;
}

string Mensaje :: getTexto(){
    return this->texto;
}

DataMensaje Mensaje :: getDataMensaje(){
    return DataMensaje(this->fecha,this->hora,this->texto);
}

Mensaje :: ~Mensaje(){

}
