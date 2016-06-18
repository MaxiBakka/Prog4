#ifndef RutinaEliminarPropiedad_h
#define  RutinaEliminarPropiedad_h

#include "UserInterface.h"

using namespace std;

class IPropiedadController;

class RutinaEliminarPropiedad: public UserInterface {
private:
	IPropiedadController* ctrl;
	void eliminarPropiedad();
public:
	RutinaEliminarPropiedad();
	void ejecutar();
	virtual ~RutinaEliminarPropiedad();
};

#endif //RutinaEliminarPropiedad
