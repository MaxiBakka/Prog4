#include "ExDptoNoExistente.h"

ExDptoNoExistente::ExDptoNoExistente(){

}


const char* ExDptoNoExistente::what()const throw(){
		return "Departamento no existente";
	}
