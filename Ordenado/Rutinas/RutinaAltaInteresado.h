#ifndef RutinaAltaInteresado_h
#define  RutinaAltaInmobiliari_h

#include "../Interfaces/IUsuarioController.h"
#include "../Interfaces/UserInterface.h"

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
