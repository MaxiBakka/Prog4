#ifndef CARGARDATOSCONTROLLER_H_
#define CARGARDATOSCONTROLLER_H_

#include <map>
#include <string>

#include "../ClasesDeDominio/Departamento.h"
#include "../ClasesDeDominio/Zona.h"
#include "../ClasesDeDominio/Propiedad.h"
#include "../ClasesDeDominio/Administrador.h"
#include "../ClasesDeDominio/Inmobiliaria.h"
#include "../ClasesDeDominio/Edificio.h"
#include "../ClasesDeDominio/Interesado.h"
#include "../ClasesDeDominio/Mensaje.h"
#include "../ClasesDeDominio/Apartamento.h"
#include "../ClasesDeDominio/Casa.h"
#include "../Interfaces/ICargaDatosController.h"

using namespace std;

class CargarDatosController: public ICargaDatosController {
private:
	static bool DatosCargados;
	
	virtual void cargarDepartamentos();
	virtual void cargarZonas();
	virtual void cargarApartamentos();
	virtual void cargarCasas();
	virtual void cargarInmobiliarias();
	virtual void cargarInteresados();
	virtual void cargarEdificios();
	virtual void cargarMensajes();
	virtual void cargarAdministrador();

	//Atributos que guarden las referencias como en el pdf.
	map<string,Departamento*>* refEmpresas;
	map<string,Zona*>* refSucursales;
	map<string,Edificio*>* refSecciones;
	map<string,Inmobiliaria*>* refEstudiantes;
	map<string,Interesado*>* refAsignaturas;
	map<string,Casa*>* refCarreras;
	map<string,Chat*>* refOfertas;
	map<string,Apartamento*>* refEncargados;


public:
	CargarDatosController();
	virtual ~CargarDatosController();
	virtual void cargarDatosdeSistema();
};
