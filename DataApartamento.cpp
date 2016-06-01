#include "DataApartamento.h"

DataApartamento :: DataApartamento(int cAmbientes, int Dormitorios , int banios, string direc, bool garaje, DataAlquiler *&infoAlquiler, DataVenta *&infoVenta, float m2Tot,int codigo,DataEdificio*de)
:DataPropiedad(cAmbientes,Dormitorios,banos,direc,gar,&infoAlquiler,&infoVenta,codigo){
		this->edificio=de;	
		this->m2totales=m2Tot;
}

DataApartamento::DataApartamento(DataApartamento*da):DataPropiedad(da->getCantAmbientes,de->getDormitorios,de->getBanios,de->getDireccion,de->getAlquiler,de->getVenta,de->getcodigo){
	this->edificio=da->getEdificio;
	this->m2totales=da->getM2totales;
	
	
}

string DataApartamento :: getDireccion(){
	return this->direccion;
}

int DataApartamento :: getCantAmbientes(){
	return this->cantAmbientes;
}

int DataApartamento :: getDormitorios(){
	return this->dormitorios;
}

int DataApartamento :: getBanios(){
	return this->banios;
}
bool DataApartamento :: getGaraje(){
	return this->garaje;
}

DataAlquiler*& DataApartamento :: getAlquiler(){
	return this->info_alquiler;
}

DataVenta*& DataApartamento :: getVenta(){
	return this->info_venta;
}

float DataApartamento :: getM2totales(){
	return this->m2totales;
}
int DataApartamento:: getCodigo(){
	return this->codigo
}

DataEdificio*& DataApartameneto:: getEdficio(){
	return this->edificio;
}
DataApartamento::~DataApartamento(){

}

ostream& operator <<(ostream& output, DataApartamento& da){
	//hacer operacion
} 
