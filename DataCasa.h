#ifndef DataCasa_h
#define DataCasa_h

#include <string>
#include "DataPropiedad.h"
#include "DataInfoAlquiler.h"
#include "DataInfoVenta.h"
using namespace std;

class DataCasa : public DataPropiedad{

private:

		float m2edificados,espacioverde;

public:

		DataCasa(int cAmbientes, int Dormitorios , int banos, string direc, bool gar,DataInfoAlquiler *&infoAlquiler, DataInfoVenta *&infoVenta, float m2Tot, float everde);
        virtual ~DataCasa();

		virtual string getDireccion();
		virtual int getCantAmbientes();
		virtual int getDormitorios();
		virtual int getBanios();
		virtual bool getGaraje();
		virtual DataInfoAlquiler*& getAlquiler();
		virtual DataInfoVenta*& getVenta();
		float getM2edificados();
		float getEspacioVerde();



};


#endif
