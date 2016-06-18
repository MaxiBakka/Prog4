#include "RutinaObtenerReporteInmobiliarias.h"
#include "Factory.h"
#include "ProcesoCancelado.h"
#include "../DataTypes/DataDepartamento.h"
#include "ManejadorDepartamentos.h"
#include "ExNoHayZonas.h"



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
		cout<< "Obteniendo reporte por favor espere..."<<endl<<endl;
		set<DataInfoInmobiliaria*>* reportes = ctrl->ObtenerReporte();
		ManejadorDepartamentos* md= ManejadorDepartamentos::getInstancia();
        cout<< "Reporte: "<<endl;

			for(set<DataInfoInmobiliaria*>::iterator it = reportes->begin(); it != reportes->end(); ++it){
				DataInfoInmobiliaria* cast = dynamic_cast<DataInfoInmobiliaria*>(*it);
				cout << endl;
                cout << "---------------------------------------------------------------" << endl;
                cout << "Inmobiliaria: " << cast->get_nombre() << endl<<endl;
				set<DataDepartamento*>* Departamentos = md->getDepartamentos();

				for(set<DataDepartamento*>::iterator itd = Departamentos->begin();itd!=Departamentos->end();++itd){
                    try{
                    DataDepartamento* ddpto=dynamic_cast<DataDepartamento*>(*itd);
                    Departamento* dpto = md->getDepartamento(ddpto->get_letra());
                    cout << endl;
                    cout<< "Departamento: " << ddpto->get_nombre() <<endl;
                    set<DataZona*>* Zonas=dpto->getDataZonas();
                    delete ddpto;
                    for(set<DataZona*>::iterator itz=Zonas->begin();itz!=Zonas->end();++itz){
                        DataZona* dzona= dynamic_cast<DataZona*>(*itz);
                        cout << endl;
                        cout << "Zona: " << dzona->get_nombre() << endl<<endl;
                        cast->imprimirCasasYApartamentos(dzona);
                        }
                    }catch(ExNoHayZonas& e){
                            cout << endl << "El departamento no contiene zonas " << endl;
                        }
                    }
                }
        delete md;
        delete reportes;
		cout << endl;
        MenuUtils::esperarInput();
}
