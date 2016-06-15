#include "DataApartamento.h"

DataApartamento :: DataApartamento(int cod,int cAmbientes, int dormitorios , int banios, string direc, bool garaje, DataAlquiler *& infoAlquiler, DataVenta *&infoVenta, float m2Tot,int codigo,DataEdificio*&de)
:DataPropiedad(cod,cAmbientes,dormitorios,banios,direc,garaje,infoAlquiler,infoVenta){
		this->edificio=de;
		this->m2totales=m2Tot;
}

DataApartamento::DataApartamento(DataApartamento*da):DataPropiedad(da->getCantAmbientes,da->getDormitorios,da->getBanios,da->getDireccion,da->getGaraje,da->getAlquiler,da->getVenta,da->getCodigo){
	this->edificio=da->getEdificio;
	this->m2totales=da->getM2totales;


}

string& DataApartamento :: getDireccion(){
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

DataAlquiler* DataApartamento :: getAlquiler(){
	return this->info_alquiler;
}

DataVenta* DataApartamento :: getVenta(){
	return this->info_venta;
}

float DataApartamento :: getM2totales(){
	return this->m2totales;
}
int DataApartamento:: getCodigo(){
	return this->codigo;
}

DataEdificio* DataApartamento:: getEdificio(){
	return this->edificio;
}
//desctructor
DataApartamento::~DataApartamento(){

}

ostream& operator <<(ostream& output, DataApartamento& da){
	//hacer operacion
}
