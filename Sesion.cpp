#include "Sesion.h"

Sesion* Sesion::instancia=NULL;

Sesion::Sesion() {
    this->usuario=NULL;
}

void Sesion::cerrarSesion() {
    this->usuario=NULL;
}

Usuario* Sesion::getInstancia() {
    if (this->instancia=NULL){
        instancia = new Sesion();
    }
    return this->instancia;
}

Usuario* Sesion::getUsuario() {
    return this->usuario=NULL;
}

void Sesion::iniciarSesion(Usuario*& user) {
    this->usuario=user;
}

Sesion::~Sesion() {
    
}




