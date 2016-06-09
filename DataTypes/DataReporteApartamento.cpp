
#include "DataReporteApartamento.h"

DataReporteApartamento::DataReporteApartamento(int c, int cda, int d, int b, bool g, string& dir, float iv, float ia, float m2t):DataReportePropiedad(c,cda,d,b,g,dir,iv,ia) {
    this->m2Totales=m2t;
}

float DataReporteApartamento::getM2Edificados() {
    return this->m2Totales;
}

float DataReporteApartamento::getM2Totales() {
    return this->m2Totales;
}

DataReporteApartamento::~DataReporteapartamento() {
    
}






