#ifndef DATAINFOINMOBILIARIA_H_INCLUDED
#define DATAINFOINMOBILIARIA_H_INCLUDED

#include <string>
#include <iostream>
#include<set>
#include "DataReportePropiedad.h"

using namespace std;

class DataInfoInmobiliaria{
private:
    string nombre;
    string ubicacion;
    string email;
    set<DataReportePropiedad*>* reportePropiedades;
public:
    DataInfoInmobiliaria(string& n,string& u,string& e,set<DataReportePropiedad*>* propiedades);
    string& get_nombre();
    string& get_ubicacion();
    string& get_email();
    set<DataReportePropiedad*>* getReportePropiedades();
    ~DataInfoInmobiliaria();

};

ostream& operator<<(ostream& o,DataInfoInmobiliaria& di);


#endif // DATAINFOINMOBILIARIA_H_INCLUDED
