#include "../DataTypes/DataDepartamento.h"



DataDepartamento :: DataDepartamento(string name, string letra){
	this->nombre = name;
	this->letra = letra;
}

string& DataDepartamento :: get_nombre(){
	return this->nombre;
}

string& DataDepartamento :: get_letra(){
	return this->letra;
}

DataDepartamento::~DataDepartamento(){

}

ostream& operator <<(ostream& output, DataDepartamento& de){

 output << "Nombre departamento:" << de.get_nombre() << endl << "Letra departamento:" << de.get_letra()<< endl;

     return output;

 }
