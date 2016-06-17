#include "DataMensaje.h"


DataMensaje::DataMensaje(Fecha& f,Hora& h,string& t):fecha(f){

    this->hora=h;
    this->texto=t;
}

Fecha& DataMensaje :: get_fecha(){
    return this->fecha;
}

Hora& DataMensaje :: get_hora(){
    return this->hora;
}

string& DataMensaje :: get_texto(){
    return this->texto;
}



DataMensaje :: ~DataMensaje(){

}

ostream& operator <<(ostream& output, DataMensaje& dm) {
  output << "Mensaje: " << dm.get_texto() << endl;
  output <<'\t'<<'\t'<< '\t' << dm.get_fecha() << ' ' << dm.get_hora() << endl; 
  return output;

}
