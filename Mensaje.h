#ifndef Mensaje_h
#define Mensaje_h

#include <string>
#include "DataMensaje.h"
#include "Hora.h"
#include "Fecha.h"

class Mensaje {
private:
    Fecha fecha;
    Hora hora;
    string texto;
public:
    Mensaje(Fecha& f,Hora& h,string& t);
    Fecha& getFecha();
    Hora& getHora();
    string& getTexto();
    
    //setters
    void setTexto(string& texto);
    void setHora(Hora& hora);
    void setFecha(Fecha& fecha);
    
    DataMensaje* getDataMensaje();
    virtual ~Mensaje();
};


#endif // Mensaje_h