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

string Administrador :: get_contraseņa(){
    return this->email;
}

void Administrador :: set_email(string &e){
    this->email=e;
}

void Aministrador :: set_contraseņa(string &c){
    this->contraseņa=c;
}

Administrador :: ~Administrador(){
}
