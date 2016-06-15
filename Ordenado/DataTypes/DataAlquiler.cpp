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
