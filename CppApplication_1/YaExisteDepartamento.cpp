#include "YaExisteDepartamento.h"

YaExisteDepartamento::YaExisteDepartamento(){

}

YaExisteDepartamento::~YaExisteDepartamento(){
	
}

	virtual const char* YaExisteDepartamento::what()const throw(){
		return "El departamento ya existe";
	}
