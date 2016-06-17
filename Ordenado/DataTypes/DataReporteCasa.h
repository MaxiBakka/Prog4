#ifndef DATAREPORTECASA_H
#define	DATAREPORTECASA_H

#include "DataReportePropiedad.h"
#include <iostream>
#include <iomanip>

using namespace std;

class DataReporteCasa :public DataReportePropiedad {
private:
    float m2Edificados;
    float espacioVerde;
public:
    DataReporteCasa(int c,int cda, int d,int b,bool g,string &dir,float iv,float ia,float m2E,float ev,DataZona* dz,DataDepartamento* dpto);
    float getM2Edificados();
    float getEspacioVerde();
    float getM2Totales();
    virtual ~DataReporteCasa();

};

ostream& operator<<(ostream& o, DataReporteCasa& dra);

#endif	/* DATAREPORTECASA_H */
