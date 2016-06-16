#include "NoExisteZona.h"

NoExisteZona::NoExisteZona(){

}

const char* NoExisteZona::what()const throw(){
		return "La zona no existe";
	}
