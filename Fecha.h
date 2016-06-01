#ifndef Fecha_h
#define Fecha_h

#include <iostream>

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:

    Fecha(int d,int m,int a);
    int get_dia();
    int get_mes();
    int get_anio();

    //sobrecarga de operadores
    Fecha& operator =(const Fecha f);

    ~Fecha();
};

ostream& operator<<(ostream& o,  Fecha& f);

#endif // Fecha_h
