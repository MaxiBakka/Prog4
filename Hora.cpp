#include "Hora.h"
#include "HoraInvalida.h"

Hora :: Hora(){
    this->hora=-1;
    this->minuto=-1;
    this->segundo=-1;
}

Hora :: Hora(int h,int m,int s){
  if (!(h<0||h>23 || m<0 || m>60 || s<0 || s>60)){
    this->hora=h;
    this->minuto=m;
    this->segundo=s;
  } else throw HoraInvalida();

}


int Hora :: get_hora(){
    return this->hora;
}

int Hora :: get_minuto(){
    return this->minuto;
}

int Hora :: get_segundo(){
    return this->segundo;
}

Hora :: ~Hora(){

}


Hora&Hora::operator =(const Hora h) {
	this->hora = h.hora;
	this->minuto = h.minuto;
	this->segundo = h.segundo;

	return (*this);
}

ostream & operator<<(ostream& o,Hora& h){

  o<< h.get_hora()<< ":" << h.get_minuto()<< ":" << h.get_segundo();
  return o;
}
