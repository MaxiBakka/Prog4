#include "DataInfoInmobiliaria.h"

DataInfoInmobiliaria::DataInfoInmobiliaria(string n,string u,string e){
    this->nombre=n;
    this->ubicacion=u;
    this->email=e;
}

string DataInfoInmobiliaria::get_nombre(){
    return this->nombre;
}

string DataInfoInmobiliaria::get_ubicacion(){
    return this->ubicacion;
}

string DataInfoInmobiliaria::get_email(){
    return this->email;
}

void DataInfoInmobiliaria::agregarDataReportePropiedad(DataReportePropiedad*& drp) {
    this->reportePropiedades->insert(drp);
}

set<DataReportePropiedad*>* DataInfoInmobiliaria::getReportePropiedades() {
    new set<DataReportePropiedad*>* res (this->reportePropiedades);
    return res;    
}

DataInfoInmobiliaria :: ~DataInfoInmobiliaria(){}
