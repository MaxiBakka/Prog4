#ifndef PROPIEDADCONTROLLER_H
#define	PROPIEDADCONTROLLER_H

#include "../ClasesDeDominio/Edificio.h"
#include "../ClasesDeDominio/Propiedad.h"
#include "../ClasesDeDominio/Zona.h"
#include "../ClasesDeDominio/Departamento.h"
#include "../Interfaces/IPropiedadController.h"

#include "../DataTypes/DataPropiedad.h"
#include "../DataTypes/DataAlquiler.h"
#include "../DataTypes/DataVenta.h"
#include "../DataTypes/DataDepartamento.h"
#include "../DataTypes/DataEdificio.h"
#include "../DataTypes/DataZona.h"
#include "../DataTypes/DataMensaje.h"
#include "../DataTypes/DataInfoPropiedad.h"
#include "../DataTypes/DataDetallePropiedad.h"
#include "../DataTypes/DataInfoInmobiliaria.h"


#include <string>
#include <set>

using namespace std;

class PropiedadController:public IPropiedadController {
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
   void elegirPropiedadzona(int codigo);

};
#endif	/* PROPIEDADCONTROLLER_H */
