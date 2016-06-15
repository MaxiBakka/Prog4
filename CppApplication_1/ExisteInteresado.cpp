#include "ExisteInteresado.h"

ExisteInteresado::ExisteInteresado(){

}

ExisteInteresado::~ExisteInteresado(){
	
}

	virtual const char* ExisteInteresado::what()const throw(){
		return "Interesado ya existente";
	}
