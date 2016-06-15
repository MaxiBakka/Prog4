#include "NoHayConversaciones.h"

NoHayConversaciones::NoHayConversaciones(){

}

NoHayConversaciones::~NoHayConversaciones(){
	
}

	virtual const char* NoHayConversaciones::what()const throw(){
		return "No hay conversaciones";
	}
