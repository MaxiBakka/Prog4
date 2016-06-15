#include "DataInfoAlquiler.h"


DataInfoAlquiler::DataInfoAlquiler(float precio){

	this->precio=precio;
}

float DataInfoAlquiler::get_precio(){

	return this->precio;
}

DataInfoAlquiler& DataInfoAlquiler::operator =( DataInfoAlquiler alquiler){
    this->precio=alquiler.precio;
}


DataInfoAlquiler::~DataInfoAlquiler(){


}
