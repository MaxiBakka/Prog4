#include "Sesion.h"

Sesion* Sesion::instancia=NULL;

Sesion::Sesion() {
    this->usuario=NULL;
}

void Sesion::cerrarSesion() {
    this->usuario=NULL;
}

Sesion* Sesion::getInstancia() {
    if (instancia=NULL){
        instancia = new Sesion();
    }
    return instancia;
}

Usuario* Sesion::getUsuario() {
    return this->usuario;
}

void Sesion::iniciarSesion(Usuario*& user) {
    this->usuario=user;
}

Sesion::~Sesion() {

}
