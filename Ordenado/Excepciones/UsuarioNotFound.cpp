#include "UsuarioNotFound.h"

UsuarioNotFound::UsuarioNotFound(){

}

UsuarioNotFound::~UsuarioNotFound(){

}
const char* UsuarioNotFound::what()const throw(){
		return "El usuario no se encuentra en el sistema";
	}
