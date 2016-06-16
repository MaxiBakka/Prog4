#ifndef RutinaAltaInteresado_h
#define  RutinaAltaInmobiliari_h

#include "IUsuarioController.h"
#include "UserInterface.h"

using namespace std;

class RutinaAltaInteresado: public UserInterface {
private:
	IUsuarioController* ctrl;
	void IngresarInteresado();
public:
	RutinaAltaInteresado();
	void ejecutar();
	virtual ~RutinaAltaInteresado();
};

#endif
