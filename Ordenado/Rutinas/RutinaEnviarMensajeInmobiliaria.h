#ifndef RutinaEnviarMensajeInmobiliaria_h
#define RutinaEnviarMensajeInmobiliaria_h

#include "../Interfaces/UserInterface.h"

using namespace std;

class IEnviarMensajeController;

class RutinaEnviarMensajeInmobiliaria: public UserInterface {
private:
	IEnviarMensajeController* ctrl;
    void seleccionarChat();
    void enviarMensaje();
public:
	RutinaEnviarMensajeInmobiliaria();
	void ejecutar();
	virtual ~RutinaEnviarMensajeInmobiliaria();
};

#endif //RutinaEnviarMensajeInteresado
