#ifndef DataApartamento_h
#define DataApartamento_h

#include <string>
#include <iostream>

#include "DataPropiedad.h"

using namespace std;

class DataApartamento: public DataPropiedad{

private:

	float m2edificados;
public:

		DataApartamento(int cod,
			  int cAmbientes,
			  int dormitorios,
			  int banios,
				string& direc,
				bool garaje,
				float infoAlquiler,
				float infoVenta,
				float m2Tot,
				float m2edif);

		virtual ~DataApartamento();
		//getterss

		virtual int getCodigo();
		virtual string& getDireccion();
		virtual int getCantAmbientes();
		virtual int getDormitorios();
		virtual int getBanios();
		virtual bool getGaraje();
		virtual float & getAlquiler();
		virtual float & getVenta();
		float getM2totales();
		float getM2edificados();


};

ostream &operator <<(ostream &output,DataApartamento& da);


#endif
