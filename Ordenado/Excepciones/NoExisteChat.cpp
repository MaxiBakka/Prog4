#include "NoExisteChat.h"

NoExisteChat::NoExisteChat(){

}

NoExisteChat::~NoExisteChat(){
	
}

	virtual const char* NoExisteChat::what()const throw(){
		return "No existe chat";
	}
