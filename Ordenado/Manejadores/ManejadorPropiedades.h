
#ifndef MANEJADORPROPIEDADES_H
#define	MANEJADORPROPIEDADES_H

#include <map>
#include <set>
#include <string>

#include "Propiedad.h"
#include "../DataTypes/DataPropiedad.h"
#include "../DataTypes/DataInfoPropiedad.h"
#include "Zona.h"
#include "Oferta.h"
#include "Edificio.h"


using namespace std;

class ManejadorPropiedades {
private:
    static ManejadorPropiedades* instancia;
    ManejadorPropiedades();
    map<int,Propiedad*>* propiedades;
public:
    static ManejadorPropiedades* getInstancia();
    //Destructor
    virtual~ManejadorPropiedades();
    //Operaciones DSD
    Propiedad* crearPropiedad(DataPropiedad* p,Zona* z,Oferta*oferta,Edificio*edificio);
    void eliminarPropiedad(int c);
    bool ExistePropiedad(int codigo);
    set<DataInfoPropiedad*>* getConversacionesPropiedad(Zona* z,string& email);
    Propiedad* getPropiedad(int c);
};

#endif	/* MANEJADORPROPIEDADES_H */
