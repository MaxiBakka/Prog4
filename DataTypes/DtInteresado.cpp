#include "DtInteresado.h"

using namespace std;

DtInteresado::DtInteresado(string& n, string& a, int e, string& correo) {
    this->nombre=n;
    this->apellido=a;
    this->edad=e;
    this->email=correo;
}

string& DtInteresado::get_Apellido() {
    return this->apellido;
}

int DtInteresado::get_Edad() {
    return this->edad;
}

string& DtInteresado::get_Email() {
    return this->email;
}

string& DtInteresado::get_Nombre() {
    return this->nombre;
}

DtInteresado::~DtInteresado() {

}


ostream& operator<<(ostream& o, const DtInteresado& di){


}