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

ostream& operator<<(ostream& output, DataReporteCasa& drc){

    output<< setprecision(30);
    output << "Codigo:" << drc.getCodigo() << '\n' << "Direccion del apartamento:" << drc.getDireccion() << '\n' << "Cantidad de ambientes:" << drc.getCantDeAmbientes()<< '\n'<< "Dormitorios:" << drc.getDormitorios() << '\n'
    << "Banios:" << drc.getBanios() << '\n' << "Garaje:" << drc.getGaraje() << '\n';
    if(drc.getInfoAlquiler()>1){
        output<< "Precio Alquiler:" << drc.getInfoAlquiler() << '\n';
    }
    if(drc.getInfoVenta()>1){
        output<< "Precio Venta:" << drc.getInfoVenta() << '\n';
    }
    output << "M2 totales:" << drc.getM2Totales() << '\n' << "M2 Edificados:" << drc.getM2Edificados() << '\n';

    return output;
}
