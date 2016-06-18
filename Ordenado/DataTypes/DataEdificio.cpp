#include "DataEdificio.h"
#include <sstream>

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

ostream& operator <<(ostream& o, const set<DataEdificio*> sds) {
	//estaleciendo cabezales
	string headNombre = "Edificio"; int colNombre = 25; headNombre.resize(colNombre,' ');
	string headpisos = "Cantidad de pisos"; int colpisos = 20; headpisos.resize(colpisos, ' ');
	string headgcomunes = "Gastos comunes";

	//imprimir cabezales
	o<< headNombre << "   " << headpisos << "   " << headgcomunes << endl;
	o << setprecision(10);
	//imprimir registros
	for(set<DataEdificio*>::iterator it=sds.begin();it!=sds.end();++it){
		DataEdificio* row  = dynamic_cast<DataEdificio*>(*it);
		string rowNombre = row->get_nombre(); rowNombre.resize(colNombre,' ');
		stringstream ss; int x = row->get_cantPisos(); ss << x;

    string rowpisos = ss.str();rowpisos.resize(colpisos, ' ');
		float rowgcomunes = row->get_gastosComunes();

		o<< rowNombre << " | " << rowpisos << " | " << rowgcomunes << endl;
	}
	return o;
}
