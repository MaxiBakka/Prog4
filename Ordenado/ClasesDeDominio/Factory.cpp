#include "Factory.h"
#include "UsuarioController.h"
#include "PropiedadController.h"
#include "EnviarMensajeController.h"
#include "ModificarPropiedadController.h"
#include "CargarDatosController.h"

	Factory* Factory::instancia = NULL;

	Factory::Factory(){};

	Factory::~Factory(){};

	Factory* Factory::getInstance(){
		if (instancia==NULL)
			instancia = new Factory();
		return instancia;
	}

	IPropiedadController *Factory::getIPropiedadController(){
		return new PropiedadController();
	}

	IUsuarioController *Factory::getIUsuarioController(){
		return new UsuarioController();
	}

	IEnviarMensajeController *Factory::getIEnviarMenajeController(){
		return new EnviarMensajeController();
	}

	 IModificarPropiedadController *Factory::getIModificarPropiedadController(){

		 return new ModificarPropiedadController();
	 }
	 ICargarDatosController *Factory::getICargarDatosController(){
		 	return new CargarDatosController();

	 }
