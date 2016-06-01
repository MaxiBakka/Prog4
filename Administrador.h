#ifndef Administrador_h
#define Administrador_h

#include "Usuario.h"

class Administrador : public Usuario{
    public:
        Administrador();
        Administrador(string& e,string& c);
        virtual ~Administrador();
};


#endif // Administrador_h
