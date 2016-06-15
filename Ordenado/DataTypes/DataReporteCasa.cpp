#include "DataReporteCasa.h"

DataReporteCasa::DataReporteCasa(int c, int cda, int d, int b, bool g, string& dir, float iv, float ia, float m2E, float ev,DataZona* dz,DataDepartamento* dpto):DataReportePropiedad(c,cda,d,b,g,dir,iv,ia,dz,dpto) {
    this->espacioVerde=ev;
    this->m2Edificados=m2E;
}

float DataReporteCasa::getEspacioVerde() {
    return this->espacioVerde;
}

float DataReporteCasa::getM2Edificados() {
    return this->m2Edificados;
}

float DataReporteCasa::getM2Totales() {
    return (this->espacioVerde + this->m2Edificados);
}

DataReporteCasa::~DataReporteCasa() {
}

