#include "PrecioInvalido.h"

	virtual const char* PrecioInvalido::what()const throw(){
		return "El precio es invalido";
	}

