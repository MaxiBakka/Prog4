#ifndef Fecha_h
#define Fecha_h

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha();
    Fecha(int d,int m,int a);
    int get_dia();
    int get_mes();
    int get_anio();
    ~Fecha;
};



#endif // Fecha_h
