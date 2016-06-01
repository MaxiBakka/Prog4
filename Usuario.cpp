#include Usuario.h

Usuario :: Usuario(){
    this->email='';
    this->contrasenia='';
}

Usuario :: Usuario(string& e,string& c){
    this->email=e;
    this->contrasenia=c;
}

void Usuario:: set_contrasenia(string &c){
    contrasenia=c;
}

string & Usuario:: get_email(){
    return email;
}

string & Usuario:: get_contrasenia(){
    
    return contrasenia;
}

Usuario::~Usuario(){
    
}
