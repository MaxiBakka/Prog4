#ifndef DataCasa_h
#define DataCasa_h

#include <string>
#include "DataPropiedad.h"
#include "DataAlquiler.h"
#include "DataVenta.h"

using namespace std;

class DataCasa : public DataPropiedad{

private:

		float m2edificados,espacioverde;

public:

DataCasa(int cod,int cAmbientes, int Dormitorios , int banos, string& direc, bool gar,float infoAlquiler, float infoVenta, float m2Tot,float m2edif,float everde);
virtual ~DataCasa();

		virtual string& getDireccion();
		virtual int getCantAmbientes();
		virtual int getDormitorios();
		virtual int getBanios();
		virtual bool getGaraje();
		virtual float & getAlquiler();
        virtual float & getVenta();
		float getM2totales();
		float getM2edificados();
		float getEspacioVerde();



};


#endif
