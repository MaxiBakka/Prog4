#ifndef DataCasa_h
#define DataCasa_h

#include <string>
#include "DataPropiedad.h"
#include <iostream>


using namespace std;

class DataCasa : public DataPropiedad{

private:

		float m2edificados,espacioverde;

public:

DataCasa(int cod,int cAmbientes, int Dormitorios , int banios, string& direc, bool gar,float &infoAlquiler, float &infoVenta, float m2Tot,float m2edif,float everde);
virtual ~DataCasa();

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
		float getEspacioVerde();



};

ostream &operator <<(ostream &output,DataCasa& dc);


#endif
