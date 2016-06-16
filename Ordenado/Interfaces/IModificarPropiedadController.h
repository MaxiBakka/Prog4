#ifndef IModificarPropiedadController_h
#define IModificarPropiedadController_h

#include "DataPropiedad.h"

using namespace std;

class IModificarPropiedadController {

public:
  IModificarPropiedadController ();
  virtual ~IModificarPropiedadController ();

  virtual DataPropiedad* ObtenerPropiedad(int &codigo) = 0;
  virtual void guardarPropiedad(DataPropiedad*p) = 0;

};

#endif
