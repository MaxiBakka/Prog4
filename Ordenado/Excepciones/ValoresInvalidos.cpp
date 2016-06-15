#include "ValoresInvalidos.h"

ValoresInvalidos::ValoresInvalidos(){

}

ValoresInvalidos::~ValoresInvalidos(){
	
}

	virtual const char* ValoresInvalidos::what()const throw(){
		return "Valores invalidos";
	}
