

#ifndef ICARGARDATOSCONTROLLER_H_
#define ICARGARDATOSCONTROLLER_H_

class ICargarDatosController {
public:
	ICargarDatosController();
	virtual ~ICargarDatosController();
	virtual void cargarDatosdeSistema()=0;
};

#endif
