#include "DataPropiedad.h"

DataPropiedad::DataPropiedad(int cod, int cantAmbientes, int cantDormitorios, int cantBanios, string direccion, bool garaje, DataAlquiler*& infoAlquiler, DataVenta*& infoVenta) : cantAmbientes(cantAmbientes), dormitorios(cantDormitorios), banios(cantBanios), codigo(cod), direccion(direccion), garaje(garaje), info_alquiler(infoAlquiler), info_venta(infoVenta) {
}


ostream & operator <<(ostream &output, DataPropiedad* dp){
	
	
	
}


