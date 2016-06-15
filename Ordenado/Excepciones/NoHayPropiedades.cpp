#include "NoHayPropiedades.h"

NoHayPropiedades::NoHayPropiedades(){

}

NoHayPropiedades::~NoHayPropiedades(){
	
}

	virtual const char* NoHayPropiedades::what()const throw(){
		return "No hay propiedades";
	}
