#include "InmobiliariaNotFound.h"

InmobiliariNotFound::InmobiliariNotFound(){

}

InmobiliariNotFound::~InmobiliariNotFound(){

}

virtual const char* InmobiliariNotFound::what()const throw(){
		return "Inmobiliaria no encontrada";
}
