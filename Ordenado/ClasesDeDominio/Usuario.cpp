#include "Usuario.h"

Usuario::Usuario() {
    this->email='';
    this->contrasenia='';   
}

Usuario::Usuario(string& e, string& c) {
    this->contrasenia=c;
    this->email=e;
}

string& Usuario::get_contrasenia() {
    return this->contrasenia;
}

string& Usuario::get_email() {
    return this->email;
}

void Usuario::set_contrasenia(string& c) {
    this->contrasenia=c;
}

Usuario::~Usuario() {

}





