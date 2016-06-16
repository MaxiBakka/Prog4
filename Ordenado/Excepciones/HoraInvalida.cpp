#include "HoraInvalida.h"

HoraInvalida::HoraInvalida(){

}

const char* HoraInvalida::what()const throw(){
		return "Hora invalida";
	}
