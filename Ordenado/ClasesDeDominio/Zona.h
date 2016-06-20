#ifndef Zona_h
#define Zona_h

#include <string>
#include <map>
#include <set>

#include "../DataTypes/DataZona.h"
#include "Propiedad.h"
#include "../DataTypes/DataDepartamento.h"


using namespace std;

class Departamento;//fwd declaration

class Zona {
private:
    int codigo;
    string nombre;
    Departamento* departamento;
    map<int,Propiedad*>*propiedades;
public:
    Zona(int c,string n,Departamento* &d);
    int getCodigo();
    string getNombre();
    Departamento* getDepartamento();
    DataZona* getDataZona();
    //se utiliza para el caso de uso obtener reporte
    DataDepartamento* getDataDepartamento();
    //setters
    void setCodigo(int);
    void setNombre(string&);


    void AgregarPropiedad(Propiedad* p);
    void RemoverPropiedad(int& codigo);
    set<Propiedad*>* getPropiedades();
    Propiedad* getPropiedad(int codigo);
    set<DataDetallePropiedad*>* getDataDetallePropiedad();

    ~Zona();
};

#endif // Zona_h
