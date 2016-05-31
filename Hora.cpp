#include Hora.h

Hora :: Hora(){
    this->hora=-1;
    this->minuto=-1;
    this->segundo=-1;
}

Hora :: Hora(int h,int m,int s){
    this->hora=h;
    this->minuto=m;
    this->segundo=s;
}

int Hora :: get_hora(){
    return this->hora;
}

int Hora :: get_minuto(){
    return this->minuto;
}

int Hora :: get_segundo(){
    return->segundo;
}

Hora :: ~Hora(){}

