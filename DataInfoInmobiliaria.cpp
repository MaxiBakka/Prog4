#include DataInfoInmobiliaria.h

DataInfoInmobiliaria :: DataInfoInmobiliaria(string n,string u,string e){
    this->nombre=n;
    this->ubicacion=u;
    this->email=e;
}

string DataInfoInmobiliaria :: get_nombre(){
    return this->nombre;
}

string DataInfoInmobiliaria :: get_ubicacion(){
    return this->ubicacion;
}

string DataInfoInmobiliaria :: get_email(){
    return this->email;
}

DataDepartamento DataInfoInmobiliaria :: get_dtdepartamento(){
    return this->dtdepartamento;
}

DataZona DataInfoInmobiliaria :: get_dtzona(){
    return this->dtzona;
}

DataInfoInmobiliaria :: ~DataInfoInmobiliaria(){}
