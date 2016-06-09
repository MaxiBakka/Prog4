#ifndef Zona_h
#define Zona_h

#include<string>
#include<map>
#include "DataZona.h"
#include "Propiedad.h"

using namespace std;

class Departamento;//fwd declaration

class Zona {
private:
    int codigo;
    string nombre;
    Departamento* departamento;
    map<int,Propiedad*>*propiedades;
public:
    Zona(int c,string n,Departamento* &d); //en el metodo le agregas una coleccion de propiedades vacia
    int getCodigo();
    string getNombre();
    Departamento* getDepartamento();
    DataZona* getDataZona();
    void AgregarPropiedad(Propiedad* p);
    void RemoverPropiedad(Propiedad* p);
    set<Propiedad*>* getPropiedades();
    ~Zona();
};

#endif // Zona_h
