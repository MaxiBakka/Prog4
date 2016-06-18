#ifndef RutinaEnviarMensajeInteresado_h
#define RutinaEnviarMensajeInteresado_h

#include "UserInterface.h"

using namespace std;

class IPropiedadController;

class RutinaEnviarMensajeInteresado: public UserInterface {
private:
	IPropiedadController* ctrl;
  void seleccionarChat();
  void ingresarMensaje();
  void seleccionarDepartamento();
  void seleccionarZona();
public:
	RutinaEnviarMensajeInteresado();
	void ejecutar();
	virtual ~RutinaEnviarMensajeInteresado();
};

#endif //RutinaConsultarPropiedad
