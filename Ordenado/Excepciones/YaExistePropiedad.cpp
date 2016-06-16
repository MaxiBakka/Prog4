#include "YaExistePropiedad.h"

YaExistePropiedad::YaExistePropiedad(){

}

YaExistePropiedad::~YaExistePropiedad(){

}

const char* YaExistePropiedad::what()const throw(){
		return "La propiedad ya existe";
}
