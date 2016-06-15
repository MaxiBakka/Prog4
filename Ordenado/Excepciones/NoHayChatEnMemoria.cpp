#include "NoHayChatEnMemoria.h"

NoHayChatEnMemoria::NoHayChatEnMemoria(){

}

NoHayChatEnMemoria::~NoHayChatEnMemoria(){
  
}

        virtual const char* NoHayChatEnMemoria::what()const throw(){
		return "No hay chat en memoria";
	}
