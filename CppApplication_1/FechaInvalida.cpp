#include "FechaInvalida.h"

FechaInvalida::FechaInvalida(){

}

FechaInvalida::~FechaInvalida(){
	
}

	virtual const char* FechaInvalida::what()const throw(){
		return "Fecha Invalida";
	}
