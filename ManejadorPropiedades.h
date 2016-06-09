
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
    map<int,Propiedad*>* propiedades;
public:
    static ManejadorPropiedades* getInstancia();
    //Destructor
    virtual~ManejadorPropiedades();
    //Operaciones DSD
    void crearPropiedad(DataPropiedad* p,Zona z);
    void eliminarPropiedad(int c);
    bool ExistePropiedad(int codigo);
    set<DataInfoPropiedad*>* getConversacionesPropiedad(Zona* z,string& email);
    Propiedad* getPropiedad(int c);
};

#endif	/* MANEJADORPROPIEDADES_H */

