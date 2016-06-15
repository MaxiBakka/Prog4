#ifndef IEnviarMensajeController_h
#define IEnviarMensajeController_h
//usuario inmobiliaria

#include "DataChat.h"
#include "DataMensaje.h"

#include <set>


using namespace std;

class IEnviarMensajeController
{
public:
	IEnviarMensajeController();
	~IEnviarMensajeController();

	virtual set<DataChat*>* listarChats() = 0;
	virtual void seleccionarChat(DataChat*dc) = 0;
	virtual set<DataMensaje*>* listarMensajes() = 0;
	virtual void enviarMensaje(DataMensaje* mensaje) = 0;
       

};




#endif										