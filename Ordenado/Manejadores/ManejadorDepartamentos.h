#ifndef ManejadorDepartamentos_h_
#define  ManejadorDepartamentos_h_

#include <map>
#include <string>
#include <set>

#include "Departamento.h"
#include "../DataTypes/DataDepartamento.h"

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

      //Operaciones de  Departamento
      void AgregarDepartamento(DataDepartamento*dd);
      bool ExisteDepartamento(string &letra);
      void RemoverDepartamento(string &letra);

};

#endif
