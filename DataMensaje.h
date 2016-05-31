#ifndef DataMensaje_h
#define DataMensaje_h

#include <string>
#include Hora.h
#include Fecha.h

using namespace std;

class DataMensaje{
private:
    Fecha *fecha;
    Hora *hora;
    string texto;
public:
    DataMensaje();
    DataMensaje(Fecha f,Hora h,string t);
    Fecha get_fecha();
    Hora get_hora();
    string get_texto();
    void set_fecha(Fecha *&f);
    void set_hora(Hora *&h);
    void set_texto(string &t);
    ~DataMensaje;

};



#endif // DataMensaje_h
