#include "DataAlquiler.h"


DataAlquiler::DataAlquiler(float precio){

	this->precio=precio;
}

float DataAlquiler::get_precio(){

	return this->precio;
}

DataAlquiler& DataAlquiler::operator =( DataAlquiler alquiler){
    this->precio=alquiler.precio;
}


DataAlquiler::~DataAlquiler(){


}

ostream& operator <<(ostream& o, DataAlquiler& N){

o << "El precio del alquiler es:" << N.get_precio() << '\n' ;

    return o;

}
