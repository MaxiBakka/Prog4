#include "ManejadorDepartamentos.h"


ManejadorDepartamentos* ManejadorDepartamentos::instancia = NULL;

ManejadorDepartamentos::ManejadorDepartamenos(){
		departamentos = new map<string,Departamento*>();


};



ManejadorDepartamentos* ManejadorDepartamentos::getInstancia({
	if (instancia==NULL)
		instancia= new ManejadorDepartamentos();

	return instancia;

}

//Obtencion Datatypes
set<DataDepartamento*>* ManejadorDepartamentos::getDepartamentos(){

	set<DataDepartamento*>*dptos = new set<DataDepartamento*>();

	for (map<string,Departamento*>::iterator it = departamentos->begin(); it !=departamentos->end(); ++it) {

		dptos->insert(*it->getDataDepartamento());
	}

	return dptos;

}

//get Departamento
Departamento* ManejadorDepartamentos::getDepartamento(const string& letra){

	map<string,Departamento*>::iterator it = departamentos->find(letra);
	if(it!= departamentos->end()){
		Departamento*dpto= it->second;

	}else throw ExDptoNoExistente;

	return dpto;
}

 //Agregar Departamento
void ManejadorDepartamentos::AgregarDepartamento(DataDepartamento*dd){
	departamentos->insert(//pairnosecuanto)

}
void ManejadorDepartamentos::EliminarDepartamento(string &letra){

}


ManejadorDepartamentos::~ManejadorDepartamentos(){

}
