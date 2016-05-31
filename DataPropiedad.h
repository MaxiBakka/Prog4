#ifndef DataPropiedad_h
#define DataPropiedad_h

#include <string>
#include "DataInfoAlquiler.h"
#include "DataInfoVenta.h"


using namespace std;

class DataPropiedad{

protected:
	int cantAmbientes, dormitorios, banios;
	string direccion;
	bool garaje;
	DataInfoAlquiler*info_alquiler;
	DataInfoVenta*info_venta;

public:

		DataPropiedad(int cantAmbientes, int cantDormitorios , int  cantBanios, string direccion, bool garaje, DataInfoAlquiler *&infoAlquiler,
                 DataInfoVenta *&infoVenta):cantAmbientes(cantAmbientes),dormitorios(cantDormitorios),banios(cantBanios),direccion(direccion),garaje(garaje),info_alquiler(infoAlquiler),info_venta(infoVenta){};
		virtual ~DataPropiedad(){};

		virtual string getDireccion()=0;
		virtual int getCantAmbientes()=0;
		virtual int getDormitorios()=0;
		virtual int getBanios()=0;
		virtual bool getGaraje()=0;
		virtual DataInfoAlquiler*& getAlquiler()=0;
		virtual DataInfoVenta*& getVenta()=0;



};


#endif
