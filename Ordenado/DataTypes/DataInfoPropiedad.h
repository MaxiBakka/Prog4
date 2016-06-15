#ifndef DataInfoPropiedad_h
#define DataInfoPropiedad_h

#include <string>

using namespace std;

class DataInfoPropiedad{
    private:
        int codigo;
        string direccion;
        int cantMensaje;
    public:
        DataInfoPropiedad(int c,string d,int cmjs);
        int get_codigo();
        string get_direccion();
        int get_cantMensajes();
        ~DataInfoPropiedad();
};

#endif // DataInfoPropiedad_h
