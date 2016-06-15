#ifndef PROPIEDADCONTROLLER_H
#define	PROPIEDADCONTROLLER_H

#include "Edificio.h"
#include "Propiedad.h"
#include "Zona.h"
#include "Departamento.h"
#include "IPropiedadController"

#include "DataPropiedad.h"
#include "DataAlquiler.h"
#include "DataVenta.h"
#include "DataDepartamento.h"
#include "DataEdificio.h"
#include "DataZona.h"
#include "DataMensaje.h"
#include "DataInfoPropiedad.h"
#include "DataDetallePropiedad.h"
#include "DataInfoInmobiliaria.h"


#include <string>
#include <set>

using namespace std;

class PropiedadController: public IPropiedadController {
private:
    Departamento* dpto;
    Zona* zona;
    DataPropiedad* dp;
    DataAlquiler* da;
    DataVenta* dv;
    Propiedad*propiedad;
    Edificio*edificio;
public:
        PropiedadController();
        virtual ~PropiedadController();
  //Alta Propiedad
	void confirmarAltaPropiedad();
	void ingresarNuevaCasa(DataPropiedad* casa);
	void ingresarPrecioAlquiler(DataAlquiler* pAlquiler);
	void ingresarNuevoApartamento(DataPropiedad* apartamento);
	void ingresarPrecioVenta(DataVenta* pVenta);
	set<DataDepartamento*>* listarDepartamentos();
	set<DataEdificio*>* listarEdificios();
	set<DataZona*>* listarZonas();
  void seleccionarDepartamento(string& letra);
	void seleccionarZona(int codigo);
	void seleccionarEdificio(const string& nombre);

	//bool tipoPropiedad(int codigo);

	void eliminarPropiedad(int codigo);
  //caso de uso enviarMensaje interesado
  void enviarMensaje(DataMensaje* mensaje);
	set<DataMensaje*>* listarMensajes();
	set<DataInfoPropiedad*>* obtnerConversaciones();
	void seleccionarPropiedad(int codigo);

  //Alta Edificio
	 void IngresarEdificio(DataEdificio*de);

  //caso de uso consultarPropiedad
   set<DataDetallePropiedad*>* obtenerDetallePropiedad();
   DataInfoInmobiliaria* informacionDetallada();

};
#endif	/* PROPIEDADCONTROLLER_H */
