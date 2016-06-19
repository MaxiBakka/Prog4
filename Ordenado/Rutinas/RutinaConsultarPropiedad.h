#ifndef RutinaConsultarPropiedad_h
#define  RutinaConsultarPropiedad_h

#include "../Interfaces/UserInterface.h"

using namespace std;

class IPropiedadController;

class RutinaConsultarPropiedad: public UserInterface {
private:
	IPropiedadController* ctrl;
	void seleccionarDepartamento();
  void seleccionarZona();
public:
	RutinaConsultarPropiedad();
	void ejecutar();
	virtual ~RutinaConsultarPropiedad();
};

#endif
