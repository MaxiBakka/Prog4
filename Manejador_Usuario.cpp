#include "Manejador_Usuario.h"

Manejador_Usuario* Manejador_Usuario::instancia = NULL;

Manejador_Usuario :: Manejador_Usuario(){};
Manejador_Usuario :: ~Manejador_Usuario(){};

public Manejador_Usuario::getInstance(){
	if (instancia==NULL) instancia = new Manejador_Usuario();
	return instancia;
}
