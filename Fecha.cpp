#include Fecha.h

Fecha :: Fecha(){
    this->dia=0;
    this->mes=0;
    this->anio=0;
}

Fecha :: Fecha(int d,int m,int a){
    this->dia=d;
    this->mes=m;
    this->anio=a;
}

int Fecha :: get_dia(){
    return this->dia;
}

int Fecha :: get_mes(){
    return this->mes;
}

int Fecha :: get_anio(){
    return this->anio;
}

Fecha :: ~Fecha(){}

