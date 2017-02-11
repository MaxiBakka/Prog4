#ifndef DataMensaje_h
#define DataMensaje_h

#include <string>
#include <iostream>

#include "Hora.h"
#include "Fecha.h"

using namespace std;

class DataMensaje{
private:
    Fecha fecha;
    Hora hora;
    string texto;
public:
    //constructor
    DataMensaje(Fecha& f,Hora& h,string t);
    //getters
    Fecha& get_fecha();
    Hora& get_hora();
    const string& get_texto();
    //destructor
    ~DataMensaje();

};

oustream& operator <<(ostream &output,DataMensaje& dm);

#endif // DataMensaje_h
