#ifndef Usuario_h
#define Usuario_h

#include <string>

using namespace std;

class Usuario {
    private:
        string email;
        string contraseña;
    public:
        Usuario();
        Usuario(string e,string c);
        virtual string get_email();
        virtual string get_contrasenia();
        virtual void set_email(string &e);
        virtual void set_contrasenia(string &c);
        virtual ~Usuario;
};



#endif // Usuario_h
