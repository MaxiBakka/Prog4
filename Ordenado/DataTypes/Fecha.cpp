#include "../DataTypes/Fecha.h"
#include "FechaInvalida.h"

#include <cstdlib>
#include <sstream>
#include <iomanip>


Fecha :: Fecha(int d,int m,int a){
  if(!(d<1 || d>31 || m<1 || m>12 || a<1900)){
    this->dia=d;
    this->mes=m;
    this->anio=a;
}else throw FechaInvalida();

}

Fecha::Fecha(Fecha& ref) {
	this->anio=ref.anio;
	this->mes=ref.mes;
	this->dia=ref.dia;
}


Fecha::Fecha(const string& fecha) {
	istringstream f(fecha);
	string s;
	int dato = 0;
	while(getline(f, s,'/')){
		if(dato == 0){
			this->dia = atoi(s.c_str());
			dato++;
		}else if(dato == 1){
			this->mes = atoi(s.c_str());
			dato++;
		}else{
			this->anio = atoi(s.c_str());
			dato++;
		}
	}
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
	o << setfill('0') << setw(2)  << f.get_dia() << "/";
	o << setfill('0') << setw(2)  << f.get_mes() << "/" ;
	o << setfill('0') << setw(2) << f.get_anio() << endl;
	return o;
}
