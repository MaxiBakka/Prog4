#include "DatosYaCargados.h"

DatosYaCargados::DatosYaCargados(){

}

DatosYaCargados::~DatosYaCargados(){

}

	virtual const char* DatosYaCargados::what()const throw(){
		return "Los datos ya fueron cargados en el sistema";
	}
