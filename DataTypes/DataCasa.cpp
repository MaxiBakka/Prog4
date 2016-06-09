#include "DataCasa.h"

DataCasa :: DataCasa(int cod,int cAmbientes, int Dormitorios , int banos, string direc, bool gar, DataAlquiler *&infoAlquiler, DataVenta *&infoVenta, float m2Ed, float eVerde):
    DataPropiedad(cod,cAmbientes,Dormitorios,banos,direc,gar,infoAlquiler,infoVenta){

		this->m2edificados=m2Ed;
		this->espacioverde=eVerde;
}

string DataCasa :: getDireccion(){
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

DataAlquiler*& DataCasa :: getAlquiler(){
	return this->info_alquiler;
}

DataVenta*& DataCasa :: getVenta(){
	return this->info_venta;
}

float DataCasa :: getM2edificados(){
	return this->m2edificados;
}

float DataCasa :: getEspacioVerde(){
	return this->espacioverde;
}

DataCasa::~DataCasa(){

}
