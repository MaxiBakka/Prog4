#include "RutinaCargarDatos.h"
#include "../Menus/MenuUtils.h"
#include "../Fabrica/Factory.h"
#include "../Excepciones/DatosYaCargados.h"
#include "../Interfaces/ICargarDatosController.h"

#include <iostream>

RutinaCargarDatos::RutinaCargarDatos(){

}
RutinaCargarDatos::~RutinaCargarDatos(){}

void RutinaCargarDatos::ejecutar(){
	try{
		ICargarDatosController* ctrl = Factory::getICargarDatosController();
		cout<<"Cargar Set de Datos de Prueba"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"Comienza la carga de datos, por favor aguarde"<<endl<<endl;
		ctrl->cargarDatosdeSistema();
		cout<<"Datos cargados exitosamente"<<endl;
	}catch(DatosYaCargados &e){
		cout<< e.what()<<endl;
	}
	delete ctrl;
	MenuUtils::esperarInput();
}
