#include "NoExisteZona.h"

NoExisteZona::NoExisteZona(){

}

NoExisteZona::~NoExisteZona(){
	
}

	virtual const char* NoExisteZona::what()const throw(){
		return "La zona no existe";
	}
