#include "DataApartamento.h"

DataApartamento :: DataApartamento(int cod,int cAmbientes, int dormitorios , int banios, string direc, bool garaje, float &infoAlquiler,float &infoVenta, float m2Tot,float m2edif)
:DataPropiedad(cod,cAmbientes,dormitorios,banios,direc,garaje,m2Tot,infoAlquiler,infoVenta){
		this->m2edificados=m2edif;
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

float & DataApartamento :: getAlquiler(){
	return this->info_alquiler;
}

float & DataApartamento :: getVenta(){
	return this->info_venta;
}

float DataApartamento :: getM2totales(){
	return this->m2Totales;
}
int DataApartamento:: getCodigo(){
	return this->codigo;
}
float DataApartamento::getM2edificados(){

	return m2edificados;
}


//desctructor
DataApartamento::~DataApartamento(){

}

ostream& operator <<(ostream& output, DataApartamento& da){

output << "Direccion del apartamento:" << da.getDireccion() << '\n' << "Cantidad de ambientes:" << da.getCantAmbientes()<< '\n'<< "Dormitorios:" << da.getDormitorios() << '\n'
<< "Banios:" << da.getBanios() << '\n' << "Garaje:" << da.getGaraje() << '\n' << "Alquiler:" << da.getAlquiler() << '\n' << "Venta:" << da.getVenta() << '\n'
<< "M2 totales:" << da.getM2totales() << '\n' << "Codigo:" << da.getCodigo() << '\n' << "M2 Edificados:" << da.getM2edificados() << '\n';

    return output;

}
