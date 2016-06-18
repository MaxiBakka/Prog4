#include "../../UserInterface.h"
#include "IModificarPropiedadController.h"
#include "DataPropiedad.h"


#ifndef RUTINA_MODIFICAR_PROPIEDAD_H_
#define RUTINA_MODIFICAR_PROPIEDAD_H_

class RutinaModificarPropiedad: public PantallaUI {
private:
	IModificarPropiedadController* ctrl;
	DataPropiedad* propiedad;
	void seleccionarPropiedad();
	void modificarDatos();

public:
	RutinaModificarPropiedad();
	void ejecutar();
	virtual ~RutinaModificarPropiedad();
};

#endif /* RUTINA_MODIFICAR_PROPIEDAD */
