#ifndef RutinaEnviarMensajeInmobiliaria_h
#define RutinaEnviarMensajeInmobiliaria_h

#include "UserInterface.h"

using namespace std;

class IPropiedadController;

class RutinaEnviarMensajeInmobiliaria: public UserInterface {
private:
	IPropiedadController* ctrl;
	void seleccionarChat();
  void ingresarChat();
public:
	RutinaEnviarMensajeInmobiliaria();
	void ejecutar();
	virtual ~RutinaEnviarMensajeInmobiliaria();
};

#endif //RutinaConsultarPropiedad
