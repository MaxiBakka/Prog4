#include "UsuarioNotFound.h"

UsuarioNotFound::UsuarioNotFound(){

}

const char* UsuarioNotFound::what()const throw(){
		return "No se encontro el usuario";
	}
