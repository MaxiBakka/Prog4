#ifndef IPropiedadController_h
#define IPropiedadController_h

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

class IPropiedadController{

public:
	IPropiedadController();
	virtual ~IPropiedadController();

	virtual void confirmarAltaPropiedad() = 0;
	virtual void ingresarNuevaCasa(DataPropiedad* casa) = 0;
	virtual void ingresarPrecioAlquiler(DataAlquiler* pAlquiler) = 0;
	virtual void ingresarNuevoApartamento(DataPropiedad* apartamento) = 0;
	virtual void ingresarPrecioVenta(DataVenta* pVenta) = 0;
	virtual set<DataDepartamento*>* listarDepartamentos() = 0;
	virtual set<DataEdificio*>* listarEdificios() = 0;
	virtual set<DataZona*>* listarZonas() = 0;
	virtual void seleccionarDepartamento(string& letra) = 0;
	virtual void seleccionarZona(int codigo) = 0;
	virtual void seleccionarEdificio(const string& nombre) = 0;
	//virtual bool tipoPropiedad(int codigo) = 0; esta operacion se hace directamente en el menu
	//caso de uso eliminarPropiedad
	virtual void eliminarPropiedad(int codigo) = 0;
	//caso de uso enviarMensaje interesado
	virtual void enviarMensaje(DataMensaje* mensaje) = 0;
	virtual set<DataMensaje*>* listarMensajes() = 0;
	virtual set<DataInfoPropiedad*>* obtnerConversaciones() = 0;
	virtual void seleccionarPropiedad(int codigo) = 0;

	//Alta Edificio
	virtual void IngresarEdificio(DataEdificio*de) = 0;

	//caso de uso consultarPropiedad

  virtual set<DataDetallePropiedad*>* obtenerDetallePropiedad() = 0;
  virtual DataInfoInmobiliaria* informacionDetallada() = 0;
	virtual void elegirPropiedadzona(int codigo) = 0;
};
#endif //IPropiedadController_h
