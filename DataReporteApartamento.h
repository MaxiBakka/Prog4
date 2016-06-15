#ifndef DATAREPORTEAPARTAMENTO_H
#define	DATAREPORTEAPARTAMENTO_H

#include "DataReportePropiedad.h"

class DataReporteApartamento:public DataReportePropiedad {
    private:
        float m2Totales;
public:
    DataReporteApartamento(int c,int cda, int d,int b,bool g,string &dir,float iv,float ia,float m2t);
    float getM2Totales();
    float getM2Edificados();
    ~DataReporteapartamento();
};

#endif	/* DATAREPORTEAPARTAMENTO_H */

