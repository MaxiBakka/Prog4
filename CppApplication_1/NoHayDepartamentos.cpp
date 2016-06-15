#include "NoHayDepartamentos.h"

NoHayDepartamentos::NoHayDepartamentos(){

}

NoHayDepartamentos::~NoHayDepartamentos(){
	
}

	virtual const char* NoHayDepartamentos::what()const throw(){
		return "No hay departamentos.";
	}
