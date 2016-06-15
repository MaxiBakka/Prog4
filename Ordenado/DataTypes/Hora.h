#ifndef Hora_h
#define Hora_h

#include <iostream>

using namespace std;

class Hora{
private:
    int hora;
    int minuto;
    int segundo;
public:
    Hora();

    Hora(int h,int m,int s);

    int get_hora();
    int get_minuto();
    int get_segundo();
    //sobrecarga de operadores
    Hora& operator =(const Hora h);
    //destructor
    ~Hora();
};

ostream & operator<<(ostream& o,Hora& h);

#endif // Hora_h
