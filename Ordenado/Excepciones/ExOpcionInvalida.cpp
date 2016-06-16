#include "ExOpcionInvalida.h"

ExOpcionInvalida::ExOpcionInvalida(){

}

const char* ExOpcionInvalida::what()const throw(){
		return "Opcion inválida. Intente nuevamente.";
}
