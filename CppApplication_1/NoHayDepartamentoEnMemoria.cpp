#include "NoHayDepartamentoEnMemoria.h"

NoHayDepartamentoEnMemoria::NoHayDepartamentoEnMemoria(){

}

NoHayDepartamentoEnMemoria::~NoHayDepartamentoEnMemoria(){
	
}

	virtual const char* NoHayDepartamentoEnMemoria::what()const throw(){
		return "No hay departamento en memoria";
	}
