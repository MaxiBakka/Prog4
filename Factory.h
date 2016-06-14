#ifndef Factory.h
#define Factory.h

#include  "IPropiedadController.h"
#include  "IUsuarioController.h"
#include  "IEnviarMenajeController.h"


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

};

#endif
