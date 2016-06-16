#ifndef RutinaAltaInmobiliaria_h
#define  RutinaAltaInmobiliaria_h

#include "UserInterface.h"

using namespace std;

class IUsuarioController;

class RutinaAltaInmobiliaria: public UserInterface {
private:
	IUsuarioController* ctrl;
	void AltaInmobiliaria();
public:
	RutinaAltaInmobiliaria();
	void ejecutar();
	virtual ~RutinaAltaInmobiliaria();
};

#endif
