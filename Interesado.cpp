#include Interesado.h

Interesado :: Interesado(){
    Usuario();
    this->nombre='';
    this->apellido='':
    this->edad=-1;
}

Interesado :: Interesado(string e,string c,string n,string a,int age){
    Usuario(e,c);
    this->nombre=n;
    this->apellido=a:
    this->edad=age;
}

string Interesado :: get_email(){
    return this->email;
}

string Interesado :: get_contrasenia(){
    return this->contrasenia;
}

void Interesado :: set_email(string &e){
    this->email=e;
}

void Interesado :: set_contrasenia(string &c){
    this->contrasenia=c;
}

string Interesado :: get_nombre(){
    return this->nombre;
}

string Interesado :: get_apellido(){
    return this->apellido;
}

int Interesado :: get_edad(){
    return this->edad;
}

void Interesado :: set_nombre(string &n){
    this->nombre=n;
}

void Interesado :: set_apellido(string &a){
    this->apellido=a;
}

void Interesado :: set_edad(int &age){
    this->edad=e;
}

Interesado :: ~Interesado(){
    ~Usuario();
}

