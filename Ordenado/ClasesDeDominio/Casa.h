
#ifndef CASA_H
#define	CASA_H

#include <string>

#include "Propiedad.h"
#include "Oferta.h"
#include "DataPropiedad.h"
#include "DataReportePropiedad.h"

using namespace std;

class Casa:public Propiedad{
private:
    int espacioVerde;
    float m2Edificados;
public:
    Casa(int cod,int cda,int dormi,int banios,bool garaje,string dir,float m2t,Zona* z,Oferta* of,int ev,float m2e);
    int getEspacioVerde();
    float getM2Edificados();

    void setEspacioVerde(int espverde);
    void setM2edificados(float m2edificados);
    DataPropiedad* getDataPropiedad();
    DataReportePropiedad* getDataReportePropiedad();

    void modificarPropiedad(DataPropiedad*dp);
    virtual ~Casa();

};

#endif	/* CASA_H */
