#ifndef APARTAMENTO_H
#define	APARTAMENTO_H

#include "Propiedad.h"
#include "DataApartamento.h"
class Edificio; //fwd declaration

class Apartamento:public Propiedad {
public:
    Apartamento(int cod,int cda,int dormi,int banios,bool garaje,string dir,float m2t,Zona* z);
    float getM2Edificados();
    DataApartamento* getDataApartamento();
    ~Apartamento();
    bool estaEnZona(int cod);

};

#endif	/* APARTAMENTO_H */

