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

ostream& operator<<(ostream& o, DataReporteApartamento& dra){
    o << setprecision(30);
    o << "------- Apartamento Nro" << dra.getCodigo() << " -------" << endl;
    o << "Direccion: " << dra.getDireccion() << '\n' ;
    o << "Cantidad de ambientes: " << dra.getCantDeAmbientes()<< '\n';
    o << "Dormitorios: " << dra.getDormitorios() << '\n';
    o << "Banios: " << dra.getBanios() << '\n' ;
    o << "Incluye Garaje: ";  if(dra.getGaraje()){o << "Si"; }else{ o<< "No";} o << endl;
    if(dra.getInfoAlquiler()>1){
        o<< "Precio Alquiler: " << dra.getInfoAlquiler() << '\n';
    }
    if(dra.getInfoVenta()>1){
        o<< "Precio Venta: " << dra.getInfoVenta() << '\n';
    }
    o << "M2 totales: " << dra.getM2Totales() << '\n';
    o << "M2 Edificados: " << dra.getM2Edificados() << '\n';
    if(dra.getDataDepartamento()!=NULL)
    o << "Departamento: " << *dra.getDataDepartamento() << endl;
    if(dra.getDataZona()!=NULL)
    o << "Zona: " << dra.getDataZona()->get_nombre() << " - Codigo: " << dra.getDataZona()->get_codigo() << endl;
    o << "------------------------------------------------------------------------------------------------" << endl;

    return o;
 }
