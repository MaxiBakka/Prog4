#include "../DataTypes/DataVenta.h"


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

ostream & operator <<(ostream &o, DataVenta& dv){

    if (dv.get_precio()>0)
            o << "El precio de Venta es: " << dv.get_precio() << endl;
    return o;
}
