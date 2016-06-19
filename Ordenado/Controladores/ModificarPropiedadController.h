#ifndef ModificarPropiedadController_h_
#define ModificarPropiedadController_h_

#include "../DataTypes/DataPropiedad.h"
#include "../Interfaces/IModificarPropiedadController.h"

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
