#include "EdificioNoExistente.h"

	virtual const char* EdificioNoExistente::what()const throw(){
		return "El edificio no existe";
	}

