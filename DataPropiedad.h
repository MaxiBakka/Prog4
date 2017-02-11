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
	DataAlquiler*info_alquiler;
	DataVenta*info_venta;

public:

		DataPropiedad(int cantAmbientes, int cantDormitorios , int  cantBanios, string direccion, bool garaje, DataAlquiler *&infoAlquiler,
                 DataVenta *&infoVenta,int cod):cantAmbientes(cantAmbientes),dormitorios(cantDormitorios),banios(cantBanios),codigo(cod),direccion(direccion),garaje(garaje),info_alquiler(infoAlquiler),info_venta(infoVenta){};
		virtual ~DataPropiedad(){};
		//getteres
		virtual string getDireccion()=0;
		virtual int getCantAmbientes()=0;
		virtual int getDormitorios()=0;
		virtual int getBanios()=0;
		virtual bool getGaraje()=0;
		virtual DataAlquiler*& getAlquiler()=0;
		virtual DataVenta*& getVenta()=0;
		virtual int getCodigo()=0;



};

ostream& operator <<(ostream &output,DataPropiedad& dp);

#endif
