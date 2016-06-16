#include "ExisteInteresado.h"

ExisteInteresado::ExisteInteresado(){

}

const char* ExisteInteresado::what()const throw(){
		return "Interesado ya existente";
	}
