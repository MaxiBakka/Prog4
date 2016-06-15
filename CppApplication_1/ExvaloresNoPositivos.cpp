#include "ExvaloresNoPositivos.h"

ExvaloresNoPositivos::ExvaloresNoPositivos(){

}

ExvaloresNoPositivos::~ExvaloresNoPositivos(){

}

	virtual const char* ExvaloresNoPositivos::what()const throw(){
		return "Valores no positivos";
	}
