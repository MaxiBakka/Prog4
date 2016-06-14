#ifndef DataPropiedad_h
#define DataPropiedad_h

#include <string>
#include <iostream>

#include "DataAlquiler.h"
#include "DataVenta.h"


using namespace std;

class DataPropiedad{

protected:
	int cantAmbientes, dormitorios, banios,codigo;
	string direccion;
	bool garaje;
	float m2Totales;
	float info_alquiler;
	float info_venta;

public:

		DataPropiedad(int cod,int cantAmbientes, int cantDormitorios , int  cantBanios, string direccion, bool garaje,float m2Totales,float &infoAlquiler,
                 float &infoVenta);
		virtual ~DataPropiedad(){};
		//getteres
		virtual string getDireccion()=0;
		virtual int getCantAmbientes()=0;
		virtual int getDormitorios()=0;
		virtual int getBanios()=0;
		virtual bool getGaraje()=0;
		virtual float & getAlquiler()=0;
		virtual float & getVenta()=0;
		virtual float getM2totales()=0;
		virtual int getCodigo()=0;



};

ostream& operator <<(ostream &output,DataPropiedad& dp);

#endif
