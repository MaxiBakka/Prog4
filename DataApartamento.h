#ifndef DataApartamento_h
#define DataApartamento_h

#include <string>
#include "DataPropiedad.h"
#include "DataInfoVenta.h"
#include "DataInfoAlquiler.h"

using namespace std;

class DataApartamento: public DataPropiedad{

private:

	float m2totales;

public:

		DataApartamento(int cAmbientes, int dormitorios , int banios, string direc, bool gar, DataInfoAlquiler *&infoAlquiler, DataInfoVenta *&infoVenta, float m2Tot);
		virtual ~DataApartamento();

		virtual string getDireccion();
		virtual int getCantAmbientes();
		virtual int getDormitorios();
		virtual int getBanios();
		virtual bool getGaraje();
		virtual DataInfoAlquiler*& getAlquiler();
		virtual DataInfoVenta*& getVenta();
		float getM2totales();



};


#endif
