#include Administrador.h

Administrador :: Administrador(){
    Usuario();
}

Administrador :: Administrador (string e,string c){
    Usuario(e,c);
}

string Administrador :: get_email(){
    return this->email;
}

string Administrador :: get_contraseña(){
    return this->email;
}

void Administrador :: set_email(string &e){
    this->email=e;
}

void Aministrador :: set_contraseña(string &c){
    this->contraseña=c;
}

Administrador :: ~Administrador(){
}
