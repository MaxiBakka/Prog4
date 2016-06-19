
#ifndef MANEJADORPROPIEDADES_H
#define	MANEJADORPROPIEDADES_H

#include <map>
#include <set>
#include <string>

#include "../ClasesDeDominio/Propiedad.h"
#include "../ClasesDeDominio/Zona.h"
#include "../ClasesDeDominio/Oferta.h"
#include "../ClasesDeDominio/Edificio.h"


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
