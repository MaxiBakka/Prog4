
#include "DataDetallePropiedad.h"

DataDetallePropiedad::DataDetallePropiedad(int codigo, string& direccion, bool venta, bool alquiler) {
    this->codigo=codigo;
    this->direccion=direccion;
    this->venta=venta;
    this->alquiler=alquiler;
}

bool DataDetallePropiedad::getAlquiler() {
    return this->alquiler;
}

int DataDetallePropiedad::getCodigo() {
    return this->codigo;
}

string& DataDetallePropiedad::getDireccion() {
    return this->direccion;
}

bool DataDetallePropiedad::getVenta() {
    return this->venta;
}

DataDetallePropiedad::~DataDetallePropiedad() {

}

ostream& operator<<(ostream& o, const DataDetallePropiedad& ddp){



}
