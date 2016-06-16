#include "RutinaCargarDatos.h"
#include "MenuUtils.h"

RutinaCargarDatos::RutinaCargarDatos(){
	CargarDatosController* ctrl = Factory::getICargarDatosController();
}
RutinaCargarDatos::~RutinaCargarDatos(){}

void RutinaCargarDatos::ejecutar(){
	try{
		cout<<"Cargar Set de Datos de Prueba"<<endl;
		cout<<"-----------------------------"<<endl;
		cout<<"Comienza la carga de datos, por favor aguarde"<<endl<<endl;
		ctrl->cargarDatosdeSistema();
		cout<<"Datos cargados exitosamente"<<endl;
	}catch(DatosYaCargados &e){
		cout<< e.what()<<endl;
	}
	delete ctrl;
	MenuUtils::limpiarConsola()
}
