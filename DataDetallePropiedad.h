
#ifndef DATADETALLEPROPIEDAD_H
#define	DATADETALLEPROPIEDAD_H

#include<string>
#include <iostream>

using namespace std;

class DataDetallePropiedad {
private:
    int codigo;
    string direccion;
    bool venta,alquiler;
public:
    DataDetallePropiedad(int codigo,string& direccion,bool venta,bool alquiler);
    int getCodigo();
    string& getDireccion();
    bool getVenta();
    bool getAlquiler();
    ~DataDetallePropiedad();

};

ostream& operator<<(ostream& o, const DataDetallePropiedad& ddp);


#endif	/* DATADETALLEPROPIEDAD_H */
