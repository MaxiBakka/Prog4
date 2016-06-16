#ifndef RutinaAltaInteresado_h
#define  RutinaAltaInmobiliari_h

#include "IPropiedadController.h"

using namespace std;

class RutinaAltaInteresado: public UserInterface {
private:
	IPropiedadController* ctrl;
	void IngresarInteresado();
public:
	RutinaAltaInteresado();
	void ejecutar();
	virtual ~RutinaAltaInteresado();
};

#endif
