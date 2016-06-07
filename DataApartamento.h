#ifndef DataApartamento_h
#define DataApartamento_h

#include <string>
#include <iostream>

#include "DataPropiedad.h"
#include "DataVenta.h"
#include "DataAlquiler.h"
#include "DataEdificio.h"

using namespace std;

class DataApartamento: public DataPropiedad{

private:

	float m2totales;
	DataEdificio*edificio;

public:
		DataApartamento(DataApartamento*da);
		DataApartamento(int cAmbientes, int dormitorios , int banios, string direc, bool garaje, DataAlquiler *&infoAlquiler, DataVenta *&infoVenta, float m2Tot,int codigo,DataEdificio *&de);
		virtual ~DataApartamento();
		//getterss

		virtual int getCodigo();
		virtual string getDireccion();
		virtual int getCantAmbientes();
		virtual int getDormitorios();
		virtual int getBanios();
		virtual bool getGaraje();
		virtual DataAlquiler*& getAlquiler();
		virtual DataVenta*& getVenta();
		float getM2totales();
		DataEdificio*& getEdificio();

};

ostream &operator <<(ostream &output,DataApartamento& da);


#endif
