
#ifndef ENVIARMENSAJECONTROLLER_H
#define	ENVIARMENSAJECONTROLLER_H

#include <set>

#include "DataMensaje.h"
#include "DataChat.h"
#include "Chat.h"


class EnviarMensajeController {
private:
    Chat* chat;
public:
    EnviarMensajeController();\
    ~EnviarMensajeController();
    
    /**********************************/
    set<DataChat*>* listarChats();
    void seleccionarChat(DataChat*dc); //Se guarda el chat en el parametro "chat"
    set<DataMensaje*>* listarMensajes();
    void enviarMensaje(DataMensaje* mensaje);
    

};

#endif	/* ENVIARMENSAJECONTROLLER_H */

