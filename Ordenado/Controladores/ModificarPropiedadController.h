#ifndef ModificarPropiedadController_h_
#define ModificarPropiedadController_h_

#include "DataPropiedad.h"
#include "IModificarPropiedadController.h"

class Propiedad;

class ModificarPropiedadController: public IModificarPropiedadController {
private:
  Propiedad*propiedad;
public:
  ModificarPropiedadController();
  virtual ~ModificarPropiedadController();

  virtual DataPropiedad* ObtenerPropiedad(int &codigo);
  virtual void guardarPropiedad(DataPropiedad*p);

};








#endif
