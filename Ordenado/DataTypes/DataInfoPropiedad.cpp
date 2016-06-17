#include "DataInfoPropiedad.h"

DataInfoPropiedad :: DataInfoPropiedad(int c,string d,int cmjs){
    this->codigo=c;
    this->direccion=d;
    this->cantMensaje=cmjs;
}

int DataInfoPropiedad :: get_codigo(){
    return this->codigo;
}

string DataInfoPropiedad :: get_direccion(){
    return this->direccion;
}

int DataInfoPropiedad :: get_cantMensajes(){
    return this->cantMensaje;
}

DataInfoPropiedad :: ~DataInfoPropiedad(){}

ostream& operator<<(ostream& o, DataInfoInmobiliaria& di){

    o << "Nombre inmobiliaria:" << di.get_nombre() << '\n' << "Ubicacion:" << di.get_ubicacion()<< '\n'<< "Email:" << di.get_email() << '\n'
    << "Listado de Propiedades: " << '\n' << '\n';
    for(set<DataReportePropiedad*>::iterator it = di.getReportePropiedades()->begin();it!=di.getReportePropiedades()->end();++it){
        DataReportePropiedad* drp = *it;
        o << drp;
    }
    return o;

}
