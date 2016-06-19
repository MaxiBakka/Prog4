#ifndef Factory_h
#define Factory_h

#include "../Interfaces/IPropiedadController.h"
#include "../Interfaces/IUsuarioController.h"
#include "../Interfaces/IEnviarMensajeController.h"
#include "../Interfaces/ICargarDatosController.h"
#include "../Interfaces/IModificarPropiedadController.h"


class Factory {
	private:
		static Factory* instancia;
		Factory();

	public:
		~Factory();
		static Factory*getInstance();
		static IPropiedadController *getIPropiedadController();
		static IUsuarioController *getIUsuarioController();
		static IEnviarMensajeController *getIEnviarMenajeController();
		static IModificarPropiedadController *getIModificarPropiedadController();
		static ICargarDatosController *getICargarDatosController();

};

#endif
