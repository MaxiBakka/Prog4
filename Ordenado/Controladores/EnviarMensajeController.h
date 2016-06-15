
#ifndef ENVIARMENSAJECONTROLLER_H
#define	ENVIARMENSAJECONTROLLER_H

#include <set>

#include "DataMensaje.h"
#include "DataChat.h"
#include "Chat.h"
#include "IEnviarMensajeController.h"


class EnviarMensajeController :public IEnviarMensajeController{
private:
    Chat* chat;
public:
    EnviarMensajeController();
    ~EnviarMensajeController();

    /**********************************/
    set<DataChat*>* listarChats();
    void seleccionarChat(DataChat*dc); //Se guarda el chat en el parametro "chat"
    set<DataMensaje*>* listarMensajes();
    void enviarMensaje(DataMensaje* mensaje);


};

#endif	/* ENVIARMENSAJECONTROLLER_H */
