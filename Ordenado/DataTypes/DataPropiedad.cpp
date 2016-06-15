#include "DataPropiedad.h"

DataPropiedad::DataPropiedad(int cod, int cantAmbientes, int cantDormitorios, int cantBanios, string direccion, bool garaje,float m2Totales,float &infoAlquiler,float &infoVenta) :
cantAmbientes(cantAmbientes), dormitorios(cantDormitorios), banios(cantBanios), codigo(cod), direccion(direccion),
garaje(garaje),m2Totales(m2Totales), info_alquiler(infoAlquiler), info_venta(infoVenta) {

}



ostream & operator <<(ostream &output, DataPropiedad* dp){

	return output;

}
