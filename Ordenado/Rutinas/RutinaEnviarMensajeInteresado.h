#ifndef RutinaEnviarMensajeInteresado_h
#define RutinaEnviarMensajeInteresado_h

#include "../Interfaces/UserInterface.h"

using namespace std;

class IPropiedadController;

class RutinaEnviarMensajeInteresado: public UserInterface {
private:
	IPropiedadController* ctrl;
  void seleccionarChat();
  void enviarMensaje();
  void seleccionarDepartamento();
  void seleccionarZona();
public:
	RutinaEnviarMensajeInteresado();
	void ejecutar();
	virtual ~RutinaEnviarMensajeInteresado();
};

#endif //RutinaConsultarPropiedad
