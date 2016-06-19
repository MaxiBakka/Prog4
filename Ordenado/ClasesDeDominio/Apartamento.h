#ifndef APARTAMENTO_H
#define	APARTAMENTO_H

#include<string>

#include "Propiedad.h"
#include "Oferta.h"
#include "../DataTypes/DataPropiedad.h"
#include "../DataTypes/DataReportePropiedad.h"

class Edificio; //fwd declaration

using namespace std;

class Apartamento:public Propiedad {
private:
    Edificio* edificio;
    float m2edificados;
public:
    Apartamento(int cod,int cda,int dormi,int banios,bool garaje,string& dir,float m2t,Zona* z,Oferta*of,float m2e,Edificio* e);
    float getM2Edificados();
    Edificio* getEdificio();

    void setM2edificados(float m2e);

    DataReportePropiedad* getDataReportePropiedad();
    DataPropiedad* getDataPropiedad();
    void modificarPropiedad(DataPropiedad*dp);

    virtual ~Apartamento();


};

#endif	/* APARTAMENTO_H */
