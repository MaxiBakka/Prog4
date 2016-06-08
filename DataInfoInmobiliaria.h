#ifndef DATAINFOINMOBILIARIA_H_INCLUDED
#define DATAINFOINMOBILIARIA_H_INCLUDED

#include <string>
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
    DataInfoInmobiliaria(string n,string u,string e);
    string get_nombre();
    string get_ubicacion();
    string get_email();
    set<DataReportePropiedad*>* getReportePropiedades();
    void agregarDataReportePropiedad(DataReportePropiedad* &drp);
    ~DataInfoInmobiliaria();
};


#endif // DATAINFOINMOBILIARIA_H_INCLUDED
