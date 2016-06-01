#ifndef Factory.h
#define Factory.h

class "IPropiedadController.h"
class "IUsuarioController.h"


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
