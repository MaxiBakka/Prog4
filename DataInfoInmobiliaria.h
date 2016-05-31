#ifndef DATAINFOINMOBILIARIA_H_INCLUDED
#define DATAINFOINMOBILIARIA_H_INCLUDED

#include <string>
#include DataZona.h
#include DataDepartamento.h

using namespace std;

class DataInfoInmobiliaria{
private:
    string nombre;
    string ubicacion;
    string email;
    DataDepartamento dtdepartamento;
    DataZona dtzona;
public:
    DataInfoInmobiliaria(string n,string u,string e);
    string get_nombre();
    string get_ubicacion();
    string get_email();
    DataDepartamento get_dtdepartamento();
    DataZona get_dtzona();
    ~DataInfoInmobiliaria;
};


#endif // DATAINFOINMOBILIARIA_H_INCLUDED
