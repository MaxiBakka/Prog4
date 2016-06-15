#ifndef USUARIO_H
#define	USUARIO_H

#include<string>

using namespace std;

class Usuario{
private:
    string email;
    string contrasenia;
public:
    Usuario();
    Usuario(string& e,string& c);
    virtual string& get_email();
    virtual string& get_contrasenia();
    virtual void set_contrasenia(string &c);
    virtual ~Usuario();
};

#endif	/* USUARIO_H */

