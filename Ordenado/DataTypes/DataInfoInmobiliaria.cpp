#include "DataInfoInmobiliaria.h"

#include "DataReporteApartamento.h"
#include "DataReporteCasa.h"
DataInfoInmobiliaria::DataInfoInmobiliaria(string n,string u,string e,set<DataReportePropiedad*>* propiedades){
    this->nombre=n;
    this->ubicacion=u;
    this->email=e;
    this->reportePropiedades= propiedades;
}

string& DataInfoInmobiliaria::get_nombre(){
    return this->nombre;
}

string& DataInfoInmobiliaria::get_ubicacion(){
    return this->ubicacion;
}

string& DataInfoInmobiliaria::get_email(){
    return this->email;
}

set<DataReportePropiedad*>* DataInfoInmobiliaria::getReportePropiedades() {

    return reportePropiedades;
}

DataInfoInmobiliaria :: ~DataInfoInmobiliaria(){

  for(set<DataReportePropiedad*>::iterator it = reportePropiedades->begin(); it!=reportePropiedades->end(); ++it){
		delete *it;
	}
}

ostream& operator<<(ostream& o, DataInfoInmobiliaria& di){

    o << "Nombre inmobiliaria:" << di.get_nombre() << '\n' << "Ubicacion:" << di.get_ubicacion()<< '\n'<< "Email:" << di.get_email() << '\n'
    << "Listado de Propiedades: " << '\n' << '\n';
    for(set<DataReportePropiedad*>::iterator it = di.getReportePropiedades()->begin();it!=di.getReportePropiedades()->end();++it){
        DataReporteApartamento* drp =dynamic_cast<DataReporteApartamento*> (*it);
        if(drp!=0){

           o << *drp;
        }else if(DataReporteCasa* drp =dynamic_cast<DataReporteCasa*> (*it)){

        o << *drp;
        }

    }
    return o;

}
