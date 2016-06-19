#include "../Interfaces/UserInterface.h"
#include "../Interfaces/IUsuarioController.h"

class DataPropiedad;
class IUsuarioController;

#ifndef RUTINA_OBTENER_REPO_INMOS_H_
#define RUTINA_OBTENER_REPO_INMOS_H_

class RutinaObtenerReporteInmobiliarias: public UserInterface {
private:
	IUsuarioController* ctrl;
public:
	RutinaObtenerReporteInmobiliarias();
	void ejecutar();
	virtual ~RutinaObtenerReporteInmobiliarias();
};

#endif /* RUTINA_OBTENER_REPO_INMOS_H_*/
