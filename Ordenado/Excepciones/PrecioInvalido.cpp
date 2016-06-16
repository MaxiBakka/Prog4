#include "PrecioInvalido.h"

PrecioInvalido::PrecioInvalido(){

}

PrecioInvalido::~PrecioInvalido(){

}

const char* PrecioInvalido::what()const throw(){
		return "El precio es invalido";
}
