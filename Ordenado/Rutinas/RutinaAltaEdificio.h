#include "../Interfaces/UserInterface.h"
#include "../Interfaces/IPropiedadController.h"

#ifndef RUTINA_ALTA_EDIFICIO_H_
#define RUTINA_ALTA_EDIFICIO_H_

class RutinaAltaEdificio: public UserInterface {
private:
  IPropiedadController* ctrl;
  void IngresarEdificio();
  string nombreEdificio;
public:
	RutinaAltaEdificio();
	void ejecutar();
	virtual ~RutinaAltaEdificio();
	string getNombreEdificio();
};

#endif /* RUTINA_INCIO_CARGAR_DATOS_H_*/
