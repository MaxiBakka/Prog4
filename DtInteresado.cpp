#include DtInteresado.h

DtInteresado :: DtInteresado(string n,string a,string ed,string em){
    this->nombre=n;
    this->apellido=a;
    this->edad=ed;
    this->email=em;
}

string DtInteresado :: get_nombre(){
    return this->nombre;
}


string DtInteresado :: get_apellido(){
    return this->apellido;
}


string DtInteresado :: get_edad(){
    return this->edad;
}


string DtInteresado :: get_email(){
    return this->email;
}

DtInteresado :: ~DtInteresado(){}

