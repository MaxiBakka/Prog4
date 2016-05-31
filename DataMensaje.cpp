#include DataMensaje.h

DataMensaje :: DataMensaje(){
    this->fecha=Fecha();
    this->hora=Hora();
    this->texto="";
}

DataMensaje :: DataMensaje(Fecha f,Hora h,string t){
    this->fecha=f;
    this->hora=h;
    this->texto=t;
}

Fecha DataMensaje :: get_fecha(){
    return this->fecha;
}

Hora DataMensaje :: get_hora(){
    return this->hora;
}

string DataMensaje :: get_texto(){
    return this->texto;
}

void DataMensaje :: set_fecha(Fecha *&f){
    this->fecha=f;
}

void set_hora(Hora *&h){
    this->hora=h;
}
void set_texto(string *&t){
    this->texto=t;
}

DataMensaje :: ~DataMensaje(){
    this->fecha.~Fecha();
    this->hora.~Hora();
}
