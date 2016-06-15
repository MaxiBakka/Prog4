#include "ExDptoNoExistente.h"

ExDptoNoExistente::ExDptoNoExistente(){

}

ExDptoNoExistente::~ExDptoNoExistente(){
	
}

	virtual const char* ExDptoNoExistente::what()const throw(){
		return "Departamento no existente";
	}
