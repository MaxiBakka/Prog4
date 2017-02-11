#include "Fecha.h"
#include "FechaInvalida.h"


Fecha :: Fecha(int d,int m,int a){
  if(!(d<1 || d>31 || m<1 || m>12 || a<1900)){
    this->dia=d;
    this->mes=m;
    this->anio=a;
}else throw FechaInvalida();

}

int Fecha :: get_dia(){
    return this->dia;
}

int Fecha :: get_mes(){
    return this->mes;
}

int Fecha :: get_anio(){
    return this->anio;
}

Fecha&Fecha::operator =(const Fecha f) {
	this->dia = f.dia;
	this->mes = f.mes;
	this->anio = f.anio;
	return (*this);
}


Fecha :: ~Fecha(){

};


ostream& operator<<(ostream& o,  Fecha& f){
	o << f.get_dia() << "/" << f.get_mes() << "/" << f.get_anio();
	return o;
}
