#ifndef RutinaAltaInteresado_h
#define  RutinaAltaInmobiliari_h

#include "IUsuarioController.h"
#include "UserInterface.h"

using namespace std;

class RutinaInicioSesion: public UserInterface {
private:
	IUsuarioController* ctrl;
	void ingPrimeraVez();
	void ingresoEmail();
	void ingresoPwd();
public:
	RutinaInicioSesion();
	void ejecutar();
	virtual ~RutinaInicioSesion();
};

#endif
