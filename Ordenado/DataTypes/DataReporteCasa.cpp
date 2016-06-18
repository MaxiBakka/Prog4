#include "../DataTypes/DataReporteCasa.h"
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

ostream& operator<<(ostream& o, DataReporteCasa& drc){
    o << setprecision(30);
    o << "------- Casa nro:" << drc.getCodigo() << " -------" << endl;
    o << "Direccion: " << drc.getDireccion() << '\n' ;
    o << "Cantidad de ambientes: " << drc.getCantDeAmbientes()<< '\n';
    o << "Dormitorios: " << drc.getDormitorios() << '\n';
    o << "Banios: " << drc.getBanios() << '\n' ;
    o << "Incluye Garaje: ";  if(drc.getGaraje()){o << "Si"; }else{ o<< "No";} o << endl;
    if(drc.getInfoAlquiler()>1){
        o<< "Precio Alquiler: " << drc.getInfoAlquiler() << '\n';
    }
    if(drc.getInfoVenta()>1){
        o<< "Precio Venta: " << drc.getInfoVenta() << '\n';
    }
    o << "M2 totales: " << drc.getM2Totales() << endl;
    o << "M2 Edificados: " << drc.getM2Edificados() << endl;
    o << "Espacio verde: " << drc.getEspacioVerde() << endl;
    if(drc.getDataDepartamento()!=NULL)
    o << "Departamento: " << *drc.getDataDepartamento() << endl;
    if(drc.getDataZona()!=NULL)
    o << "Zona: " << drc.getDataZona()->get_nombre() << " - Codigo: " << drc.getDataZona()->get_codigo() << endl;

    o << "------------------------------------------------------------------------------------------------" << endl;

    return o;
 }
