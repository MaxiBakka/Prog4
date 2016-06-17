
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

ostream& operator<<(ostream& output, DataDetallePropiedad& ddp){

output << "Codigo de la propiedad:" << ddp.getCodigo() << endl << "Direccion:" << ddp.getDireccion()<< endl;
if(ddp.getVenta())
    output << "Propiedad se encuentra a la Venta"<< endl;
if(ddp.getAlquiler())
    output << "Propiedad se encuentra en Alquiler" << endl;

    return output;

}
