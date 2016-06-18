#include "../DataTypes/DataPropiedad.h"
#include "../DataTypes/DataApartamento.h"
#include "../DataTypes/DataCasa.h"


DataPropiedad::DataPropiedad(int cod, int cantAmbientes, int cantDormitorios, int cantBanios, string direccion, bool garaje,float m2Totales,float &infoAlquiler,float &infoVenta) :
cantAmbientes(cantAmbientes), dormitorios(cantDormitorios), banios(cantBanios), codigo(cod), direccion(direccion),
garaje(garaje),m2Totales(m2Totales), info_alquiler(infoAlquiler), info_venta(infoVenta) {

}



ostream & operator <<(ostream &o, DataPropiedad*& dp){
  DataApartamento* da = dynamic_cast<DataApartamento*>(dp);
        if(da!=NULL){
            o << *da;
        }else{
            DataCasa* dc = dynamic_cast<DataCasa*>(dp);
            o<< *dc;
        }
    return o;
}
