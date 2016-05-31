#ifndef Hora_h
#define Hora_h

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
    ~Hora;
};





#endif // Hora_h
