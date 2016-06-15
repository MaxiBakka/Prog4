#ifndef DATAREPORTEAPARTAMENTO_H
#define	DATAREPORTEAPARTAMENTO_H

#include "DataReportePropiedad.h"

using namespace std;

class DataReporteApartamento:public DataReportePropiedad {
    private:
        float m2Totales;
        float m2Edificados;
public:
    DataReporteApartamento(int c,int cda, int d,int b,bool g,string &dir,float iv,float ia,DataZona* dz,DataDepartamento* dpto,float m2t,float m2e);
    float getM2Totales();
    float getM2Edificados();
    virtual ~DataReporteApartamento();
};

#endif	/* DATAREPORTEAPARTAMENTO_H */

