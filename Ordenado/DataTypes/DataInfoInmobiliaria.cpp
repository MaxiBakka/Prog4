#include "DataInfoInmobiliaria.h"

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

ostream& operator<<(ostream& o, const DataInfoInmobiliaria& di){
  //ver en que formato imprimir

}
