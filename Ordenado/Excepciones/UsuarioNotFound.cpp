#include "UsuarioNotFound.h"

UsuarioNotFound::UsuarioNotFound(){

}

UsuarioNotFound::~UsuarioNotFound(){
	
}

	virtual const char* UsuarioNotFound::what()const throw(){
		return "No se encontro el usuario";
	}
