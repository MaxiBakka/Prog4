#ifndef DataApartamento_h
#define DataApartamento_h

#include <string>
#include <iostream>

#include "DataPropiedad.h"
#include "DataVenta.h"
#include "DataAlquiler.h"

using namespace std;

class DataApartamento: public DataPropiedad{

private:

	float m2totales;

public:
		DataApartamento(DataApartamento*da);
		DataApartamento(int codigo,int cAmbientes, int dormitorios , int banios, string direc, bool garaje, DataAlquiler *&infoAlquiler, DataVenta *&infoVenta, float m2Tot);
		virtual ~DataApartamento();

		virtual string getDireccion();
		virtual int getCantAmbientes();
		virtual int getDormitorios();
		virtual int getBanios();
		virtual bool getGaraje();
		virtual DataAlquiler*& getAlquiler();
		virtual DataVenta*& getVenta();
		float getM2totales();

};

ostream &operator <<(ostream &output,DataApartamento*da);


#endif
