#include "ExNoHayMensajes.h"

ExNoHayMensajes::ExNoHayMensajes(){

}

const char* ExNoHayMensajes::what()const throw(){
		return "No hay mensajes";
	}
