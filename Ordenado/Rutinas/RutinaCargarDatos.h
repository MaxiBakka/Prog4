#ifndef RUTINA_INCIO_CARGAR_DATOS_H_
#define RUTINA_INCIO_CARGAR_DATOS_H_

#include "../Interfaces/UserInterface.h"

class ICargarDatosController;
using namespace std;

class RutinaCargarDatos: public UserInterface {
public:
	RutinaCargarDatos();
	void ejecutar();
	virtual ~RutinaCargarDatos();
};

#endif /* RUTINA_INCIO_CARGAR_DATOS_H_*/
