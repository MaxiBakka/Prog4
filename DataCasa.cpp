#include "DataCasa.h"
#include "DataPropiedad.h"

DataCasa :: DataCasa(int cAmbientes, int Dormitorios , int banos, string direc, bool gar, DataInfoAlquiler *&infoAlquiler, DataInfoVenta *&infoVenta, float m2Ed, float eVerde):
    DataPropiedad(cAmbientes,Dormitorios,banos,direc,gar,*&infoAlquiler,*&infoVenta){

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

DataInfoAlquiler*& DataCasa :: getAlquiler(){
	return this->info_alquiler;
}

DataInfoVenta*& DataCasa :: getVenta(){
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
