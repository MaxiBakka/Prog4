#ifndef PROPIEDADCONTROLLER_H
#define	PROPIEDADCONTROLLER_H

#include "DataPropiedad.h"
#include "DataAlquiler.h"
#include "DataVenta.h"
#include "DataAlquiler.h"
#include "DataDepartamento.h"
#include "DataEdificio.h"
#include "DataZona.h"
#include "DataMensaje.h"
#include "DataInfoPropiedad.h"
#include "ManejadorDepartamentos.h"
#include "ManejadorEdificios.h"
#include "Manejador_Usuario.h"
#include "Manejador_Propiedad"

#include <string>
#include <set>

using namespace std;
class PropiedadController {
private:
    Zona* zona;
    DataPropiedad* propiedad;
    DataAlquiler* da;
    DataVenta* dv;
public:
        PropiedadController();
	void confirmarAltaPropiedad();
	void ingresarNuevaCasa(DataPropiedad* casa);
	void ingresarPrecioAlquiler(DataAlquiler* pAlquiler);
	void ingresarNuevoApartamento(DataPropiedad* apartamento);
	void ingresarPrecioVenta(DataVenta* pVenta);
	set<DataDepartamento*>* listarDepartamentos();
	set<DataEdificio*>* listarEdificios();
	set<DataZona*>* listarZonas();
	void enviarMensaje(DataMensaje* mensaje);
	bool tipoPropiedad(int codigo);
	void eliminarPropiedad(int codigo);
	set<DataMensaje*>* listarMensajes();
	set<DataInfoPropiedad*>* obtnerConversaciones();
	void seleccionarPropiedad(int codigo); 
	void seleccionarDepartamento(string letra);
	void seleccionarZona(int codigo);
	void seleccionarEdificio(string nombre);
};
#endif	/* PROPIEDADCONTROLLER_H */