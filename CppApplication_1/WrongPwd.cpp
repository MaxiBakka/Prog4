#include "WrongPwd.h"

WrongPwd::WrongPwd(){

}

WrongPwd::~WrongPwd(){
  
}

        virtual const char* WrongPwd::what()const throw(){
		return "Contraseña Incorrecta";
	}
