#include "EdificioNoExistente.h"

EdificioNoExistente::EdificioNoExistente(){

}



const char* EdificioNoExistente::what()const throw(){
		return "El edificio no existe";
	}
