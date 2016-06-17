#include "DataReporteCasa.h"
#include <iomanip>

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

ostream& operator<<(ostream& o, DataReporteCasa& dra){
    o << setprecision(30);
    o << "------- Casa nº" << dra.getCodigo() << " -------" << endl;
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
    o << "M2 totales: " << dra.getM2Totales() << endl;
    o << "M2 Edificados: " << dra.getM2Edificados() << endl;
    o << "Espacio verde: " << dra.getEspacioVerde() << endl;
    o << "Departamento: " << *dra.getDataDepartamento() << endl;
    o << "Zona: " << dra.getDataZona()->get_nombre() << " - Codigo: " << dra.getDataZona()->get_codigo() << endl;
    o << "------------------------------------------------------------------------------------------------" << endl;

    return o;
 }
