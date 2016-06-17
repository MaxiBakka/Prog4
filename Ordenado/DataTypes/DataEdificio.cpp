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

ostream& operator<<(ostream& o, DataEdificio& de){
o << setprecision(10);
o << "Nombre edificio: " << de.get_nombre() << '\n' << "Cantidad de pisos: " << de.get_cantPisos()<< '\n'<< "Gastos Comunes: " << de.get_gastosComunes() << '\n';

    return o;

}
