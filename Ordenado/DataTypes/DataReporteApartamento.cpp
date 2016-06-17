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

ostream& operator<<(ostream& output, DataReporteApartamento& dra){
    output<< setprecision(30);
    output << "Codigo: " << dra.getCodigo() << '\n' << "Direccion del apartamento: " << dra.getDireccion() << '\n' << "Cantidad de ambientes: " << dra.getCantDeAmbientes()<< '\n'<< "Dormitorios: " << dra.getDormitorios() << '\n'
    << "Banios: " << dra.getBanios() << '\n' << "Garaje: " << dra.getGaraje() << '\n';
    if(dra.getInfoAlquiler()>1){
        output<< "Precio Alquiler: " << dra.getInfoAlquiler() << '\n';
    }
    if(dra.getInfoVenta()>1){
        output<< "Precio Venta: " << dra.getInfoVenta() << '\n';
    }
    output << "M2 totales: " << dra.getM2Totales() << '\n' << "M2 Edificados: " << dra.getM2Edificados() << '\n';

    return output;
 }
