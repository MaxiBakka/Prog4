#include "EdificioNoExistente.h"

EdificioNoExistente::EdificioNoExistente(){

}

EdificioNoExistente::~EdificioNoExistente(){
	
}

	virtual const char* EdificioNoExistente::what()const throw(){
		return "El edificio no existe";
	}
