#include "UsuarioNotFound.h"

	virtual const char* UsuarioNotFound::what()const throw(){
		return "No se encontro el usuario";
	}
