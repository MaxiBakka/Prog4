#include "../DataTypes/DataInfoInmobiliaria.h"

#include "../DataTypes/DataReporteApartamento.h"
#include "../DataTypes/DataReporteCasa.h"


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

void DataInfoInmobiliaria::imprimirCasasYApartamentos(DataZona* dz){
  int cantCasas=0;
  int cantApartamento=0;
  DataReporteCasa* drc;
  DataReporteApartamento* dra;
  for(set<DataReportePropiedad*>::iterator it=reportePropiedades->begin();it!=reportePropiedades->end();++it){
    DataReportePropiedad* drprop = dynamic_cast<DataReportePropiedad*>(*it);
    drc = dynamic_cast<DataReporteCasa*>(drprop);
    if((drc != NULL) && ((drc->getDataZona()->get_codigo()==dz->get_codigo()))){
      cantCasas++;
    }else{
     dra = dynamic_cast<DataReporteApartamento*>(drprop);
      if((dra!=NULL)&&(dra->getDataZona()->get_codigo()==dz->get_codigo()))
        cantApartamento++;
    }
 }
  cout << "Cantidad de casas: " << cantCasas <<endl;
  cout << "Cantidad de apartamentos: " << cantApartamento << endl;
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
