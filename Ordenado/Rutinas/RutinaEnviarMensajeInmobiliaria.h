#ifndef RutinaEnviarMensajeInmobiliaria_h
#define RutinaEnviarMensajeInmobiliaria_h

#include "UserInterface.h"

using namespace std;

class IEnviarMensajeController;

class RutinaEnviarMensajeInmobiliaria: public UserInterface {
private:
	IEnviarMensajeController* ctrl;
	void seleccionarChat();
  void ingresarMensaje();
public:
	RutinaEnviarMensajeInmobiliaria();
	void ejecutar();
	virtual ~RutinaEnviarMensajeInmobiliaria();
};

#endif //RutinaConsultarPropiedad
