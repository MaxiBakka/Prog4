#ifndef Departamento.h
#define  Departamento.h

#include <string>
#include <map>
#include <set>

#include "Zona.h"
#include "DataZona.h"

class DataDepartamento;

using namespace std;

class Departamento{
  private:
          string nombre;
          string letra;
          map<int,Zona*>*zonas;

  public:
          //constructor
          Departamento(const string&,const string&);
          //getters
          const string& getNombre() const;
          const string& getLetra() const;
          //getters de datatypes
          DataDepartamento *getDataDepartamento();
          set<DataZona*>* getDataZonas();
          //setters
          void setNombre(const string& nombre);
          void setLetra(const string& letra);
          //Operaciones
          void AddZona(Zona*z);
          Zona* ObtenerZona(int codigo);
          //void borrarZona(int codigo);

          //Destructor
          virtual ~Departamento();

}

#endif
