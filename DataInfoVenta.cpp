#include "DataInfoVenta.h"


DataInfoVenta::DataInfoVenta(float precio){

	this->precio=precio;
}

float DataInfoVenta::get_precio(){

	return this->precio;
}

DataInfoVenta& DataInfoVenta::operator =( DataInfoVenta venta){
    this->precio=venta.precio;
}


DataInfoVenta::~DataInfoVenta(){


}
