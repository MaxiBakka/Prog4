#include "DataCasa.h"


DataCasa :: DataCasa(int cod,int cAmbientes, int Dormitorios , int banios, string& direc, bool gar,float &infoAlquiler, float &infoVenta,float m2Tot,float m2edif,float everde):
    DataPropiedad(cod,cAmbientes,Dormitorios,banios,direc,gar,m2Tot,infoAlquiler,infoVenta){

		this->m2edificados=m2edif;
		this->espacioverde=everde;
}

string& DataCasa :: getDireccion(){
	return this->direccion;
}

int DataCasa :: getCantAmbientes(){
	return this->cantAmbientes;
}

int DataCasa :: getDormitorios(){
	return this->dormitorios;
}

int DataCasa :: getBanios(){
	return this->banios;
}
bool DataCasa :: getGaraje(){
	return this->garaje;
}
int DataCasa:: getCodigo(){
	return this->codigo;
}

float & DataCasa :: getAlquiler(){
	return this->info_alquiler;
}

float & DataCasa :: getVenta(){
	return this->info_venta;
}
float DataCasa::getM2totales(){
    return this->m2Totales;
}

float DataCasa :: getM2edificados(){
	return this->m2edificados;
}

float DataCasa :: getEspacioVerde(){
	return this->espacioverde;
}

DataCasa::~DataCasa(){

}

ostream& operator <<(ostream& output, DataCasa& dc){

output << setprecision(30);
output << "Codigo:" << dc.getCodigo() << '\n'<< "Direccion de la casa:" << dc.getDireccion() << '\n' << "Cantidad de ambientes:" << dc.getCantAmbientes()<< '\n'<< "Dormitorios:" << dc.getDormitorios() << '\n'
<< "Banios:" << dc.getBanios() << '\n' << "Garaje: " ; if(drc.getGaraje()){o << "Si"; }else{ o<< "No";} o << endl;
if(dc.getAlquiler()>1)
    output<< "Precio Alquiler:" << dc.getAlquiler() << '\n';
 if(dc.getVenta()>1)
    output<< "Precio Venta:" << dc.getVenta() << '\n';
output<< "M2 totales:" << dc.getM2totales() << '\n'  << "M2 Edificados:" << dc.getM2edificados() << '\n'
<< "Espacio verde:" << dc.getEspacioVerde() << '\n';

    return output;

}
