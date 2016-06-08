
#ifndef MANEJADORPROPIEDADES_H
#define	MANEJADORPROPIEDADES_H

#include <map>
#include <set>
#include <string>

#include "Propiedad.h"
#include "DataPropiedad.h"
#include "DataInfoPropiedad.h" 
#include "Zona.h"


using namespace std;

class ManejadorPropiedades {
private:
    static ManejadorPropiedades* instancia;
    ManejadorPropiedades();
    set<Propiedad*>* propiedades;
public:
    static ManejadorPropiedades* getInstancia();
    //Destructor
    virtual~ManejadorPropiedades();
    //Operaciones DSD
    set<Propiedad*>* getPropiedades();
    void crearPropiedad(DataPropiedad* p,Zona z);
    void eliminarPropiedad(int c);
    set<DataInfoPropiedad*>* getConversacionesPropiedad(Zona z,string email);
    Propiedad* getPropiedad(int c);
};

#endif	/* MANEJADORPROPIEDADES_H */

