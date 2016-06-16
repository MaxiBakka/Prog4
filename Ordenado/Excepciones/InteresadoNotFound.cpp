#include "InteresadoNotFound.h"

InteresadoNotFound::InteresadoNotFound(){

}

const char* InteresadoNotFound::what()const throw(){
		return "No se encontro el interesado";
	}
