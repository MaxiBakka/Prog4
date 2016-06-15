#include "HoraInvalida.h"

HoraInvalida::HoraInvalida(){

}
HoraInvalida::~HoraInvalida(){
	
}

	virtual const char* HoraInvalida::what()const throw(){
		return "Hora invalida";
	}
