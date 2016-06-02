#ifndef Mensaje_h
#define Mensaje_h

#include <string>
#include "DataMensaje.h"

class Mensaje {
private:
    Fecha fecha;
    Hora hora;
    string texto;
public:
    Mensaje(Fecha f,Hora h,string t);
    Fecha getFecha();
    Hora getHora();
    string getTexto();
    DataMensaje getDataMensaje();
    ~Mensaje)();
};


#endif // Mensaje_h
