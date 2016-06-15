#include "DataEdificio.h"


DataEdificio :: DataEdificio(string name, int cpisos, float gComunes){
	this->nombre=name;
	this->cantPisos=cpisos;
	this->gastosComunes=gComunes;
}

string DataEdificio :: get_nombre(){
	return this->nombre;
}

int DataEdificio :: get_cantPisos(){
	return this->cantPisos;
}

float DataEdificio :: get_gastosComunes(){
	return this->gastosComunes;
}

DataEdificio::~DataEdificio(){


}
