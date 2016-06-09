#include "ManejadorDepartamentos.h"

#include <utility>


#include "../exceptions/NoHayDepartamentos.h"
#include "../exceptions/YaExisteDepartamento.h"
#include "../exceptions/ExDptoNoExistente.h"

using namespace std;

ManejadorDepartamentos* ManejadorDepartamentos::instancia = NULL;

ManejadorDepartamentos::ManejadorDepartamenos(){
		departamentos = new map<string,Departamento*>();


};



ManejadorDepartamentos* ManejadorDepartamentos::getInstancia(){
	if (instancia==NULL)
		instancia= new ManejadorDepartamentos();

	return instancia;

}

//Obtencion Datatypes
set<DataDepartamento*>* ManejadorDepartamentos::getDepartamentos(){

if (departamentos->size()==0) throw NoHayDepartamentos();

	set<DataDepartamento*>*dptos = new set<DataDepartamento*>();
	for (map<string,Departamento*>::iterator it = departamentos->begin(); it !=departamentos->end(); ++it) {

		dptos->insert(it->second->getDataDepartamento());
	}

	return dptos;

}

//get Departamento
Departamento* ManejadorDepartamentos::getDepartamento(const string& letra){

	map<string,Departamento*>::iterator it = departamentos->find(letra);
	if(it!= departamentos->end()){
		return it->second;

	}else throw ExDptoNoExistente();
}

bool ManejadorDepartamenos::ExisteDepartamento(string &letra){
		return departamentos->find(letra)!= departamentos->end();
}

 //Agregar Departamento
void ManejadorDepartamentos::AgregarDepartamento(DataDepartamento*dd){
	if (ExisteDepartamento(dd->getLetra())) {
		throw YaExisteDepartamento();
	} else {
		Departamento* d= new Departamento(dd);
		departamentos->insert(pair<string,Departamento*>(dd->getLetra(),d))
	}
}

void Departamento::RemoverDepartamento(string &letra){
	//al querer destruir un departamento se llama a esta operacion del manejador
	if(!ExisteDepartamento(letra)){
		throw ExDptoNoExistente();
	}else{
		Departamento* d = departamentos->find(letra)->second;
		departamentos->erase(letra);
		delete d;
	}

}

//destructor
ManejadorDepartamentos::~ManejadorDepartamentos(){

	for(map<string,Departamento*>::iterator it = departamentos->begin(); it != departamentos->end(); ++it){
		Departamento* d = it->second;
		delete d;
	}
	departamentos->clear();
	delete departamentos;
	instancia = NULL;

}
