#ifndef Factory_h
#define Factory_h

#include  "IPropiedadController.h"
#include  "IUsuarioController.h"
#include  "IEnviarMenajeController.h"
#include "ICargarDatosController.h"
#include "IModificarPropiedadController.h"


class Factory {
	private:
		static Factory* instancia;
		Factory();

	public:
		~Factory();
		static Factory*getInstance();
		static IPropiedadController *getIPropiedadController();
		static IUsuarioController *getIUsuarioController();
		static IEnviarMenajeController *getIEnviarMenajeController();
		static IModificarPropiedadController *getIModificarPropiedadController();
		static ICargarDatosController *getICargarDatosController();

};

#endif
