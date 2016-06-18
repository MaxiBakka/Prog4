#include "RutinaObtenerReporteInmobiliarias.h"
#include "Factory.h"
#include "ProcesoCancelado.h"

#include <iostream>
#include <set>
#include <string>


#include "MenuUtils.h"

using namespace std;

RutinaObtenerReporteInmobiliarias::RutinaObtenerReporteInmobiliarias() {
	ctrl = Factory::getIUsuarioController();
}

RutinaObtenerReporteInmobiliarias::~RutinaObtenerReporteInmobiliarias(){
delete ctrl;
}

void RutinaObtenerReporteInmobiliarias::ejecutar() {
	try{
		cout<< "Obteniendo reporte por favor espere..."<<endl<<endl;
		set<DataInfoInmobiliaria*>* reportes = ctrl->ObtenerReporte();
		set<DataInfoInmobiliaria*>::iterator it = reportes->begin();
		if( it != reportes->end()){
			cout<< "Reporte: "<<endl;
			for(set<DataInfoInmobiliaria*>::iterator it = reportes->begin(); it != reportes->end(); ++it){
				DataInfoInmobiliaria* cast = dynamic_cast<DataInfoInmobiliaria*>(*it);
				cout<< "Departamento: " << cast->getDataDepartamento() <<endl;
				cout << "Zona: " << cast->getDataZona() << endl;
				cast->imprimirCasasYApartamentos();
				delete cast;
			}
		}else{
			throw ProcesoCancelado();
		}
	}catch(ProcesoCancelado&){
		cout<<"No existen inmobiliarias que reportar"<<endl;
	}
}
