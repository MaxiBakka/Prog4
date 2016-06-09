
#include "DataDetallePropiedad.h"

DataDetallePropiedad::DataDetallePropiedad(int codigo, string& direccion, float venta, float alquiler) {
    this->codigo=codigo;
    this->direccion=direccion;
    this->venta=venta;
    this->alquiler=alquiler;
}

float DataDetallePropiedad::getAlquiler() {
    return this->alquiler;
}

int DataDetallePropiedad::getCodigo() {
    return this->codigo;
}

string& DataDetallePropiedad::getDireccion() {
    return this->direccion;
}

float DataDetallePropiedad::getVenta() {
    return this->venta;
}

DataDetallePropiedad::~DataDetallePropiedad() {
    
}





