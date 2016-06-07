#ifndef ManejadorDepartamentos
#define  ManejadorDepartamentos

#include <map>
#include <string>
#include <set>

#include "Departamento.h"
#include "DataDepartamento.h"

using namespace std;


class ManejadorDepartamentos{
private:
      static ManejadorDepartamentos*instancia;
      ManejadorDepartamentos();
      map<string,Departamento*>*departamentos;

public:
      static ManejadorDepartamentos* getInstancia();

      //destructor
      virtual ~ManejadorDepartamentos();

      //Obtencion Datatypes
      set<DataDepartamento*>* getDepartamentos();

      //get Departamento
      Departamento* getDepartamento(const string& letra);

      //Agregar Departamento
      void AgregarDepartamento(DataDepartamento*dd);
      void EliminarDepartamento(string &letra);

};

#endif
