#include "YaExistePropiedad.h"

YaExistePropiedad::YaExistePropiedad(){

}

YaExistePropiedad::~YaExistePropiedad(){
	
}

	virtual const char* YaExistePropiedad::what()const throw(){
		return "La propiedad ya existe";
	}
