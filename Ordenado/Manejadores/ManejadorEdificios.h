#ifndef ManejadorEdificios_h
#define  ManejadorEdificios_h

#include <map>
#include <string>
#include <set>

#include "../ClasesDeDominio/Edificio.h"



using namespace std;

class ManejadorEdificios{
private:
        static ManejadorEdificios*instancia;
        ManejadorEdificios();
        map<string,Edificio*>*edificios;
public:
      static ManejadorEdificios*getInstancia();

      //destructor
      virtual ~ManejadorEdificios();

      //Obtencion Datatypes
      set<DataEdificio*>* getEdificios();
      //get Edificio
      Edificio* getEdificio(const string& nombre);
      //Crear Edificio (AltaEdificio)
      void addEdificio(DataEdificio*de);

};

#endif
