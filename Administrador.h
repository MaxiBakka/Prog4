#ifndef Administrador_h
#define Administrador_h

#include Usuario.h

class Administrador : public Usuario:
    private:
    public:
        Administrador();
        Administrador(string e,string c);
        virtual string get_email();
        virtual string get_contraseņa();
        virtual void set_email(string &e);
        virtual void set_contraseņa(string &c);
        virtual ~Administrador;


#endif // Administrador_h
