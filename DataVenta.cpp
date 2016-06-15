#include "DataVenta.h"


DataVenta::DataVenta(float precio){

	this->precio=precio;
}

float DataVenta::get_precio(){

	return this->precio;
}

DataVenta& DataVenta::operator =( DataVenta venta){
    this->precio=venta.precio;
}


DataVenta::~DataVenta(){


}
