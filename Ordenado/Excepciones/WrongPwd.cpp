#include "WrongPwd.h"

WrongPwd::WrongPwd(){

}

WrongPwd::~WrongPwd(){

}

const char* WrongPwd::what()const throw(){
		return "Contraseña Incorrecta";
}
