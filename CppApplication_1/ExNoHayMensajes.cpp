#include "ExNoHayMensajes.h"

ExNoHayMensajes::ExNoHayMensajes(){

}

ExNoHayMensajes::~ExNoHayMensajes(){
	
}

	virtual const char* ExNoHayMensajes::what()const throw(){
		return "No hay mensajes";
	}
