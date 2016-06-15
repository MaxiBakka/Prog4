#include "DataReporteApartamento.h"


DataReporteApartamento:: DataReporteApartamento(int c,int cda, int d,int b,bool g,string &dir,float iv,float ia,DataZona* dz,DataDepartamento* dpto,float m2t,float m2e)
:DataReportePropiedad(c,cda,d,b,g,dir,iv,ia,dz,dpto) {
    this->m2Totales=m2t;
    this->m2Edificados=m2e;
}

float DataReporteApartamento::getM2Edificados() {
    return this->m2Edificados;
}

float DataReporteApartamento::getM2Totales() {
    return this->m2Totales;
}

DataReporteApartamento::~DataReporteApartamento() {

}






