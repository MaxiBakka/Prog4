#include DataInfoPropiedad.h

DataInfoPropiedad :: DataInfoPropiedad(int c,string d,int cmjs){
    this->codigo=c;
    this->direccion=d;
    this->cantMensajes=cmjs;
}

int DataInfoPropiedad :: get_codigo(){
    return this->codigo;
}

string DataInfoPropiedad :: get_direccion(){
    return this->direccion;
}

int DataInfoPropiedad :: get_cantMensajes(){
    return this->cantMensajes;
}

DataInfoPropiedad :: ~DataInfoPropiedad(){}


