#include "DataInmobiliaria.h"

DataInmobiliaria::DataInmobiliaria(string nombre, string email, string direccion){

	this->nombre=nombre;
	this->email=email;
	this->direccion=direccion;
}

string& DataInmobiliaria::get_nombre(){
	return this->nombre;
}

string& DataInmobiliaria::get_email(){
	return this->email;
}

string& DataInmobiliaria::get_direccion(){
	return this->direccion;
}

DataInmobiliaria::~DataInmobiliaria(){

}

ostream& operator<<(ostream& o, DataInmobiliaria& di){

    o<< "Nombre: " << di.get_nombre() << endl << "Direccion: " << di.get_direccion() << endl << "Email: " << di.get_email() << endl;


    return o;
}
