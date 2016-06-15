#include "ExOpcionInvalida.h"

	virtual const char* ExOpcionInvalida::what()const throw(){
		return "Opcion Invalida, intente nuevamente";
	}
