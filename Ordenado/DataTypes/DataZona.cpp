#include "../DataTypes/DataZona.h"


DataZona :: DataZona(int code, string name){
	this->codigo=code;
	this->nombre=name;
}

int DataZona :: get_codigo(){
	return this->codigo;
}

string DataZona :: get_nombre(){
	return this->nombre;
}

DataZona::~DataZona(){

}

ostream & operator <<(ostream &o, DataZona& dz){

    o << "Nombre: " << dz.get_nombre() << endl << "Codigo: " << dz.get_codigo() << endl;
    return o;
}
