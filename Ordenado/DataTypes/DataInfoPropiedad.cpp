#include "../DataTypes/DataInfoPropiedad.h"

DataInfoPropiedad :: DataInfoPropiedad(int c,string d,int cmjs){
    this->codigo=c;
    this->direccion=d;
    this->cantMensaje=cmjs;
}

int DataInfoPropiedad :: get_codigo(){
    return this->codigo;
}

string DataInfoPropiedad :: get_direccion(){
    return this->direccion;
}

int DataInfoPropiedad :: get_cantMensajes(){
    return this->cantMensaje;
}

DataInfoPropiedad :: ~DataInfoPropiedad(){}

ostream& operator<<(ostream& o, DataInfoPropiedad& di){
  o << "------- Propiedad nro" << di.get_codigo() << " -------" << endl;
	o << "Direccion: " << di.get_direccion() << endl;
	o << "Cantidad de mensajes enviados: " << di.get_cantMensajes() << endl;
  return o;

}
