#include "DtConsultaPropiedad.h"

DtConsultaPropiedad :: DtConsultaPropiedad(){
	this->codigo = -1;
	this->direccion = "";
	this->venta = false;
	this->alquiler = false;
}

DtConsultaPropiedad :: DtConsultaPropiedad(int code, string dir, bool v, bool a){
	this->codigo = code;
	this->direccion = dir;
	this->venta = v;
	this->alquiler = a;
}

int DtConsultaPropiedad :: get_codigo(){
	return this->codigo;
}

string DtConsultaPropiedad :: get_direccion(){
	return this->direccion;
}

bool DtConsultaPropiedad :: get_venta(){
	return this->venta;
}

bool DtConsultaPropiedad :: get_alquiler(){
	return this->alquiler;
}

DtConsultaPropiedad :: ~DtConsultaPropiedad(){

}
