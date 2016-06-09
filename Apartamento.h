#ifndef APARTAMENTO_H
#define	APARTAMENTO_H

#include<string>

#include "Propiedad.h"
#include "DataApartamento.h"
class Edificio; //fwd declaration

using namespace std;

class Apartamento:public Propiedad {
private:
    Edificio* edificio;
public:
    Apartamento(int cod,int cda,int dormi,int banios,bool garaje,string dir,float m2t,Zona* z,Edificio* e);
    float getM2Edificados();
    Edificio* getEdificio();
    DataApartamento* getDataApartamento();
    ~Apartamento();
    bool estaEnZona(int cod);

};

#endif	/* APARTAMENTO_H */

