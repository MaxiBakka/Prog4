#ifndef RUTINACERRARSESION_H
#define  RUTINACERRARSESION_H

#include "IUsuarioController.h"
#include "UserInterface.h"

class RutinaCerrarSesion: public UserInterface {
private:
	IUsuarioController* ctrl;
	
public:
	RutinaCerrarSesion();
	void ejecutar();
	virtual ~RutinaCerrarSesion();
};





#endif
