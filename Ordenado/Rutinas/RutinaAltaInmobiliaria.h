#ifndef RutinaAltaInmobiliaria_h
#define  RutinaAltaInmobiliaria_h

#include "IPropiedadController.h"

using namespace std;

class RutinaAltaInmobiliaria: public UserInterface {
private:
	IPropiedadController* ctrl;
	void IngresarInmobiliaria();
public:
	RutinaAltaInmobiliaria();
	void ejecutar();
	virtual ~RutinaAltaInmobiliaria();
};

#endif
