#ifndef Edificio_h
#define  Edificio_h

#include <map>
#include <string>

#include "Apartamento.h"
#include "../DataTypes/DataEdificio.h"

using namespace std;

class Edificio{
private:
        string nombre;
        int cantPisos;
        float gastosComunes;
        map<int,Apartamento*>*apartamentos;
public:
      //constructores y destructores
      Edificio(const string& nombre,int cantPisos,float gcomunes);
      Edificio(DataEdificio*de);
      ~Edificio();


      //getters y setters
      const string& getNombre();
      int getCantPisos();
      float getGastosComunes();
      void setNombre(const string& nombre);
      void setCantPisos(int cantPisos);
      void setGastosComunes(float &gcomunes);

      //datatypes
      DataEdificio*getDataEdificio();

      //apartamentos
      void agregarApartamento(Apartamento*apto);
      void RemoverApartamento(int codigo);
      bool ExisteApartamento(int codigo);

};


#endif
