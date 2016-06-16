#include "DataCasa.h"

DataCasa :: DataCasa(int cod,int cAmbientes, int Dormitorios , int banios, string& direc, bool gar,float &infoAlquiler, float &infoVenta,float m2Tot,float m2edif,float everde):
    DataPropiedad(cod,cAmbientes,Dormitorios,banios,direc,gar,m2Tot,infoAlquiler,infoVenta){

		this->m2edificados=m2edif;
		this->espacioverde=eVerde;
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
return this->m2Totales

}
float DataCasa :: getM2edificados(){
	return this->m2edificados;
}

float DataCasa :: getEspacioVerde(){
	return this->espacioverde;
}

DataCasa::~DataCasa(){

}

ostream& operator <<(ostream& output, DataCasa& da){

output << "Direccion de la casa:" << da.getDireccion() << '\n' << "Cantidad de ambientes:" << da.getCantAmbientes()<< '\n'<< "Dormitorios:" << da.getDormitorios() << '\n'
<< "Banios:" << da.getBanios() << '\n' << "Garaje:" << da.getGaraje() << '\n' << "Alquiler:" << da.getAlquiler() << '\n' << "Venta:" << da.getVenta() << '\n'
<< "M2 totales:" << da.getM2totales() << '\n' << "Codigo:" << da.getCodigo() << '\n' << "M2 Edificados:" << da.getM2edificados() << '\n'
<< "Espacio verde:" << da.getEspacioVerde() << '\n';

    return output;

}
