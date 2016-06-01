#ifndef Factory.h
#define Factory.h

#include "IPropiedadController.h"
#include "IUsuarioController.h"

class Factory {
	private:
		static Factory* instancia;
		Factory();

	public:
		~Factory();
		static Factory*getInstance();
		static IPropiedadController *getIPropiedadController();
		static IUsuarioController *getIUsuarioController();

};

#endif
