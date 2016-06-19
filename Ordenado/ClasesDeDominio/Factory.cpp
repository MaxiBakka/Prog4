#include "Factory.h"
#include "../Controladores/UsuarioController.h"
#include "../Controladores/PropiedadController.h"
#include "../Controladores/EnviarMensajeController.h"
#include "../Controladores/ModificarPropiedadController.h"
#include "../Controladores/CargarDatosController.h"

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
