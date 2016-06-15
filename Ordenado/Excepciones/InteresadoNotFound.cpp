#include "InteresadoNotFound.h"

InteresadoNotFound::InteresadoNotFound(){

}

InteresadoNotFound::~InteresadoNotFound(){
	
}

	virtual const char* InmobiliariaNotFound::what()const throw(){
		return "No se encontro el interesado";
	}
