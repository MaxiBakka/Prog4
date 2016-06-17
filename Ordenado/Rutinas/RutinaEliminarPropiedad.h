#ifndef RutinaEliminarPropiedad_h
#define  RutinaEliminarPropiedad_h

#include "UserInterface.h"

using namespace std;

class IPropiedadController;

class RutinaConsultarPropiedad: public UserInterface {
private:
	IPropiedadController* ctrl;
	void eliminarDepartamento();
public:
	RutinaEliminarPropiedad();
	void ejecutar();
	virtual ~RutinaEliminarPropiedad();
};

#endif //RutinaEliminarPropiedad
