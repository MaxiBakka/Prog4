
Edificio :: Edificio(){
    this->nombre='';
    this->cantPisos=-1;
    this->gastosComunes=-1;
}

Edificio :: Edificio(string n,int cp,float gc){
    this->nombre=n;
    this->cantPisos=cp;
    this->gastosComunes=gc;
}

}

}

}

}

DataEdificio Edificio :: getDataEdificio(){
    return DataEdificio(this->nombre,this->cantPisos,this->gastosComunes);
}

Edificio :: ~Edificio(){}

