#include "RutinaObtenerReporteInmobiliarias.h"
#include "../Fabrica/Factory.h"
#include "../Excepciones/ProcesoCancelado.h"
#include "../DataTypes/DataDepartamento.h"
#include "../Manejadores/ManejadorDepartamentos.h"
#include "../Excepciones/ExNoHayZonas.h"
#include "../Excepciones/NoHayDepartamentos.h"


#include <iostream>
#include <set>
#include <string>


#include "../Menus/MenuUtils.h"

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
								cout << "Inmobiliaria: " << cast->get_nombre() << endl;
                cout << "Ubicacion: " << cast->get_ubicacion()<< '\n'<< "Email: " << cast->get_email() << '\n'<< endl;
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
                    }catch(NoHayDepartamentos& e2){
                            cout << endl << "La inmobiliaria no tiene ofertas"<<endl;
					}
                    }
                }
        for(set<DataInfoInmobiliaria*>::iterator it = reportes->begin(); it != reportes->end(); ++it){
            DataInfoInmobiliaria* borrar = *it;
            delete borrar;
        }
        delete reportes;

		cout << endl;
        MenuUtils::esperarInput();
}
