#include "DataMensaje.h"


DataMensaje :: DataMensaje(Fecha& f,Hora& h,string t){
    this->fecha=f;
    this->hora=h;
    this->texto=t;
}

Fecha& DataMensaje :: get_fecha(){
    return this->fecha;
}

Hora& DataMensaje :: get_hora(){
    return this->hora;
}

const string& DataMensaje :: get_texto(){
    return this->texto;
}



DataMensaje :: ~DataMensaje(){

}

ostream& operator <<(ostream& output, DataMensaje& dm) {
  //Implementar formato de salida

}
