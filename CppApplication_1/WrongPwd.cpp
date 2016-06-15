#include "WrongPwd.h"

        virtual const char* WrongPwd::what()const throw(){
		return "Contraseña Incorrecta";
	}