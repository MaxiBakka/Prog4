#include "DataApartamento.h"

DataApartamento :: DataApartamento(int cAmbientes, int Dormitorios , int banos, string direc, bool gar, DataInfoAlquiler *&infoAlquiler, DataInfoVenta *&infoVenta, float m2Tot)
:DataPropiedad(cAmbientes,Dormitorios,banos,direc,gar,*&infoAlquiler,*&infoVenta){

		this->m2totales=m2Tot;
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

DataInfoAlquiler*& DataApartamento :: getAlquiler(){
	return this->info_alquiler;
}

DataInfoVenta*& DataApartamento :: getVenta(){
	return this->info_venta;
}

float DataApartamento :: getM2totales(){
	return this->m2totales;
}

DataApartamento::~DataApartamento(){

}
