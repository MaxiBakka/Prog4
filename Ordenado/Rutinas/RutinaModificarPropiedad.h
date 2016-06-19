#include "../Interfaces/UserInterface.h"
#include "../Interfaces/IModificarPropiedadController.h"
#include "../DataTypes/DataPropiedad.h"


#ifndef RUTINA_MODIFICAR_PROPIEDAD_H_
#define RUTINA_MODIFICAR_PROPIEDAD_H_

class RutinaModificarPropiedad: public UserInterface {
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
