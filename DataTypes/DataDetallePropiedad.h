
#ifndef DATADETALLEPROPIEDAD_H
#define	DATADETALLEPROPIEDAD_H

#include <string>

using namespace std;

class DataDetallePropiedad {
private:
    int codigo;
    string direccion;
    float venta,alquiler;
public:
    DataDetallePropiedad(int codigo,string& direccion,float venta,float alquiler);
    int getCodigo();
    string& getDireccion();
    float getVenta();
    float getAlquiler();
    ~DataDetallePropiedad();

};

ostream& operator<<(ostream& o, const DataDetallePropiedad& ddp);


#endif	/* DATADETALLEPROPIEDAD_H */

