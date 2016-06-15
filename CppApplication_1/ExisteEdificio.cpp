#include "ExisteEdificio.h"

ExisteEdificio::ExisteEdificio(){

}

ExisteEdificio::~ExisteEdificio(){
	
}

	virtual const char* ExisteEdificio::what()const throw(){
		return "El edificio ya existe";
	}
