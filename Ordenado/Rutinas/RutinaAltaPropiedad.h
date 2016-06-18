#ifndef RutinaAltaPropiedad_h
#define  RutinaAltaPropiedad_h

#include "UserInterface.h"

using namespace std;

class IPropiedadController;

class RutinaAltaPropiedad: public UserInterface {
private:
	IPropiedadController* ctrl;
	void seleccionarDepartamento();
	void seleccionarZona();
	void ingresarNuevaCasa();
	void ingresarNuevoApartamento();
	void ingresarAlquilerVenta();
public:
    RutinaAltaPropiedad();
	void ejecutar();
	virtual ~RutinaAltaPropiedad();
};

#endif
