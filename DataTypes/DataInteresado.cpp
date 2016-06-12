#include "DataInteresado.h"

DataInteresado::DataInteresado(string& n, string& a, int e, string& correo) {
    this->nombre=n;
    this->apellido=a;
    this->edad=e;
    this->email=correo;
}

string& DataInteresado::getApellido() {
    return this->apellido;
}

int DataInteresado::getEdad() {
    return this->edad;
}

string& DataInteresado::getEmail() {
    return this->email;
}

string& DataInteresado::getNombre() {
    return this->nombre;
}

DataInteresado::~DataInteresado() {
    
}






