#include "UserInterface.h"
#include "IPropiedadController.h"

#ifndef RUTINA_ALTA_EDIFICIO_H_
#define RUTINA_ALTA_EDIFICIO_H_

class RutinaAltaEdificio: public UserInterface {
private:
  IPropiedadController* ctrl;
  void IngresarEdificio();
public:
	RutinaAltaEdificio();
	void ejecutar();
	virtual ~RutinaAltaEdificio();
};

#endif /* RUTINA_INCIO_CARGAR_DATOS_H_*/
