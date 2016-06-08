
#ifndef CASA_H
#define	CASA_H

#include<string>

#include "Propiedad.h"
#include "DataCasa.h"

using namespace std;

class Casa:public Propiedad{
private:
    int espacioVerde;
    float m2Edificados;
public:
    Casa(int cod,int cda,int dormi,int banios,bool garaje,string dir,float m2t,Zona* z,int ev,float m2e);
    int getEspacioVerde();
    float getM2Edificados();
    DataCasa* getDataCasa();
    ~Casa();

};

#endif	/* CASA_H */

